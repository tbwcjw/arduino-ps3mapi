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

    ps3.notify.sendNotification("Hello from Arduino!", 
    PS3Mapi::Notify::Icon::INFO, 
    PS3Mapi::Notify::BuzzerMode::SINGLE);
    
    delay(1000);

    ps3.notify.buzzer(PS3Mapi::Notify::BuzzerMode::TRIPLE);
    ps3.notify.led(PS3Mapi::Notify::LEDColor::YELLOW, 
    PS3Mapi::Notify::LEDMode::FAST_BLINK);
}

void loop() {
    // Your code here
}