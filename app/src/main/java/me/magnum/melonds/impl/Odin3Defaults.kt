package me.magnum.melonds.impl

import android.content.SharedPreferences
import androidx.core.content.edit

/**
 * odin3: the fork's own defaults, set once over a player's existing preferences too (a new android:defaultValue only
 * reaches a key never written, and the settings screen writes every key it shows). Dynamic internal resolution on: a
 * Vulkan game at 16x (4K) lowers its internal resolution in its heaviest scenes instead of its frame rate (Dragon Quest
 * IX's prologue sky on the Odin 3: 41 fps without, 60 with).
 */
object Odin3Defaults {
    private const val APPLIED = "odin3_defaults_v1"

    fun apply(preferences: SharedPreferences): SharedPreferences {
        if (!preferences.getBoolean(APPLIED, false)) {
            preferences.edit {
                putBoolean("video_vulkan_drs", true)
                putBoolean(APPLIED, true)
            }
        }
        return preferences
    }
}
