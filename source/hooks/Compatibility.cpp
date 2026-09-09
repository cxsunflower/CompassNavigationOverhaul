#include "Internal.h"

namespace hooks::compat
{
	void MapMarkerFramework::Install(HMODULE a_moduleHandle)
	{
		// Hook ImportManager::SetupHUDMenu 对 a_movieView->GetMovieDef() 的调用。
		struct GetCompassMovieDefHook : Hook<6>
		{
			GetCompassMovieDefHook(std::uintptr_t a_hookedAddress) :
				Hook{ a_hookedAddress, reinterpret_cast<std::uintptr_t>(&GetCompassMovieDef) }
			{}
		};

		std::uintptr_t getCompassMovieDefHookAddress = SigScanner::FindPattern
		<
			"4C 8B F1 "	// mov     r14, rcx
			"48 8B 02 "	// mov     rax, [rdx]
			"48 8B CA "	// mov     rcx, rdx <- We want this address (offset 6)
			"FF 50 08 "	// call    qword ptr [rax+8]
			"?? 8B ?? "	// mov     ??, rax
			"48 85 C0"	// test    rax, rax
		>(a_moduleHandle) + 6;

		GetCompassMovieDefHook getCompassMovieDefHook{ getCompassMovieDefHookAddress };

		static CustomTrampoline mapMarkerFrameworkTrampoline{ "MapMarkerFramework Trampoline", a_moduleHandle,
															  getCompassMovieDefHook.getSize() };

		mapMarkerFrameworkTrampoline.write_call(getCompassMovieDefHook);
	}

	RE::GFxMovieDef* MapMarkerFramework::GetCompassMovieDef()
	{
		return compassMovieDef;
	}
}
