// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#include <string>
#include "ags2client/agsplugin.h"

#include "AGS2ClientStub.h"
using namespace AGS2Client::Stub;

AGS2ClientStub& AGS2ClientStub::GetAGS2ClientStub() noexcept
{
	static AGS2ClientStub stub;
	return stub;
}

void AGS2ClientStub::Startup() const noexcept
{
}

bool AGS2ClientStub::IsInitialized() const noexcept
{
    return false;
}

void AGS2ClientStub::ResetStatsAndAchievements() const noexcept
{
}

char const* AGS2ClientStub::GetCurrentGameLanguage() const noexcept
{
    return nullptr;
}

char const* AGS2ClientStub::GetExtraFunctionsForScriptHeader() const noexcept
{
    return
        "  import static void Initialize(const string, const string);\r\n";
}

char const* AGS2ClientStub::GetUserName() const noexcept
{
    return nullptr;
}

void AGS2ClientStub::Shutdown() const noexcept
{
}

void AGS2ClientStub::Update() const noexcept
{
}

char const* AGS2ClientStub::GetAGSPluginName() const noexcept
{
#ifdef AGS2CLIENTSTUB_PLUGIN_NAME
    return AGS2CLIENTSTUB_PLUGIN_NAME;
#else
    return "AGS2Client";
#endif // AGS2CLIENTSTUB_PLUGIN_NAME
}

char const* AGS2ClientStub::GetAGSPluginDesc() const noexcept
{
    return "AGS2ClientStub: Game-client plugin stub for AGS (C) 2014-2017 MonkeyMoto Productions, Inc.";
}

float AGS2ClientStub::GetVersion() const noexcept
{
    return 3.0f;
}

bool AGS2ClientStub::ClaimKeyPress(int data, int (*IsKeyPressed)(int)) const noexcept
{
	return false;
}

int AGS2ClientStub_Initialize(char const*, char const*) // to match AGSGalaxy::Initialize(char const*, char const*)
{
    return 0;
}

void AGS2ClientStub::RegisterScriptFunctions(IAGSEngine *engine) const noexcept
{
	static std::string initialize = std::string(this->GetClientNameForScript()) + "::Initialize^2";
    IAGS2Client::RegisterScriptFunctions(engine);
    engine->RegisterScriptFunction(initialize.c_str(), reinterpret_cast<void*>(AGS2ClientStub_Initialize));
}
