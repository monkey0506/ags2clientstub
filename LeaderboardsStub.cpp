// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#include "LeaderboardsStub.h"
using namespace AGS2Client::Stub;

LeaderboardsStub& LeaderboardsStub::GetLeaderboardsStub() noexcept
{
	static LeaderboardsStub stub;
	return stub;
}

void LeaderboardsStub::RequestLeaderboard(char const*, AGS2Client::LeaderboardScore::Type, int) const noexcept
{
}

extern "C" void LeaderboardsStub_FindLeaderboard(char const *leaderboardName)
{
    LeaderboardsStub::GetLeaderboardsStub().RequestLeaderboard(nullptr, AGS2Client::LeaderboardScore::AroundUser, 10);
}

bool LeaderboardsStub::UploadScore(int) const noexcept
{
	return false;
}

char const* LeaderboardsStub::GetCurrentLeaderboardName() const noexcept
{
	return nullptr;
}

char const* LeaderboardsStub::GetLeaderName(int) const noexcept
{
	return nullptr;
}

int LeaderboardsStub::GetLeaderScore(int) const noexcept
{
	return 0;
}

int LeaderboardsStub::GetLeaderCount() const noexcept
{
	return 0;
}
