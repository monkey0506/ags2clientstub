// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#ifndef AGS2CLIENT_ACHIEVEMENTSSTUB_H
#define AGS2CLIENT_ACHIEVEMENTSSTUB_H

#include "ags2client/IClientAchievements.h"

namespace AGS2Client
{
    namespace Stub
    {
        class AchievementsStub : public AGS2Client::IClientAchievements
        {
		protected:
#if __cplusplus <= 199711L // NOT C++11
			AchievementsStub() noexcept {}

		public:
			~AchievementsStub() noexcept {}
#else // C++11
			AchievementsStub() noexcept = default;

		public:
			~AchievementsStub() noexcept = default;
#endif // C++11

        public:
			static AchievementsStub& GetAchievementsStub() noexcept;
			bool ResetAchievement(char const*) const noexcept override;
			bool IsAchievementAchieved(char const*) const noexcept override;
			bool SetAchievementAchieved(char const*) const noexcept override;
        };
    } // namespace Stub
} // namespace AGS2Client

#endif // AGS2CLIENT_ACHIEVEMENTSSTUB_H
