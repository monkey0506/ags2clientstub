// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#include "AchievementsStub.h"
using namespace AGS2Client::Stub;

AchievementsStub& AchievementsStub::GetAchievementsStub() noexcept
{
	static AchievementsStub stub;
	return stub;
}

bool AchievementsStub::ResetAchievement(char const*) const noexcept
{
	return true;
}

bool AchievementsStub::IsAchievementAchieved(char const*) const noexcept
{
	return false;
}

bool AchievementsStub::SetAchievementAchieved(char const*) const noexcept
{
	return false;
}
