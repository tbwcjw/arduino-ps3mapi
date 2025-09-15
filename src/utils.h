#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h> 

String extractResponse(const String &jsonPayload);

String urlEncode(const String &str);

#endif