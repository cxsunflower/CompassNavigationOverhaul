// HIGGS API/CommonLib adaptation from Palm-Compass-VR, commit 7bc931f.
// Copyright (c) 2026 Sterlingchapman; MIT. See tools/palmtest/THIRD_PARTY_NOTICES.md.
#include "HiggsInterface001.h"

namespace
{
	struct HiggsMessage
	{
		static constexpr std::uint32_t kGetInterface = 0xF9279A57;
		void* (*getApiFunction)(unsigned int) = nullptr;
	};
}

HiggsPluginAPI::IHiggsInterface001* HiggsPluginAPI::GetInterface()
{
	static IHiggsInterface001* cachedInterface = nullptr;
	if (cachedInterface) {
		return cachedInterface;
	}

	const auto messaging = SKSE::GetMessagingInterface();
	if (!messaging) {
		return nullptr;
	}

	HiggsMessage message;
	const auto dispatched = messaging->Dispatch(
		HiggsMessage::kGetInterface,
		std::addressof(message),
		sizeof(HiggsMessage*),
		"HIGGS");

	if (!dispatched || !message.getApiFunction) {
		return nullptr;
	}

	cachedInterface = static_cast<IHiggsInterface001*>(message.getApiFunction(1));
	return cachedInterface;
}
