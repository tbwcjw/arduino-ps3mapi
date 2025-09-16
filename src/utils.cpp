#include "utils.h"
/**
 * @brief extract value of "response" key from JSON.
 *
 * @param jsonPayload The JSON string containing the response.
 * @return String value as a String. returns an empty string if the key is not found
 *         or if the value cannot be extracted. type agnostic.
 */
String extractResponse(const String &jsonPayload) {
    int keyIndex = jsonPayload.indexOf("\"response\"");
    if (keyIndex < 0) return "";

    int colonIndex = jsonPayload.indexOf(":", keyIndex);
    if (colonIndex < 0) return "";

    int valueStart = colonIndex + 1;
    while (valueStart < jsonPayload.length() && 
           (jsonPayload[valueStart] == ' ' || jsonPayload[valueStart] == '\t' || 
            jsonPayload[valueStart] == '\n' || jsonPayload[valueStart] == '\r')) {
        valueStart++;
    }

    if (jsonPayload[valueStart] == '\"') {
        int endQuote = jsonPayload.indexOf('\"', valueStart + 1);
        if (endQuote < 0) return "";
        return String(jsonPayload.substring(valueStart + 1, endQuote));
    }

    int valueEnd = valueStart;
    while (valueEnd < jsonPayload.length() && 
           jsonPayload[valueEnd] != ',' && jsonPayload[valueEnd] != '}' &&
           !isspace(jsonPayload[valueEnd])) {
        valueEnd++;
    }

    return String(jsonPayload.substring(valueStart, valueEnd));
}

/**
 * @brief parse string representation of a tuple into a std::pair.
 *
 * if parsing fails, return [0,0].
 *
 * @param tupleString string containing the tuple.
 * @return std::pair<int,int> parsed tuple as a pair of ints.
 */
std::pair<int,int> parseTuple(const String &tupleString) { 
    std::pair<int,int> value = {0, 0};
    
    int start = tupleString.indexOf("["); 
    int end = tupleString.indexOf("]"); 
    
    if (start >= 0 && end > start) { 
        String numbers = tupleString.substring(start + 1, end); 
        int commaIndex = numbers.indexOf(","); 
        
        if (commaIndex >= 0) { 
            String first = numbers.substring(0, commaIndex); 
            String second = numbers.substring(commaIndex + 1); 
            value.first = first.toInt(); 
            value.second = second.toInt(); 
            } 
        } 
    return value; 
}
/**
 * @brief econde string for URL by replacing unsafe characters.
 *
 * @param str input string to encode.
 * @return String encoded string.
 */
String urlEncode(const String &str) {
    String encoded = "";
    char buf[4];
    for (size_t i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded += c; 
        } else if (c == ' ') {
            encoded += "%20"; 
        } else {
            sprintf(buf, "%%%02X", (unsigned char)c);
            encoded += buf;
        }
    }
    return encoded;
}

/**
 * @brief convert json array string into a vector of Strings.
 *
 * @param array string containing the array.
 * @return std::vector<String> vector with elements of the array. empty vector if invalid.
 */
std::vector<String> arrayToList(const String& array) {
    std::vector<String> result;
    String s = array;
    s.trim();

    int start = s.indexOf('[');
    int end = s.indexOf(']', start);
    if (start < 0 || end < 0 || end <= start) return result; 

    s = s.substring(start + 1, end); 
    s.trim();

    int prevIndex = 0;
    int commaIndex = s.indexOf(',', prevIndex);

    while (commaIndex >= 0) {
        String token = s.substring(prevIndex, commaIndex);
        token.trim();
        if (token.length() > 0) result.push_back(token);
        prevIndex = commaIndex + 1;
        commaIndex = s.indexOf(',', prevIndex);
    }

    String lastToken = s.substring(prevIndex);
    lastToken.trim();
    if (lastToken.length() > 0) result.push_back(lastToken);

    return result;
}
