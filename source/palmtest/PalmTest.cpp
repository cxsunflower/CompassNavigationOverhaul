#include "PalmTest.h"
#include "Config.h"
#include "HiggsInterface001.h"
#include "Pose.h"
#include "Scene.h"
#include "Surface.h"
#include "utils/Logger.h"
#include <atomic>
#include <chrono>

namespace CNO::PalmTest
{
    namespace
    {
        using Clock = std::chrono::steady_clock;
        class Runtime;
        Runtime& GetRuntime();

        // One owner for lifecycle and scheduling. Scene and configuration modules are stateless;
        // the surface owns its own resources. Message handling only requests frame-thread resets.
        class Runtime
        {
        public:
            void OnMessage(std::uint32_t type)
            {
                using M = SKSE::MessagingInterface;
                if (type == M::kPostPostLoad) Install();
                else if (type == M::kPreLoadGame) {
                    loading.store(true);
                    resetRequested.store(true);
                } else if (type == M::kDataLoaded || type == M::kPostLoadGame || type == M::kNewGame) {
                    resetRequested.store(true);
                    loading.store(false);
                }
            }

        private:
            void Detach()
            {
                surface.Detach();
                compass.reset();
                nextSearch = {};
            }

            void PollConfig(Clock::time_point now)
            {
                if (now < nextSettings) return;
                nextSettings = now + std::chrono::seconds(1);
                const auto next = ReadConfig();
                if (next.enabled != config.enabled) {
                    surface.AllowLoadRetry();
                    if (!next.enabled) Detach();
                    logger::info("[PalmTest] {}", next.enabled ? "enabled" : "disabled and detached");
                }
                config = next;
            }

            void FindCompass(RE::VR_NODE_DATA& nodes, Clock::time_point now)
            {
                if (compass || now < nextSearch) return;
                nextSearch = now + std::chrono::seconds(1);
                const auto found = Scene::FindCompassCandidates(nodes);
                // Keep the original unique-candidate policy: never guess another HUD surface.
                if (found.size() == 1) {
                    compass.reset(found.front());
                    loggedAmbiguous = false;
                    logger::info("[PalmTest] Verified unique compass anchor {:p}", static_cast<void*>(compass.get()));
                } else if (!loggedAmbiguous) {
                    logger::warn("[PalmTest] {} verified compass candidates; probe hidden (need exactly one)", found.size());
                    loggedAmbiguous = true;
                }
            }

            void UpdateSurface(RE::NiNode* room, Clock::time_point now)
            {
                if (!surface.EnsureAttached(room)) return;
                const auto desired = MakeWorldPose(compass->world, config.offset, config.width);
                if (!surface.ApplyWorldPose(desired)) return;
                if (now < nextLog) return;
                nextLog = now + std::chrono::seconds(2);
                const float error = (surface.World().translate - desired.translate).Length();
                logger::info("[PalmTest] anchorScale={:.4f} panelWorldScale={:.4f} width={:.2f} poseError={:.4f}",
                    compass->world.scale, surface.World().scale, config.width, error);
            }

            void Tick()
            {
                const auto now = Clock::now();
                if (resetRequested.exchange(false)) {
                    Detach();
                    surface.AllowLoadRetry();
                    logger::info("[PalmTest] Scene transition: detached probe and invalidated anchor");
                }
                PollConfig(now);
                if (!config.enabled) return;
                if (loading.load()) { surface.Hide(); return; }

                auto* player = RE::PlayerCharacter::GetSingleton();
                auto* nodes = player ? player->GetVRNodeData() : nullptr;
                if (!nodes || !nodes->RoomNode || !nodes->NPCRHnd) { Detach(); return; }
                auto* room = nodes->RoomNode->AsNode();
                if (!room) { Detach(); return; }
                if ((surface.Parent() && surface.Parent() != room) ||
                    (compass && !Scene::InCurrentScene(compass.get(), *nodes))) Detach();
                FindCompass(*nodes, now);
                auto* ui = RE::UI::GetSingleton();
                if (!compass || !Scene::Visible(compass.get()) || !Scene::Visible(room) || !ui ||
                    ui->GameIsPaused() || ui->IsMenuOpen(RE::MainMenu::MENU_NAME) ||
                    !Scene::Finite(compass->world) || !Scene::Finite(room->world)) {
                    surface.Hide();
                    return;
                }
                UpdateSurface(room, now);
            }

            static void Frame() { GetRuntime().Tick(); }

            void Install()
            {
                if (registered) return;
                if (!GetModuleHandleA("PalmCompassVR.dll")) {
                    logger::info("[PalmTest] Palm Compass not loaded; experimental probe unavailable");
                    return;
                }
                auto* api = HiggsPluginAPI::GetInterface();
                if (!api) { logger::warn("[PalmTest] HIGGS API unavailable; probe disabled"); return; }
                // Palm registers at kPostLoad; append at kPostPostLoad after all kPostLoad callbacks.
                api->AddPostVrikPostHiggsCallback(Frame);
                registered = true;
                logger::info("[PalmTest] Observer registered after Palm; HIGGS build={}; default OFF", api->GetBuildNumber());
            }

            Config config;
            RE::NiPointer<RE::NiAVObject> compass;
            Surface surface;
            std::atomic_bool resetRequested{false};
            std::atomic_bool loading{true};
            bool registered{false};
            bool loggedAmbiguous{false};
            Clock::time_point nextSettings{};
            Clock::time_point nextSearch{};
            Clock::time_point nextLog{};
        };

        Runtime& GetRuntime()
        {
            static Runtime runtime;
            return runtime;
        }
    }

    void OnMessage(std::uint32_t type) { GetRuntime().OnMessage(type); }
}
