// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2018 MonkeyMoto Productions, Inc.

#include <string>
#include "ags2client/agsplugin.h"
#include "ags2client/IClientAchievements.h"
#include "ags2client/IClientLeaderboards.h"
#include "ags2client/IClientStats.h"

#include "AGS2ClientStub.h"
using namespace AGS2Client::Stub;

AGS2ClientStub ags2clientStub;

AGS2ClientStub& AGS2ClientStub::GetAGS2ClientStub() noexcept
{
	return ags2clientStub;
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

std::string ags2clientStubHeader;

std::string replace_all(std::string str, std::string const &from, std::string const &to)
{
    if (from.empty())
    {
        return str;
    }
    std::string::size_type start_pos = 0U;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

char const* AGS2ClientStub::GetAGSScriptHeader() const noexcept
{
    std::string ags2clientHeader = IAGS2Client::GetAGSScriptHeader();
    std::string agsteamHeader = replace_all(ags2clientHeader, "AGS2Client", "AGSteam");
    std::string agsGalaxyHeader = replace_all(ags2clientHeader, "AGS2Client", "AGSGalaxy");
    ags2clientStubHeader = ags2clientHeader + "\r\n" + agsteamHeader + "\r\n" + agsGalaxyHeader;
    return ags2clientStubHeader.c_str();
}

char const* AGS2ClientStub::GetAGSPluginName() const noexcept
{
    return "AGS2ClientStub";
}

char const* AGS2ClientStub::GetAGSPluginDesc() const noexcept
{
    return "AGS2ClientStub: Game-client plugin stub for AGS (C) 2014-2018 MonkeyMoto Productions, Inc.";
}

float AGS2ClientStub::GetVersion() const noexcept
{
    return 3.1f;
}

bool AGS2ClientStub::ClaimKeyPress(int data, int (*IsKeyPressed)(int)) const noexcept
{
	return false;
}

extern "C" int AGS2ClientStub_Initialize(char const*, char const*) // to match AGSGalaxy::Initialize(char const*, char const*)
{
    return 0;
}

extern "C" void LeaderboardsStub_FindLeaderboard(char const *leaderboardName);

void AGS2ClientStub::RegisterScriptFunctions(IAGSEngine *engine) const noexcept
{
    // register "AGS2Client" functions
    IAGS2Client::RegisterScriptFunctions(engine);
    engine->RegisterScriptFunction("AGS2Client::Initialize^2", reinterpret_cast<void*>(AGS2ClientStub_Initialize)); // stub for AGSGalaxy
    // register "AGSteam" functions
    engine->RegisterScriptFunction("AGSteam::IsAchievementAchieved^1", reinterpret_cast<void*>(ClientAchievements_IsAchievementAchieved));
    engine->RegisterScriptFunction("AGSteam::SetAchievementAchieved^1", reinterpret_cast<void*>(ClientAchievements_SetAchievementAchieved));
    engine->RegisterScriptFunction("AGSteam::ResetAchievement^1", reinterpret_cast<void*>(ClientAchievements_ResetAchievement));
    engine->RegisterScriptFunction("AGSteam::GetIntStat^1", reinterpret_cast<void*>(ClientStats_GetIntStat));
    engine->RegisterScriptFunction("AGSteam::GetFloatStat^1", reinterpret_cast<void*>(ClientStats_GetFloatStat));
    engine->RegisterScriptFunction("AGSteam::GetAverageRateStat^1", reinterpret_cast<void*>(ClientStats_GetAverageRateStat));
    engine->RegisterScriptFunction("AGSteam::SetIntStat^2", reinterpret_cast<void*>(ClientStats_SetIntStat));
    engine->RegisterScriptFunction("AGSteam::SetFloatStat^2", reinterpret_cast<void*>(ClientStats_SetFloatStat));
    engine->RegisterScriptFunction("AGSteam::UpdateAverageRateStat^3", reinterpret_cast<void*>(ClientStats_UpdateAverageRateStat));
    engine->RegisterScriptFunction("AGSteam::ResetStatsAndAchievements^0", reinterpret_cast<void*>(AGS2Client_ResetStatsAndAchievements));
    engine->RegisterScriptFunction("AGSteam::get_Initialized", reinterpret_cast<void*>(AGS2Client_IsInitialized));
    engine->RegisterScriptFunction("AGSteam::get_CurrentLeaderboardName", reinterpret_cast<void*>(ClientLeaderboards_GetCurrentLeaderboardName));
    engine->RegisterScriptFunction("AGSteam::RequestLeaderboard^3", reinterpret_cast<void*>(ClientLeaderboards_RequestLeaderboard));
    engine->RegisterScriptFunction("AGSteam::UploadScore^1", reinterpret_cast<void*>(ClientLeaderboards_UploadScore));
    engine->RegisterScriptFunction("AGSteam::geti_LeaderboardNames", reinterpret_cast<void*>(ClientLeaderboards_GetLeaderName));
    engine->RegisterScriptFunction("AGSteam::geti_LeaderboardScores", reinterpret_cast<void*>(ClientLeaderboards_GetLeaderScore));
    engine->RegisterScriptFunction("AGSteam::get_LeaderboardCount", reinterpret_cast<void*>(ClientLeaderboards_GetLeaderCount));
    engine->RegisterScriptFunction("AGSteam::GetUserName^0", reinterpret_cast<void*>(AGS2Client_GetUserName));
    engine->RegisterScriptFunction("AGSteam::GetCurrentGameLanguage^0", reinterpret_cast<void*>(AGS2Client_GetCurrentGameLanguage));
    engine->RegisterScriptFunction("AGSteam::FindLeaderboard^1", reinterpret_cast<void*>(LeaderboardsStub_FindLeaderboard)); // stub for legacy AGSteam build
    // register "AGSGalaxy" functions
    engine->RegisterScriptFunction("AGSGalaxy::IsAchievementAchieved^1", reinterpret_cast<void*>(ClientAchievements_IsAchievementAchieved));
    engine->RegisterScriptFunction("AGSGalaxy::SetAchievementAchieved^1", reinterpret_cast<void*>(ClientAchievements_SetAchievementAchieved));
    engine->RegisterScriptFunction("AGSGalaxy::ResetAchievement^1", reinterpret_cast<void*>(ClientAchievements_ResetAchievement));
    engine->RegisterScriptFunction("AGSGalaxy::GetIntStat^1", reinterpret_cast<void*>(ClientStats_GetIntStat));
    engine->RegisterScriptFunction("AGSGalaxy::GetFloatStat^1", reinterpret_cast<void*>(ClientStats_GetFloatStat));
    engine->RegisterScriptFunction("AGSGalaxy::GetAverageRateStat^1", reinterpret_cast<void*>(ClientStats_GetAverageRateStat));
    engine->RegisterScriptFunction("AGSGalaxy::SetIntStat^2", reinterpret_cast<void*>(ClientStats_SetIntStat));
    engine->RegisterScriptFunction("AGSGalaxy::SetFloatStat^2", reinterpret_cast<void*>(ClientStats_SetFloatStat));
    engine->RegisterScriptFunction("AGSGalaxy::UpdateAverageRateStat^3", reinterpret_cast<void*>(ClientStats_UpdateAverageRateStat));
    engine->RegisterScriptFunction("AGSGalaxy::ResetStatsAndAchievements^0", reinterpret_cast<void*>(AGS2Client_ResetStatsAndAchievements));
    engine->RegisterScriptFunction("AGSGalaxy::get_Initialized", reinterpret_cast<void*>(AGS2Client_IsInitialized));
    engine->RegisterScriptFunction("AGSGalaxy::get_CurrentLeaderboardName", reinterpret_cast<void*>(ClientLeaderboards_GetCurrentLeaderboardName));
    engine->RegisterScriptFunction("AGSGalaxy::RequestLeaderboard^3", reinterpret_cast<void*>(ClientLeaderboards_RequestLeaderboard));
    engine->RegisterScriptFunction("AGSGalaxy::UploadScore^1", reinterpret_cast<void*>(ClientLeaderboards_UploadScore));
    engine->RegisterScriptFunction("AGSGalaxy::geti_LeaderboardNames", reinterpret_cast<void*>(ClientLeaderboards_GetLeaderName));
    engine->RegisterScriptFunction("AGSGalaxy::geti_LeaderboardScores", reinterpret_cast<void*>(ClientLeaderboards_GetLeaderScore));
    engine->RegisterScriptFunction("AGSGalaxy::get_LeaderboardCount", reinterpret_cast<void*>(ClientLeaderboards_GetLeaderCount));
    engine->RegisterScriptFunction("AGSGalaxy::GetUserName^0", reinterpret_cast<void*>(AGS2Client_GetUserName));
    engine->RegisterScriptFunction("AGSGalaxy::GetCurrentGameLanguage^0", reinterpret_cast<void*>(AGS2Client_GetCurrentGameLanguage));
    engine->RegisterScriptFunction("AGSGalaxy::Initialize^2", reinterpret_cast<void*>(AGS2ClientStub_Initialize));
}
