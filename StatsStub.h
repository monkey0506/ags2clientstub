// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#ifndef AGS2CLIENT_STATSSTUB_H
#define AGS2CLIENT_STATSSTUB_H

#include "ags2client/Cpp11Fix.h"
#include "ags2client/IClientStats.h"

namespace AGS2Client
{
    namespace Stub
    {
        class StatsStub : public AGS2Client::IClientStats
        {
		protected:
#if __cplusplus <= 199711L // NOT C++11
			StatsStub() noexcept {}

		public:
			~StatsStub() noexcept {}
#else // C++11
			StatsStub() noexcept = default;

		public:
			~StatsStub() noexcept = default;
#endif // C++11

        public:
			static StatsStub& GetStatsStub() noexcept;
			int GetIntStat(char const *) const noexcept override;
			float GetFloatStat(char const*) const noexcept override;
			float GetAverageRateStat(char const*) const noexcept override;
			bool SetIntStat(char const*, int) const noexcept override;
			bool SetFloatStat(char const*, float) const noexcept override;
			bool UpdateAverageRateStat(char const*, float, float) const noexcept override;
        };
    } // namespace Stub
} // namespace AGS2Client

#endif // AGS2CLIENT_STATSSTUB_H
