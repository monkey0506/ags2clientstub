// AGSteamStub
// Plugin stub for the Steam plugin for AGS
// Copyright © 2014-2015 MonkeyMoto Productions, Inc.
// LICENSE FILE
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
#ifndef AGSTEAM_AGSTEAMSTUB_H
#define AGSTEAM_AGSTEAMSTUB_H

#include "ags2client/IAGS2Client.h"

namespace AGSteam
{
    namespace Stub
    {
        class AGSteamStub : public AGS2Client::IAGS2Client
        {
        public:
            void AttemptDefaultInitialization() const override
            {
            }

            bool IsInitialized() const override
            {
                return false;
            }

            void ResetStatsAndAchievements() const override
            {
            }

            char const* GetCurrentGameLanguage() const override
            {
                return nullptr;
            }

            char const* GetUserName() const override
            {
                return nullptr;
            }

            void Shutdown() const override
            {
            }

            void Update() const override
            {
            }

            char const* GetAGSScriptHeader(float version = 2.0f) const override
            {
                return IAGS2Client::GetAGSScriptHeader(version);
            }

            char const* GetAGSPluginName() const override
            {
                return "AGSteamStub";
            }

            char const* GetAGSPluginDesc() const override
            {
                return "AGSteamStub: Plugin stub for the Steam plugin for AGS (C) 2014-2015 MonkeyMoto Productions, Inc.";
            }

            bool ClaimKeyPress(int data, int(*IsKeyPressed)(int)) const override
            {
                bool isShift = ((data == 403) || (data == 404)); // is pressed key shift
                bool isTab = (data == 9); // is pressed key tab
                bool isShiftTab = ((data == 0x00001111) || // shift+tab as a single key
                    ((isShift) && (IsKeyPressed(9) != 0)) || // key is shift and tab is held
                    ((isTab) && ((IsKeyPressed(403) != 0) || (IsKeyPressed(404) != 0)))); // key is tab and shift is held
                return isShiftTab; // Claim (Shift+Tab), ignore other keys
            }

            ~AGSteamStub()
            {
            }
        };

        AGSteamStub& GetAGSteamStub();
    } // namespace Stub
} // namespace AGSteam

#endif // AGSTEAM_AGSTEAMSTUB_H
