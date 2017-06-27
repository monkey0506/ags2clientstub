// AGS2ClientStub
// Game-client plugin stub for AGS
// Copyright © 2014-2017 MonkeyMoto Productions, Inc.

#ifndef AGS2CLIENT_AGS2CLIENTSTUB_H
#define AGS2CLIENT_AGS2CLIENTSTUB_H

#include "ags2client/Cpp11Fix.h"

#include "ags2client/IAGS2Client.h"

namespace AGS2Client
{
    namespace Stub
    {
        class AGS2ClientStub : public AGS2Client::IAGS2Client
        {
		protected:
#if __cplusplus <= 199711L // NOT C++11
			AGS2ClientStub() noexcept {}

		public:
			~AGS2ClientStub() noexcept {}
#else // C++11
			AGS2ClientStub() noexcept = default;

		public:
			~AGS2ClientStub() noexcept = default;
#endif // C++11

        public:
			static AGS2ClientStub& GetAGSteamStub() noexcept;
            bool IsInitialized() const noexcept override;
            void ResetStatsAndAchievements() const noexcept override;
            char const* GetUserName() const noexcept override;
			void Startup() const noexcept override;
            void Shutdown() const noexcept override;
            void Update() const noexcept override;
            char const* GetAGSPluginName() const noexcept override;
            char const* GetAGSPluginDesc() const noexcept override;
            float GetVersion() const noexcept override;
            bool ClaimKeyPress(int data, int (*IsKeyPressed)(int)) const noexcept override;
        };
    } // namespace Stub
} // namespace AGS2Client

#endif // AGS2CLIENT_AGS2CLIENTSTUB_H
