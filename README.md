<h1>PS3Mapi Arduino Library</h1>
<p>An Arduino library to monitor & control homebrewed PS3s running webMAN using PS3MAPI.</p>
<p>Documentation <a href='https://tbwcjw.github.io/arduino-ps3mapi/'>here</a>.
<h2>Installation</h2>
<ul>
    <li>Clone this repository.</li>
    <li>Copy the <code>ps3mapi</code> folder into your Arduino <code>libraries</code> folder.
    <br>OR<br>
    Go to <code>Sketch > Include Library > Add .zip Library...</code> in the Arduino IDE.</li>
    <li>Go to <code>File > Examples > ps3mapi</code> to view the example sketches.</li>
</ul>
<h2>Basic usage</h2>
<p>Basic usage example, connecting to WiFi, the PS3 and sending a notification message "Hello from Arduino!" with the INFO icon and a single buzz, then changing the color of the Power LED to yellow, with a fast blink.</p>

```cpp
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

    ps3.notify.led(PS3Mapi::Notify::LEDColor::GREEN, 
    PS3Mapi::Notify::LEDMode::FAST_BLINK);

    ps3.notify.sendSysNotification(PS3Mapi::Notify::InfoModes::HDD0_FREE);
}
```
<h3>Buzzer Modes</h3>

```cpp
enum BuzzerMode {
    NONE = 0,
    SINGLE = 1,
    DOUBLE = 2,
    TRIPLE = 3,
    CANCEL = 4,
    TROPHY = 5,
    OK = 8,
    ERROR = 9
};
```
<h3>Icons</h3>

```cpp
enum Icon {
    INFO = 0, FRIENDS = 1, HEADSET = 2, EXCLAIMATION = 3, KEYBOARD = 4,
    NETWORK = 5, REFRESH = 6, WRONGWAY = 7, TOOLBOX = 8, BRONZE = 9,
    SILVER = 10, GOLD = 11, PLATINUM = 12, HAND = 13, PEN = 14,
    CURSOR = 15, FIST = 16, PLAY = 17, PSN1 = 18, PSPLUS = 19,
    SIGNIN = 20, NEW = 21, TICK = 22, RED_EXCLAIMATION = 23,
    WRENCH = 24, STAR_TROPHY = 25, PSSTORE = 26, FOLDER = 27,
    GUEST = 28, LOADING = 29, MUSIC = 30, CAMERA = 31, 
    VIDEO = 32, CONTROLLER = 33, LOCK = 34, REDX = 35,
    UKNOWN1 = 36, SEND = 37, SPEECHBUBBLE = 38, CIRCLE = 39,
    PROFILE = 40, BRDISC = 41, CDDISC = 42, BLUEDISC = 43,
    BLCKDISC = 44, MOVIEDISC = 45, DVDDISC = 46, QUESTIONDISC = 47,
    PSVITA = 48, CLOCK = 49, REMOTEPLAY = 50
};
```
<h3>LED Colors</h3>

```cpp
enum LEDColor {
    RED = 0,
    GREEN = 1,
    YELLOW = 2
};
```
<h3>LED Modes</h3>

```cpp
enum LEDMode {
    OFF = 0,
    ON = 1,
    FAST_BLINK = 2,
    SLOW_BLINK = 3,
    ALT1_BLINK = 4,
    ALT2_BLINK = 5,
    ALT3_BLINK = 6
};
```
<h3> System Information Modes</h3>

```cpp
enum InfoModes {
    HDD0_FREE = 0, USB0_FREE = 1, USB1_FREE = 2, USB2_FREE = 3,
    USB3_FREE = 4, NTFS0_FREE = 5, MEM_FREE = 6, MEM_USAGE = 7,
    SYSCALL = 8, FAN_TEMP = 9, FAN_MODE = 10, UPTIME = 11,
    PLAYTIME = 12, RUNTIME = 13, DATETIME = 14, GAME_ID = 15,
    PROC_ID = 16, PSID = 17, IDPSLV2 = 18, IDPSEID0 = 19,
    FW_VERS = 20, MAC_ADDR = 21, IP_ADDR = 22, HOME_DIR = 23,
    WM_VERS = 24, BD_VENDOR = 25, RSX_CORE_CLOCK = 26, 
    RSX_VRAM_CLOCk = 27

};
```
<h2>Pad Control Usage</h2>
<p>A basic usage example showing the virtual controller functionality. Remember to turn the controller off, as it acts as player 2, 3 or 4.</p>

```cpp
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

    std::vector<String> buttons = {"up", "down", "left", "right"}; // list of buttons to push
    ps3.pad.pushButtons(buttons, 0.5f); //push each button with (optional) delay in seconds
    ps3.pad.off(); //turn off the virtual controller.
}
```
<h3>Pad buttons</h3>

```
up, down, left, right, cross, circle, square, triangle, r1, r2, l1, l2, psbtn, select, start, hold, release
analogL_up, analogL_down, analogL_left, analogL_right
analogR_up, analogR_down, analogR_left, analogR_right
```
<h2>License</h2>
This software is licensed under the <a href='LICENSE'>MIT License</a>.