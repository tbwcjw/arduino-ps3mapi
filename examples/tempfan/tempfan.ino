/* 
 * getFanSpeed(), getFanMode() use endpoints that are not currently 
 * implemented in the main release of webMAN. A custom sprx is required.
 * Hopefully it will be in the mainline soon. The build can be found here:
 * https://github.com/aldostools/webMAN-MOD/issues/1283
 */
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
}

int fanSpeed;
std::pair<int,int> temps;
int cpu;
int rsx;

void loop() {
    fanSpeed = ps3.system.getFanSpeed();
    temps = ps3.system.getTemp();
    cpu = temps.first;
    rsx = temps.second;

    Serial.print("Fan_Speed:");
    Serial.print(fanSpeed);
    Serial.print(",");
    Serial.print("CPU_Temp:");
    Serial.print(cpu);
    Serial.print(",");
    Serial.print("RSX_Temp:");
    Serial.print(rsx);
    Serial.println();

    delay(3000);
}