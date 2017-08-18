// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#include "AGS2ClientStub.h"
#include "AchievementsStub.h"
#include "LeaderboardsStub.h"
#include "StatsStub.h"
using namespace AGS2Client::Stub;

namespace AGS2Client
{
	IAGS2Client* GetClient() noexcept
	{
		return &AGS2ClientStub::GetAGS2ClientStub();
	}

	IClientAchievements* GetClientAchievements() noexcept
	{
		return &AchievementsStub::GetAchievementsStub();
	}

	IClientLeaderboards* GetClientLeaderboards() noexcept
	{
		return &LeaderboardsStub::GetLeaderboardsStub();
	}

	IClientStats* GetClientStats() noexcept
	{
		return &StatsStub::GetStatsStub();
	}
}
