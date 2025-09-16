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

    std::vector<String> buttons = {"up", "down"}; 
    ps3.pad.holdButtons(buttons, 2000.0f); //automatically releases after 2 seconds, no value or -1 releases immediately
    //ps3.pad.releaseButtons();
    ps3.pad.pushButtons({"left"}); //single button input
    ps3.pad.off(); //turn off virtual controlller
}

void loop() {
    // Your code here
}