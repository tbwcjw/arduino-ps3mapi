#include <WiFi.h>
#include <ps3mapi.h>

const char* ssid = "ssid";
const char* password = "pass";
PS3Mapi ps3("x.x.x.x");

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected!");

    String firmwareVersion = ps3.system.getFirmwareVersion();
    String firmwareMinVersion = ps3.system.getFirmwareMinVersion();
    String firmwareType = ps3.system.getFirmwareType();
    std::pair<int,int> temps = ps3.system.getTemp();

    Serial.printf("Firmware Version: %s\n", firmwareVersion);
    Serial.printf("Firmware Min Version: %s\n", firmwareMinVersion);
    Serial.printf("Firmware Type: %s\n", firmwareType);
    Serial.printf("CELL Temp: %d, RSX Temp: %d", temps.first, temps.second);
}

void loop() {
    // Your code here
}