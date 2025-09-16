#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h> 

String extractResponse(const String &jsonPayload);
String urlEncode(const String &str);
std::pair<int,int> parseTuple(const String &tupleString);
std::vector<String> arrayToList(const String& array);

#endif