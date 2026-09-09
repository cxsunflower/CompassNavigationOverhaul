#include "MessageListeners.h"

#include "Settings.h"
#include "IUI/API.h"
#include "IUI/GFxLoggers.h"
#include "Compass.h"
#include "QuestItemList.h"
#include "Test.h"
#include "Hooks.h"
#include "SettingsLifecycle.h"
#include "utils/Logger.h"

static void LogDisplayObject(IUI::GFxDisplayObject& a_object)
{
	static GFxMemberLogger<logger::level::debug> memberLogger;

	memberLogger.LogMembersOf(a_object);

	RE::GPointF origin = a_object.LocalToGlobal();

	logger::debug("{} is on ({}, {})", a_object.ToString().c_str(), origin.x, origin.y);
}

void InfinityUIMessageListener(SKSE::MessagingInterface::Message* a_msg)
{
	if (!a_msg || std::string_view(a_msg->sender) != "InfinityUI")
	{
		return;
	}

	if (auto message = IUI::API::TranslateAs<IUI::API::Message>(a_msg))
	{
		std::string_view movieUrl = message->movie->GetMovieDef()->GetFileURL();

		// SE 使用 HUDMenu.swf，VR 则把同一套 HUDMovieBaseInstance 放在 VR_HMD_info.swf 中。
		const bool isSupportedHUDMovie = movieUrl.find("HUDMenu") != std::string::npos ||
			movieUrl.find("VR_HMD_info") != std::string::npos;

		if (!isSupportedHUDMovie)
		{
			return;
		}

		switch (a_msg->type)
		{
		case IUI::API::Message::Type::kStartLoadInstances:
			logger::info("Started loading HUD patches");
			break;
		case IUI::API::Message::Type::kPreReplaceInstance:
			if (auto preReplaceMessage = IUI::API::TranslateAs<IUI::API::PreReplaceInstanceMessage>(a_msg))
			{
				std::string pathToOriginal = preReplaceMessage->originalInstance.ToString().c_str();

				if (pathToOriginal == CNO::Compass::path)
				{
					CNO::Compass::InitSingleton(preReplaceMessage->originalInstance);

					if (auto compass = CNO::Compass::GetSingleton())
					{
						logger::debug("Before replacing:");
						LogDisplayObject(*compass);
					}
				}
			}
			break;
		case IUI::API::Message::Type::kPostPatchInstance:
			if (auto postPatchMessage = IUI::API::TranslateAs<IUI::API::PostPatchInstanceMessage>(a_msg))
			{
				std::string pathToNew = postPatchMessage->newInstance.ToString().c_str();

				if (pathToNew == CNO::Compass::path)
				{
					// holder 应已在替换前初始化，否则说明补丁流程异常。
					if (auto compass = CNO::Compass::GetSingleton())
					{
						compass->SetupMod(postPatchMessage->newInstance);

						// QuestList is authored inside Compass, not loaded as a second movie.
						RE::GFxValue embeddedList;
						if (compass->GetMovieView()->GetVariable(&embeddedList, QuestItemList::path.data()) &&
							embeddedList.IsDisplayObject())
						{
							// QuestList is hosted by Compass's shared HUD atlas.
							// Keep this path active in VR; the dedicated panel must not replace it.
							QuestItemList::InitSingleton(embeddedList);
							auto list = QuestItemList::GetSingleton();
							CNO::UI::ApplyQuestListSettings(*list);
							logger::info("[QuestListAnchor] Embedded Compass sprite initialized: {}", QuestItemList::path);
						}
						else
						{
							logger::error("[QuestListAnchor] Embedded QuestList missing from Compass");
						}

						// 单例创建后补同步单位；重复调用无副作用。
						compass->SetUnits();

						logger::debug("After replacing:");
						LogDisplayObject(*compass);

						if (hooks::compat::MapMarkerFramework::pluginInfo)
						{
							hooks::compat::MapMarkerFramework::compassMovieDef = postPatchMessage->newInstanceMovieDef;
						}
					}
					else
					{
						logger::error("Compass instance counterpart not ready for {}", CNO::Compass::path);
					}
				}
				else if (pathToNew == QuestItemList::path && !REL::Module::IsVR())
				{
					QuestItemList::InitSingleton(postPatchMessage->newInstance);

					if (auto questItemList = QuestItemList::GetSingleton())
					{
						// Both initialization paths use the same settings synchronization.
						CNO::UI::ApplyQuestListSettings(*questItemList);

						LogDisplayObject(*questItemList);
					}
				}
			}
			break;
		case IUI::API::Message::Type::kAbortPatchInstance:
			if (auto abortPatchMessage = IUI::API::TranslateAs<IUI::API::AbortPatchInstanceMessage>(a_msg))
			{
				std::string pathToOriginal = abortPatchMessage->originalValue.ToString().c_str();

				if (pathToOriginal == CNO::Compass::path)
				{
					logger::error("Aborted replacement of {}", CNO::Compass::path);
				}
			}
			break;
		case IUI::API::Message::Type::kFinishLoadInstances:
			if (auto finishLoadMessage = IUI::API::TranslateAs<IUI::API::FinishLoadInstancesMessage>(a_msg))
			{
				RE::GFxValue test;
				if (finishLoadMessage->movie->GetVariable(&test, Test::path.data()))
				{
					Test::InitSingleton(test);
				}
			}
			// Saved marker scales must also apply on startup, not only INI reload.
			if (auto compass = CNO::Compass::GetSingleton())
			{
				compass->SetMarkerNameScale(settings::display::markerNameScale);
				compass->SetMarkerDistanceScale(settings::display::markerDistanceScale);
				if (compass->HasMember("GetMarkerScaleState"))
				{
					logger::info("[MarkerScale] startup {}", compass->Invoke("GetMarkerScaleState").ToString().c_str());
				}
			}
			logger::info("Finished loading HUD patches");
			break;
		case IUI::API::Message::Type::kPostInitExtensions:
			if (auto postInitExtMessage = IUI::API::TranslateAs<IUI::API::PostInitExtensionsMessage>(a_msg))
			{
				if (auto questItemList = QuestItemList::GetSingleton())
				{
					questItemList->AddToHudElements();

					logger::debug("QuestItemList added to HUD elements");
				}

				logger::debug("Extensions initialization finished");
			}
			break;
		default:
			break;
		}
	}
}
