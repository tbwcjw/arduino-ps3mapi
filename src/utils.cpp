#include "utils.h"

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
