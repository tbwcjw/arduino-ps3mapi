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

    String procID = ps3.process.getCurrentProcID();
    String procName = ps3.process.getProcName(procID);
    
    Serial.printf("Current Process: (%s): %s", procID.c_str(), procName.c_str());

    std::vector<String> allProcs = ps3.process.getAllProcID();
    Serial.println("\nAll Processes:");
    for (size_t i = 0; i < allProcs.size(); i++) {
        Serial.println(String(i) + ": " + allProcs[i].c_str());
    }
}

void loop() {
    // Your code here
}