#include "ps3mapi.h"
#include "Arduino.h"

PS3Mapi::PS3Mapi(const String& ip) : ip(ip), 
system(this), 
notify(this), 
process(this), 
memory(this), 
module(this), 
thread(this), 
registry(this), 
level(this), 
file(this),
pad(this) {}

PS3Mapi::System::System(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::Notify::Notify(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::Process::Process(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::Memory::Memory(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::Module::Module(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::Thread::Thread(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::Registry::Registry(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::Level::Level(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::File::File(PS3Mapi* wm) : ps3mapi(wm) {}
PS3Mapi::Pad::Pad(PS3Mapi* wm) : ps3mapi(wm) {}

// - System -
String PS3Mapi::System::getCoreVersion() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "CORE GETVERSION");
}

String PS3Mapi::System::getServerVersion() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "SERVER GETVERSION");
}

String PS3Mapi::System::getCoreMinVersion() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "CORE GETMINVERSION");
}

String PS3Mapi::System::getServerMinVersion() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "SERVER GETMINVERSION");
}

String PS3Mapi::System::getFirmwareVersion() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 GETFWVERSION");
}

String PS3Mapi::System::getFirmwareMinVersion() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 GETFWMINVERSION");
}
String PS3Mapi::System::getFirmwareType() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 GETFWTYPE");
}

String PS3Mapi::System::getSysInfo(const int& id) {
    String cmd = "PS3 GETSYSINFO " + String(id);
    return ps3mapi->_sendCommand("ps3mapi.ps3", cmd);
}

String PS3Mapi::System::getBdInfo(const String& dump_file) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 GETBDINFO " + dump_file);
}

String PS3Mapi::System::getNoBdInfo() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 GETNOBDINFO");
}

String PS3Mapi::System::getClockInfo() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 GETCLOCKINFO");
}

std::pair<int,int> PS3Mapi::System::getTemp() {
    return ps3mapi->_sendCommandTuple("ps3mapi.ps3", "PS3 GETTEMP");
}

String PS3Mapi::System::checkSyscall(const int& sc_num) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 CHECKSYSCALL " + String(sc_num));
}

bool PS3Mapi::System::pCheckSyscall8() {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 PCHECKSYSCALL8");
}
std::pair<int,int> PS3Mapi::System::getRsxClock() {
    return ps3mapi->_sendCommandTuple("ps3mapi.ps3", "PS3 GETRSXCLOCK");
}
String PS3Mapi::System::getIdps() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 GETIDPS");
}
bool PS3Mapi::System::setIdps(const String& part1, const String& part2) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 SETIDPS " + part1 + " " + part2);
}
String PS3Mapi::System::getPsid() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PS3 GETPSID");
}
bool PS3Mapi::System::setPsid(const String& part1, const String& part2) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 SETPSID " + part1 + " " + part2);
}
bool PS3Mapi::System::setGpuClock(const int& mhz) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 SETGPUCLOCK " + String(mhz));
}
bool PS3Mapi::System::setVRamClock(const int& mhz) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 SETVRAMCLOCK " + String(mhz));
}
bool PS3Mapi::System::delHistory() {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 DELHISTORY");
}
bool PS3Mapi::System::delHistoryF() {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 DELHISTORY+F");
}
bool PS3Mapi::System::removeHook() {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 REMOVEHOOK");
}

bool PS3Mapi::System::disableSyscall(const int& sc_num) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 DISABLESYSCALL " + String(sc_num));
}

bool PS3Mapi::System::pDisableSyscall8(const int& mode) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 PDISABLESYSCALL8 " + String(mode));
}

bool PS3Mapi::System::sendReboot() {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 REBOOT");
}

bool PS3Mapi::System::sendSoftReboot() {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 SOFTREBOOT");
}

bool PS3Mapi::System::sendHardReboot() {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 HARDREBOOT");
}

bool PS3Mapi::System::sendShutdown() {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "PS3 SHUTDOWN");
}
// - Notify - 
bool PS3Mapi::Notify::sendNotification(const String& message, const Icon& icon, const BuzzerMode& snd) {
    String cmd = message + "&icon=" + String(icon) + "&snd=" + String(snd);
    return ps3mapi->_sendCommandBool("popup.ps3", cmd);
}
bool PS3Mapi::Notify::buzzer(const BuzzerMode& mode) {
    String cmd = "PS3 BUZZER" + String(mode);
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", cmd);
}
bool PS3Mapi::Notify::led(const LEDColor& color, const LEDMode& mode) {
    String cmd = "PS3 LED " + String(color) + " " + String(mode);
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", cmd);
}
// - Process -
String PS3Mapi::Process::getCurrentProcID() {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PROCESS GETCURRENTPID");
}

String PS3Mapi::Process::getProcName(const String& pid) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PROCESS GETNAME " + pid);
}

std::vector<String> PS3Mapi::Process::getAllProcID() {
    return ps3mapi->_sendCommandArray("ps3mapi.ps3", "PROCESS GETALLPID");
}
// - Memory -
String PS3Mapi::Memory::getMemory(const String& pid, const String& offset, const int& size) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "MEMORY GET " + pid + " " + offset + " " + String(size));
}

bool PS3Mapi::Memory::setMemory(const String& pid, const String& address, const String& value) {
    return ps3mapi->_sendCommandBool("setmem.ps3mapi", "proc=" + pid + "&addr=" + address + "&value=" + value);
}

String PS3Mapi::Memory::payload(const String& pid, const String& payload_path) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "MEMORY PAYLOAD " + pid + " " + payload_path);
}

bool PS3Mapi::Memory::unloadPayload(const String& pid) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "MEMORY PAYLOAD " + pid + " unload");
}

bool PS3Mapi::Memory::pageAllocate(const String& pid, const int& size, const int& page_size, const String& flags, const bool& is_executable) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "MEMORY PAGEALLOCATE " + pid + " " + String(size) + " " + String(page_size) + " " + String(flags) + " " + String(is_executable));
}

bool PS3Mapi::Memory::pageFree(const String& pid, const String& flags, const String& page_table_0, const String& page_table_1) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "MEMORY PAGEFREE " + pid + " " + flags + " " + page_table_0 + " " + page_table_1);
}
// - Module -
String PS3Mapi::Module::getName(const String& pid, const String& prx_id) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "MODULE GETNAME " + pid + " " + prx_id);
}
String PS3Mapi::Module::getFileName(const String& pid, const String& prx_id) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "MODULE GETFILENAME " + pid + " " + prx_id);
}
bool PS3Mapi::Module::unload(const String& pid, const String& prx_id) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "MODULE UNLOAD " + pid + " " + prx_id);
}
bool PS3Mapi::Module::load(const String& pid, const String& prx_path) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "MODULE LOAD " + pid + " " + prx_path);
}
bool PS3Mapi::Module::loadVshPlugs(const int& slot, const String& prx_path) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "MODULE LOADVSHPLUGS " + String(slot) + " " + prx_path);
}
bool PS3Mapi::Module::unloadVshPlugs(const int& slot) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "MODULE UNLOADVSHPLUGS " + String(slot));
}
String PS3Mapi::Module::getVshPlugInfo(const int& slot) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "MODULE GETVSHPLUGINFO " + String(slot));
}
String PS3Mapi::Module::getSegments(const int& slot, const String& prx_id) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "MODULE GETSEGENTS " + String(slot) + " " + prx_id);
}
// - Thread - 
bool PS3Mapi::Thread::create(const String& pid, const String& page_table_0, const String& toc, const String& arg, const String& prio, const String& stack_size, const String& name) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "THREAD CREATE " + pid + " " + page_table_0 + " " + toc + " " + arg + " " + prio + " " + stack_size + " " + name);
}
// - Registry -
String PS3Mapi::Registry::get(const String& reg_key) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "REGISTRY GET " + reg_key);
}
bool PS3Mapi::Registry::set(const String& reg_key, const String& value) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "REGISTRY SET " + reg_key + " " + value);
}
// - Level -
String PS3Mapi::Level::peekLv1(const String& address) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PEEKLV1 " + address);
}
String PS3Mapi::Level::peekLv2(const String& address) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "PEEKLV2 " + address);
}
bool PS3Mapi::Level::pokeLv1(const String& address, const String& value) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "POKELV1 " + address);
}
bool PS3Mapi::Level::pokeLv2(const String& address, const String& value) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "POKELV2 " + address);
}
// - File -
bool PS3Mapi::File::exists(const String& file_path) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "FILE EXISTS " + file_path);
}

bool PS3Mapi::File::isDir(const String& file_path) {
    return ps3mapi->_sendCommandBool("ps3mapi.ps3", "FILE ISDIR " + file_path);
}
String PS3Mapi::File::size(const String& file_path) {
    return ps3mapi->_sendCommand("ps3mapi.ps3", "FILE SIZE " + file_path);
}
// - Pad -
void PS3Mapi::Pad::pushButtons(const std::vector<String>& buttons, float delay_float) {
    String result = "";

    for (size_t i = 0; i < buttons.size(); ++i) {
        ps3mapi->_sendCommandBool("pad.ps3", buttons[i]);
        if (delay_float > 0.0f) {
            delay(delay_float * 1000);
        }
    }
}
bool PS3Mapi::Pad::acceptButton() {
    return ps3mapi->_sendCommandBool("pad.ps3", "accept");
}
bool PS3Mapi::Pad::cancelButton() {
    return ps3mapi->_sendCommandBool("pad.ps3", "cancel");
}
bool PS3Mapi::Pad::off() {
    return ps3mapi->_sendCommandBool("pad.ps3", "off");
}

String PS3Mapi::_sendCommand(const String& apiArg, const String& route) {
    HTTPClient http;
    String url = "http://" + ip + "/" + apiArg + "?" + urlEncode(route);
    http.begin(url);

    int httpResponseCode = http.GET();
    String value = "";
    if (httpResponseCode > 0) {
        value = extractResponse(http.getString());
    } else Serial.println("Failed to connect to the specified IP. Is the IP correct, and is the system running?");
    http.end();
    return value;
}

std::vector<String> PS3Mapi::_sendCommandArray(const String& apiArg, const String& route) {
    HTTPClient http;
    String url = "http://" + ip + "/" + apiArg + "?" + urlEncode(route);
    http.begin(url);

    int httpResponseCode = http.GET();
    std::vector<String> result;
    if (httpResponseCode < 0) Serial.println("Failed to connect to the specified IP. Is the IP correct, and is the system running?");
    result = arrayToList(http.getString());
    http.end();
    return result;
}

bool PS3Mapi::_sendCommandBool(const String& apiArg, const String& route) {
    HTTPClient http;
    String url = "http://" + ip + "/" + apiArg;
    if (route.length() > 0) url += "?" + urlEncode(route);
    Serial.println("URL " + url);

    http.begin(url);
    int httpResponseCode = http.GET();
    if(httpResponseCode < 0) Serial.println("Failed to connect to the specified IP. Is the IP correct, and is the system running?");

    String respStr = extractResponse(http.getString());
    http.end();

    if (respStr == "0" || respStr == "false") return false;
    if (respStr == "1" || respStr == "true") return true;

    
    return httpResponseCode > 0; //fallback to simple http response code check
}

std::pair<int,int> PS3Mapi::_sendCommandTuple(const String& apiArg, const String& route) {
    HTTPClient http;
    String url = "http://" + ip + "/" + apiArg + "?" + urlEncode(route);
    http.begin(url);

    int httpResponseCode = http.GET();
    if (httpResponseCode < 0) Serial.println("Failed to connect to the specified IP. Is the IP correct, and is the system running?");

    std::pair<int,int> result = parseTuple(http.getString());

    http.end();
    return result;
}

