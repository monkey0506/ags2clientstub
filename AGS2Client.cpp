// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2018 MonkeyMoto Productions, Inc.

#include "AGS2ClientStub.h"
#include "AchievementsStub.h"
#include "LeaderboardsStub.h"
#include "StatsStub.h"
#include "ags2client/DllExports.h"
using namespace AGS2Client::Stub;

namespace AGS2Client
{
	AGS2CLIENT_EXPORT IAGS2Client* GetClient() noexcept
	{
		return &AGS2ClientStub::GetAGS2ClientStub();
	}

    AGS2CLIENT_EXPORT IClientAchievements* GetClientAchievements() noexcept
	{
		return &AchievementsStub::GetAchievementsStub();
	}

    AGS2CLIENT_EXPORT IClientLeaderboards* GetClientLeaderboards() noexcept
	{
		return &LeaderboardsStub::GetLeaderboardsStub();
	}

    AGS2CLIENT_EXPORT IClientStats* GetClientStats() noexcept
	{
		return &StatsStub::GetStatsStub();
	}
}
