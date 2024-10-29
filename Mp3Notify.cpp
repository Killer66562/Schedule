#include "Mp3Notify.h"
#include <DFMiniMp3.h>

static void Mp3Notify::PrintlnSourceAction(DfMp3_PlaySources source, const char* action) {}
static void Mp3Notify::OnError([[maybe_unused]] DfMp3& mp3, uint16_t errorCode) {}
static void Mp3Notify::OnPlayFinished([[maybe_unused]] DfMp3& mp3, [[maybe_unused]] DfMp3_PlaySources source, uint16_t track) {}
static void Mp3Notify::OnPlaySourceOnline([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source) {}
static void Mp3Notify::OnPlaySourceInserted([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source) {}
static void Mp3Notify::OnPlaySourceRemoved([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source) {}