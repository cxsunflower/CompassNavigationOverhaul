#pragma once

// Keep the existing SKSE and Infinity UI callback names and linkage.
extern const SKSE::LoadInterface* skse;

void SKSEMessageListener(SKSE::MessagingInterface::Message* a_msg);
void InfinityUIMessageListener(SKSE::MessagingInterface::Message* a_msg);
