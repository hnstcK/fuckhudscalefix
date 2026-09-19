#include "plugin.h"
#include "sampapi/0.3.DL-1/CChat.h"

using namespace plugin;
using namespace sampapi::v03dl;

namespace {
    bool g_initialized = false;

    void InitializeHudScaleFix()
    {
        if (g_initialized)
            return;

        HMODULE hSamp = GetModuleHandleA("samp.dll");
        if (!hSamp)
            return;

        uintptr_t sampBase = reinterpret_cast<uintptr_t>(hSamp);

        injector::WriteMemory<BYTE>(sampBase + 0x151a6E, 0x00, true);

        injector::MakeNOP(sampBase + 0x682EA, 5);

        CChat*& pChat = RefChat();
        if (pChat)
        {
            pChat->AddMessage(-1, "HUD Scale Fix permanently applied!");
        }

        g_initialized = true;
    }
}

class HudScaleFixPlugin
{
public:
    HudScaleFixPlugin()
    {
        Events::drawHudEvent += InitializeHudScaleFix;
    }
} hudScaleFixPlugin;