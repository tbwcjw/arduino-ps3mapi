/*

  ps3mapi.h - Library for flashing Morse code.

  Created by tbwcjw.

  Released under the MIT License.

*/
#ifndef PS3MAPI_H
#define PS3MAPI_H

#include <HTTPClient.h>
#include "utils.h"
#include <utility>
#include <vector>

class PS3Mapi {
public:
    PS3Mapi(const String& ip);
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
        String getRsxClock();
        String getIdps();
        bool setIdps(const String& part1, const String& part2);
        String getPsid();
        bool setPsid(const String& part1, const String& part2);
        bool delHistory();
        bool delHistoryF();
        bool removeHook();
        String pCheckSyscall8();
        bool setGpuClock(const int& mhz);
        bool setVRamClock(const int& mhz);
        bool disableSyscall(const int& sc_num=8);
        bool pDisableSyscall8(const int& mode=0);
        bool sendReboot();
        bool sendSoftReboot();
        bool sendHardReboot();
        bool sendShutdown();
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
            PLPLUS = 19,
            SIGNIN = 20,
            NEW = 21,
            TICK = 22,
            RED_EXCLAIMATION = 23,
            WRENCH = 24,
            START_TROPHY = 25,
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
        Notify(PS3Mapi* wm);
        bool sendNotification(const String& message, const Icon& icon = INFO, const BuzzerMode& snd = NONE);
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
        String getAllProcID();
    private:
        PS3Mapi* ps3mapi;
    };

    class Memory {
    public:
        Memory(PS3Mapi* wm);
        String getMemory(const String& pid, const String& offset, const String& size);
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
        String exists(const String& file_path);
        String isDir(const String& file_path);
        String size(const String& file_path);
        String md5(const String& file_path);
    private:
        PS3Mapi* ps3mapi;
    };

    class Pad {
    public:
        Pad(PS3Mapi* wm);

        void pushButtons(const std::vector<String>& buttons, float delay_float=0.0f);
        bool acceptButton();
        bool cancelButton();
        bool off();
        bool releaseButtons();

    private:
        PS3Mapi* ps3mapi;
    };

    Notify notify;
    Process process;
    Memory memory;
    System system;
    Module module;
    Thread thread;
    Registry registry;
    Level level;
    File file;
    Pad pad;

private:
    String ip;
    String _sendCommand(const String& apiArg, const String& route);
    bool _sendCommandBool(const String& apiArg, const String& route);
    std::pair<int,int> _sendCommandTuple(const String& apiArg, const String& route);
};

#endif
