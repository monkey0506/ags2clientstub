// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#ifndef AGS2CLIENT_LEADERBOARDSSTUB_H
#define AGS2CLIENT_LEADERBOARDSSTUB_H

#include "ags2client/Cpp11Fix.h"
#include "ags2client/IClientLeaderboards.h"

namespace AGS2Client
{
    namespace Stub
    {
        class LeaderboardsStub : public AGS2Client::IClientLeaderboards
        {
		protected:
#ifndef AGS2CLIENT_HAS_CPP11
			LeaderboardsStub() noexcept {}

		public:
			~LeaderboardsStub() noexcept {}
#else // C++11
			LeaderboardsStub() noexcept = default;

		public:
			~LeaderboardsStub() noexcept = default;
#endif // C++11

        public:
			static LeaderboardsStub& GetLeaderboardsStub() noexcept;
			void RequestLeaderboard(char const*, AGS2Client::LeaderboardScore::Type, int) const noexcept override;
			bool UploadScore(int) const noexcept override;
			char const* GetCurrentLeaderboardName() const noexcept override;
			char const* GetLeaderName(int) const noexcept override;
			int GetLeaderScore(int) const noexcept override;
			int GetLeaderCount() const noexcept override;
        };
    } // namespace Stub
} // namespace AGS2Client

#endif // AGS2CLIENT_LEADERBOARDSSTUB_H
