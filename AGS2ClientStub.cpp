// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#include "AGS2ClientStub.h"
using namespace AGS2Client::Stub;

AGS2ClientStub& AGS2ClientStub::GetAGSteamStub() noexcept
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
    return "AGS2ClientStub";
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
