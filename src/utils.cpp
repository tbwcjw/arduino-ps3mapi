#include "utils.h"

String extractResponse(const String &jsonPayload) {
    int start = jsonPayload.indexOf("\"response\":"); 
    if (start < 0) return "";

    start = jsonPayload.indexOf("\"", start + 11);
    if (start < 0) return ""; 

    int end = jsonPayload.indexOf("\"", start + 1);
    if (end < 0) return ""; 

    return jsonPayload.substring(start + 1, end);
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

