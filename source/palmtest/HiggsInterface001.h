// HIGGS API/CommonLib adaptation from Palm-Compass-VR, commit 7bc931f.
// Copyright (c) 2026 Sterlingchapman; MIT. See tools/palmtest/THIRD_PARTY_NOTICES.md.
#pragma once

namespace HiggsPluginAPI
{
	struct IHiggsInterface001
	{
		using PulledCallback = void (*)(bool, RE::TESObjectREFR*);
		using GrabbedCallback = void (*)(bool, RE::TESObjectREFR*);
		using DroppedCallback = void (*)(bool, RE::TESObjectREFR*);
		using StashedCallback = void (*)(bool, RE::TESForm*);
		using ConsumedCallback = void (*)(bool, RE::TESForm*);
		using CollisionCallback = void (*)(bool, float, float);
		using StartTwoHandingCallback = void (*)();
		using StopTwoHandingCallback = void (*)();
		using PrePhysicsStepCallback = void (*)(void*);
		using NoArgCallback = void (*)();

		enum class CollisionFilterComparisonResult : std::uint8_t
		{
			kContinue,
			kCollide,
			kIgnore
		};

		using CollisionFilterComparisonCallback =
			CollisionFilterComparisonResult (*)(void*, std::uint32_t, std::uint32_t);

		virtual unsigned int GetBuildNumber() = 0;
		virtual void AddPulledCallback(PulledCallback) = 0;
		virtual void AddGrabbedCallback(GrabbedCallback) = 0;
		virtual void AddDroppedCallback(DroppedCallback) = 0;
		virtual void AddStashedCallback(StashedCallback) = 0;
		virtual void AddConsumedCallback(ConsumedCallback) = 0;
		virtual void AddCollisionCallback(CollisionCallback) = 0;
		virtual void GrabObject(RE::TESObjectREFR*, bool) = 0;
		virtual RE::TESObjectREFR* GetGrabbedObject(bool) = 0;
		virtual bool IsHandInGrabbableState(bool) = 0;
		virtual void DisableHand(bool) = 0;
		virtual void EnableHand(bool) = 0;
		virtual bool IsDisabled(bool) = 0;
		virtual void DisableWeaponCollision(bool) = 0;
		virtual void EnableWeaponCollision(bool) = 0;
		virtual bool IsWeaponCollisionDisabled(bool) = 0;
		virtual bool IsTwoHanding() = 0;
		virtual void AddStartTwoHandingCallback(StartTwoHandingCallback) = 0;
		virtual void AddStopTwoHandingCallback(StopTwoHandingCallback) = 0;
		virtual bool CanGrabObject(bool) = 0;
		virtual void AddCollisionFilterComparisonCallback(CollisionFilterComparisonCallback) = 0;
		virtual void AddPrePhysicsStepCallback(PrePhysicsStepCallback) = 0;
		virtual std::uint64_t GetHiggsLayerBitfield() = 0;
		virtual void SetHiggsLayerBitfield(std::uint64_t) = 0;
		virtual RE::NiObject* GetHandRigidBody(bool) = 0;
		virtual RE::NiObject* GetWeaponRigidBody(bool) = 0;
		virtual RE::NiObject* GetGrabbedRigidBody(bool) = 0;
		virtual void ForceWeaponCollisionEnabled(bool) = 0;
		virtual bool IsHoldingObject(bool) = 0;
		virtual void GetFingerValues(bool, float[5]) = 0;
		virtual void AddPreVrikPreHiggsCallback(NoArgCallback) = 0;
		virtual void AddPreVrikPostHiggsCallback(NoArgCallback) = 0;
		virtual void AddPostVrikPreHiggsCallback(NoArgCallback) = 0;
		virtual void AddPostVrikPostHiggsCallback(NoArgCallback) = 0;
		virtual bool Deprecated1(const std::string_view&, double&) = 0;
		virtual bool Deprecated2(const std::string&, double) = 0;
		virtual RE::NiTransform GetGrabTransform(bool) = 0;
		virtual void SetGrabTransform(bool, const RE::NiTransform&) = 0;
		virtual bool GetSettingDouble(const char*, double&) = 0;
		virtual bool SetSettingDouble(const char*, double) = 0;
		virtual RE::BSFixedString GetGrabbedNodeName(bool) = 0;
	};

	[[nodiscard]] IHiggsInterface001* GetInterface();
}
