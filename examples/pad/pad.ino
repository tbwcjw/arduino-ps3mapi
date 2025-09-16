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

    std::vector<String> buttons = {"up", "down", "left", "right"}; 
    ps3.pad.pushButtons(buttons, 0.5f); 
    ps3.pad.off();
}

void loop() {
    // Your code here
}