#ifndef CONFIGURATIONLOG_H
#define CONFIGURATIONLOG_H

#include <string>
#include "Configuration.h"

namespace MelonDSAndroid
{

// The settings an emulation runs with, one "key: value" line each, logged when it is set up (logcat tag
// WatermelonSettings) so that a run on the device can be compared with an odin3-lab run, which prints the same lines.
template<typename Out>
void ForEachSetting(const EmulatorConfiguration& c, Out&& out)
{
    auto put = [&](const char* key, const std::string& value) { out(std::string(key) + ": " + value); };
    auto b = [](bool v) { return std::string(v ? "true" : "false"); };
    auto s = [](const char* v) { return std::string(v ? v : ""); };
    put("renderer", std::to_string(static_cast<int>(c.renderer)));
    if (c.renderSettings)
    {
        switch (c.renderer)
        {
        case Renderer::Software:
        {
            auto& r = static_cast<const SoftwareRenderSettings&>(*c.renderSettings);
            put("render.threadedRendering", b(r.threadedRendering));
            break;
        }
        case Renderer::OpenGl:
        {
            auto& r = static_cast<const OpenGlRenderSettings&>(*c.renderSettings);
            put("render.scale", std::to_string(r.scale));
            put("render.betterPolygons", b(r.betterPolygons));
            break;
        }
        case Renderer::Vulkan:
        {
            auto& r = static_cast<const VulkanRenderSettings&>(*c.renderSettings);
            put("render.scale", std::to_string(r.scale));
            put("render.betterPolygons", b(r.betterPolygons));
            put("render.threadedRendering", b(r.threadedRendering));
            put("render.videoFiltering", std::to_string(static_cast<int>(r.videoFiltering)));
            break;
        }
        case Renderer::Compute:
        {
            auto& r = static_cast<const ComputeRenderSettings&>(*c.renderSettings);
            put("render.scale", std::to_string(r.scale));
            put("render.highResCoordinates", b(r.highResCoordinates));
            break;
        }
        }
    }
    put("consoleType", std::to_string(c.consoleType));
    put("useJit", b(c.useJit));
    put("hgEngineFixEnabled", b(c.hgEngineFixEnabled));
    put("showBootScreen", b(c.showBootScreen));
    put("userInternalFirmwareAndBios", b(c.userInternalFirmwareAndBios));
    put("dsBios7Path", s(c.dsBios7Path));
    put("dsBios9Path", s(c.dsBios9Path));
    put("dsFirmwarePath", s(c.dsFirmwarePath));
    put("dsiBios7Path", s(c.dsiBios7Path));
    put("dsiBios9Path", s(c.dsiBios9Path));
    put("dsiFirmwarePath", s(c.dsiFirmwarePath));
    put("dsiNandPath", s(c.dsiNandPath));
    put("wfcSettingsPath", c.wfcSettingsPath);
    put("firmware.username", c.firmwareConfiguration.username);
    put("firmware.language", std::to_string(c.firmwareConfiguration.language));
    put("firmware.birthdayMonth", std::to_string(c.firmwareConfiguration.birthdayMonth));
    put("firmware.birthdayDay", std::to_string(c.firmwareConfiguration.birthdayDay));
    put("firmware.favouriteColour", std::to_string(c.firmwareConfiguration.favouriteColour));
    put("firmware.message", c.firmwareConfiguration.message);
    put("firmware.randomizeMacAddress", b(c.firmwareConfiguration.randomizeMacAddress));
    put("firmware.macAddress", c.firmwareConfiguration.macAddress);
    put("frameskipMode", std::to_string(c.frameskipMode));
    put("frameskipManualValue", std::to_string(c.frameskipManualValue));
    put("vulkanDrsEnabled", b(c.vulkanDrsEnabled));
    put("lowLatencyEnabled", b(c.lowLatencyEnabled));
    put("rtcOffsetMinutes", std::to_string(c.rtcOffsetMinutes));
    put("fastForwardSpeedMultiplier", std::to_string(c.fastForwardSpeedMultiplier));
    put("frameLimitSpeedMultiplier", std::to_string(c.frameLimitSpeedMultiplier));
    put("audio.soundEnabled", b(c.audioSettings.soundEnabled));
    put("audio.volume", std::to_string(c.audioSettings.volume));
    put("audio.audioInterpolation", std::to_string(c.audioSettings.audioInterpolation));
    put("audio.audioBitrate", std::to_string(c.audioSettings.audioBitrate));
    put("audio.audioLatency", std::to_string(c.audioSettings.audioLatency));
    put("audio.micSource", std::to_string(c.audioSettings.micSource));
    put("rewindEnabled", std::to_string(c.rewindEnabled));
    put("dsiSdCard.enabled", b(c.dsiSdCardSettings.enabled));
    put("dldiSdCard.enabled", b(c.dldiSdCardSettings.enabled));
}

}

#endif
