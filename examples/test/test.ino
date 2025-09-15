#include <WiFi.h>
#include <ps3mapi.h>

const char* ssid = "2Bloomdale 2.4GHz";
const char* password = "tucker48";
PS3Mapi ps3("10.0.0.225");

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected!");

    ps3.notify.sendNotification("Hello from Arduino!", PS3Mapi::Notify::Icon::INFO, PS3Mapi::Notify::BuzzerMode::SINGLE);
    delay(1000); 
    ps3.notify.buzzer(PS3Mapi::Notify::BuzzerMode::DOUBLE);
    delay(1000); 
    ps3.notify.led(PS3Mapi::Notify::LEDColor::GREEN, PS3Mapi::Notify::LEDMode::OFF);
    String pid = ps3.process.getCurrentProcID();
    Serial.println("Current PID: " + pid);
    String procName = ps3.process.getProcName(pid);
    Serial.println("Current PID Name:" + procName);
    std::vector<String> buttons = {"up", "down", "psbtn"};
    ps3.pad.pushButtons(buttons, 1.0f);
}

void loop() {
    // Your code here
}