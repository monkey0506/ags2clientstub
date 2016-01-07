// AGSteamStub
// Plugin stub for the Steam plugin for AGS
// Copyright © 2014-2016 MonkeyMoto Productions, Inc.
//
// This stub is a non-functional replacement for the AGSteam plugin. The
// full plugin cannot be made open-source due to restrictions enforced
// by Valve's strict licensing on the Steamworks API. If you are a
// developer who has signed an NDA with Valve and have access to
// Steamworks, access can be granted to the full plugin source. For more
// information you may contact monkey_05_06 on the AGS forums at:
// <http://www.adventuregamestudio.co.uk/forums/index.php?action=profile&u=2015>
//
// This work is free. You can redistribute it and/or modify it under the
// terms of the Do What The Fuck You Want To Public License, Version 2,
// as published by Sam Hocevar. See the LICENSE file for more details.
//
//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//                    Version 2, December 2004
//
// Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
//
// Everyone is permitted to copy and distribute verbatim or modified
// copies of this license document, and changing it is allowed as long
// as the name is changed.
//
//            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
//   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//  0. You just DO WHAT THE FUCK YOU WANT TO.
//
// The AGSteamStub plugin may be licensed under future versions of
// the WTFPL, or any compatible license which is not less restrictive.
// See http://www.wtfpl.net/ for more details.
//
#include "StatsStub.h"
using namespace AGSteam::Stub;

StatsStub& StatsStub::GetStatsStub() noexcept
{
	static StatsStub stub{};
	return stub;
}

int StatsStub::GetIntStat(char const *) const noexcept
{
	return 0;
}

float StatsStub::GetFloatStat(char const*) const noexcept
{
	return 0.0f;
}

float StatsStub::GetAverageRateStat(char const*) const noexcept
{
	return 0.0f;
}

bool StatsStub::SetIntStat(char const*, int) const noexcept
{
	return false;
}

bool StatsStub::SetFloatStat(char const*, float) const noexcept
{
	return false;
}

bool StatsStub::UpdateAverageRateStat(char const*, float, float) const noexcept
{
	return false;
}
