/*

  ps3mapi.h - Library for controlling homebrewed PS3s running webMAN via PS3MAPI. 

  Created by tbwcjw.

  Released under the MIT License.

*/
#ifndef PS3MAPI_H
#define PS3MAPI_H

#pragma once
#include <HTTPClient.h>
#include "utils.h"
#include <utility>
#include <vector>

#define HTTP_RESPONSE_ERROR(x)  Serial.printf("\n(%d) Failed to connect to the specified IP. Is the IP correct, and is the system running?\n", x)
#define HTTP_RESPONSE_LENGTH_ERROR Serial.println("A null/empty response was received.")
#define UNEXPECTED_SIZE_ERROR(x,y) Serial.printf("\nElement has %d size, expected %d. This is probably a library problem. Report it via github.\n", x, y)
class PS3Mapi {
public:
    PS3Mapi(const String& ip, const bool& displayErrors = false);
    class System {
    public:
        System(PS3Mapi* wm);
        String getCoreVersion();
        String getServerVersion();
        String getCoreMinVersion();
        String getServerMinVersion();
        String getFirmwareMinVersion();
        String getFirmwareVersion();
        String getFirmwareType();
        String getSysInfo(const int& id);
        String getBdInfo(const String& dump_file);
        String getNoBdInfo();
        String getClockInfo();
        std::pair<int,int> getTemp();
        String checkSyscall(const int& sc_num=8);
        std::pair<int,int> getRsxClock();
        String getIdps();
        bool setIdps(const String& part1, const String& part2);
        String getPsid();
        bool setPsid(const String& part1, const String& part2);
        bool delHistory();
        bool delHistoryF();
        bool removeHook();
        bool pCheckSyscall8();
        bool setGpuClock(const int& mhz);
        bool setVRamClock(const int& mhz);
        bool disableSyscall(const int& sc_num=8);
        bool disableSyscalls();
        bool pDisableSyscall8(const int& mode=0);
        bool sendReboot();
        bool sendSoftReboot();
        bool sendHardReboot();
        bool sendShutdown();
        enum FanMode {
            DYNAMIC = 0,
            MANUAL = 1,
            AUTO = 2,
            SYSCON = 3,
        };
        bool changeFanMode(const FanMode& mode = AUTO);
        bool setTargetTemp(const int& celcius);
        bool setFanSpeed(const int& percent);
        #warning "PS3 GETFANSPEED is not in the main release of webMAN yet. See https://github.com/aldostools/webMAN-MOD/issues/1283"
        int getFanSpeed(const bool& raw = false);
        #warning "PS3 GETFANSPEED is not in the main release of webMAN yet. See https://github.com/aldostools/webMAN-MOD/issues/1283"
        int getFanMode();
        bool increaseFanSpeed();
        bool decreaseFanSpeed();
    private:
        PS3Mapi* ps3mapi;
    };
    
    class Notify {
    public:
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
        enum LEDColor {
            RED = 0,
            GREEN = 1,
            YELLOW = 2
        };
        enum LEDMode {
            OFF = 0,
            ON = 1,
            FAST_BLINK = 2,
            SLOW_BLINK = 3,
            ALT1_BLINK = 4,
            ALT2_BLINK = 5,
            ALT3_BLINK = 6
        };
        enum Icon {
            INFO = 0,
            FRIENDS = 1,
            HEADSET = 2,
            EXCLAIMATION = 3,
            KEYBOARD = 4,
            NETWORK = 5,
            REFRESH = 6,
            WRONGWAY = 7,
            TOOLBOX = 8,
            BRONZE = 9,
            SILVER = 10, 
            GOLD = 11,
            PLATINUM = 12,
            HAND = 13,
            PEN = 14,
            CURSOR = 15,
            FIST = 16,
            PLAY = 17,
            PSN1 = 18,
            PSPLUS = 19,
            SIGNIN = 20,
            NEW = 21,
            TICK = 22,
            RED_EXCLAIMATION = 23,
            WRENCH = 24,
            STAR_TROPHY = 25,
            PSSTORE = 26,
            FOLDER = 27,
            GUEST = 28,
            LOADING = 29,
            MUSIC = 30,
            CAMERA = 31, 
            VIDEO = 32,
            CONTROLLER = 33,
            LOCK = 34,
            REDX = 35,
            UKNOWN1 = 36,
            SEND = 37,
            SPEECHBUBBLE = 38,
            CIRCLE = 39,
            PROFILE = 40, 
            BRDISC = 41,
            CDDISC = 42,
            BLUEDISC = 43,
            BLCKDISC = 44,
            MOVIEDISC = 45,
            DVDDISC = 46,
            QUESTIONDISC = 47,
            PSVITA = 48,
            CLOCK = 49,
            REMOTEPLAY = 50
        };
        enum InfoModes {
            HDD0_FREE = 0,
            USB0_FREE = 1,
            USB1_FREE = 2,
            USB2_FREE = 3,
            USB3_FREE = 4,
            NTFS0_FREE = 5,
            MEM_FREE = 6,
            MEM_USAGE = 7,
            SYSCALL = 8,
            FAN_TEMP = 9,
            FAN_MODE = 10,
            UPTIME = 11,
            PLAYTIME = 12,
            RUNTIME = 13,
            DATETIME = 14,
            GAME_ID = 15,
            PROC_ID = 16,
            PSID = 17,
            IDPSLV2 = 18,
            IDPSEID0 = 19,
            FW_VERS = 20,
            MAC_ADDR = 21,
            IP_ADDR = 22,
            HOME_DIR = 23,
            WM_VERS = 24,
            BD_VENDOR = 25,
            RSX_CORE_CLOCK = 26,
            RSX_VRAM_CLOCk = 27

        };
        Notify(PS3Mapi* wm);
        bool sendNotification(const String& message, const Icon& icon = INFO, const BuzzerMode& snd = NONE);
        bool sendSysNotification(const InfoModes& mode = HDD0_FREE);
        bool buzzer(const BuzzerMode& mode = SINGLE);
        bool led(const LEDColor& color = GREEN, const LEDMode& mode = ON);
    private:
        PS3Mapi* ps3mapi;
    };

    class Process {
    public:
        Process(PS3Mapi* wm);
        String getCurrentProcID();
        String getProcName(const String& pid);
        std::vector<String> getAllProcID();
    private:
        PS3Mapi* ps3mapi;
    };

    class Memory {
    public:
        Memory(PS3Mapi* wm);
        String getMemory(const String& pid, const String& offset, const int& size=16);
        bool setMemory(const String& pid, const String& address, const String& value);
        String payload(const String& pid, const String& payload_path);
        bool unloadPayload(const String& pid);
        bool pageAllocate(const String& pid, const int& size, const int& page_size, const String& flags, const bool& is_executable=false);
        bool pageFree(const String& pid, const String& flags, const String& page_table_0, const String& page_table_1);

    private:
        PS3Mapi* ps3mapi;
    };

    class Module {
    public:
        Module(PS3Mapi* wm);
        String getName(const String& pid, const String& prx_id);
        String getFileName(const String& pid, const String& prx_id);
        bool unload(const String& pid, const String& prx_id);
        bool load(const String& pid, const String& prx_path);
        bool loadVshPlugs(const int& slot, const String& psx_path);
        bool unloadVshPlugs(const int& slot);
        String getVshPlugInfo(const int& slot);
        String getSegments(const int& slot, const String& prx_id);
    private:
        PS3Mapi* ps3mapi;
    };

    class Thread {
    public:
        Thread(PS3Mapi* wm);
        bool create(const String& pid, const String& page_table_0, const String& toc, const String& arg, const String& prio, const String& stack_size, const String& name);
    private:
        PS3Mapi* ps3mapi;
    };

    class Registry {
    public:
        Registry(PS3Mapi* wm);
        String get(const String& reg_key);
        bool set(const String& reg_key, const String& value);
    private:
        PS3Mapi* ps3mapi;
    };

    class Level {
    public:
        Level(PS3Mapi* wm);
        String peekLv1(const String& address);
        String peekLv2(const String& address);
        bool pokeLv1(const String& address, const String& value);
        bool pokeLv2(const String& address, const String& value);
    private:
        PS3Mapi* ps3mapi;
    };

    class File {
    public:
        File(PS3Mapi* wm);
        bool exists(const String& file_path);
        bool isDir(const String& file_path);
        String size(const String& file_path);
        bool refreshNTFS();
        bool download(const String& address, const String& destination = "/dev_hdd0/packages");
        bool installPkg(const String& address, const bool& deleteFile = false);
    private:
        PS3Mapi* ps3mapi;
    };

    class Pad {
    public:
        Pad(PS3Mapi* wm);
        void pushButtons(const std::vector<String>& buttons, float delayFloat=0.0f);
        bool holdButtons(const std::vector<String>& buttons, float releaseAfter=0.0f);
        bool releaseButtons();
        bool acceptButton();
        bool cancelButton();
        bool off();
    private:
        PS3Mapi* ps3mapi;
    };

    class Network {
    public:
        Network(PS3Mapi* wm);
        enum Server {
            ALL = 0,
            PS3MAPI = 1,
            FTP = 2,
            NETSRV = 3,
            ARTEMIS = 4
        };
        bool enable();
        bool disable();
        bool startServer(const Server& server = ALL);
        bool stopServer(const Server& server = ALL);
        bool changeDnsPrimary(const String& address);
        bool changeDnsSecondary(const String& address);
    private:
        PS3Mapi* ps3mapi;
    };

    class XMB {
    public:
        XMB(PS3Mapi* wm);
        enum Category {
            GAME = 0,
            VIDEO = 1,
            FRIEND = 2,
            PSN = 3,
            NETWORK = 4,
            MUSIC = 5,
            PHOTO = 6,
            TV = 7
        };
        enum BrowserType {
            BROWSER = 0,
            SILK = 1,
            WEBKIT = 2
        };
        bool localBrowser(const String& address);
        bool externalBrowser(const String& address, const BrowserType& = BROWSER);
        bool goTo(const Category& category, const int& id);
        bool reload();
        bool refresh();
        bool vshMenu();
        bool sLaunchMenu();
    private:
        PS3Mapi* ps3mapi;
    };
    /**
     * @deprecated Use the XMB class instead. This will be removed in an upcoming version.
     */
    class Browser {
    public:
        Browser(PS3Mapi* wm);

        [[deprecated("Use localBrowser in class XMB instead. This will be removed in an upcoming version.")]]
        bool local(const String& address) {
            return ps3mapi->xmb.localBrowser(address);
        }

        [[deprecated("Use externalBrowser in class XMB instead. This will be removed in an upcoming version.")]]
        bool external(const String& address, const XMB::BrowserType& type = XMB::BROWSER) {
            return ps3mapi->xmb.externalBrowser(address, type);
        }

    private:
        PS3Mapi* ps3mapi;
    };
    String ip; 
    bool displayErrors;   
    System system;
    Notify notify;
    Process process;
    Memory memory;
    Module module;
    Thread thread;
    Registry registry;
    Level level;
    File file;
    Pad pad;
    Network network;
    XMB xmb;
    Browser browser;
private:
    String _sendCommand(const String& apiArg, const String& route);
    bool _sendCommandBool(const String& apiArg, const String& route="");
    std::pair<int,int> _sendCommandTuple(const String& apiArg, const String& route);
    std::vector<String> _sendCommandArray(const String& apiArg, const String& route, const size_t& expectedLength);
};

#endif
