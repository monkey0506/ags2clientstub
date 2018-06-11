// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2018 MonkeyMoto Productions, Inc.

#include "AchievementsStub.h"
using namespace AGS2Client::Stub;

AchievementsStub achievementsStub;

AchievementsStub& AchievementsStub::GetAchievementsStub() noexcept
{
	return achievementsStub;
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
