package me.magnum.melonds.impl

import android.content.SharedPreferences
import android.util.Log

/**
 * odin3-lab: the settings a test run pins (e.g. the renderer and its internal resolution) read over the player's own, for
 * this process only, from the system property debug.melonds.arnes.prefs ("key=value,key=value", the preference keys and
 * values of pref_*.xml), which the lab sets before launching the build and clears after. Nothing is written: the player's
 * preferences stay as they were.
 */
class LabPreferences private constructor(
    private val base: SharedPreferences,
    private val overrides: Map<String, String>,
) : SharedPreferences by base {

    override fun getString(key: String?, defValue: String?): String? = overrides[key] ?: base.getString(key, defValue)
    override fun getBoolean(key: String?, defValue: Boolean): Boolean = overrides[key]?.toBooleanStrictOrNull() ?: base.getBoolean(key, defValue)
    override fun getInt(key: String?, defValue: Int): Int = overrides[key]?.toIntOrNull() ?: base.getInt(key, defValue)
    override fun getLong(key: String?, defValue: Long): Long = overrides[key]?.toLongOrNull() ?: base.getLong(key, defValue)
    override fun getFloat(key: String?, defValue: Float): Float = overrides[key]?.toFloatOrNull() ?: base.getFloat(key, defValue)
    override fun contains(key: String?): Boolean = key in overrides || base.contains(key)

    companion object {
        private const val PROPERTY = "debug.melonds.arnes.prefs"

        fun overlay(base: SharedPreferences): SharedPreferences {
            val value = runCatching {
                ProcessBuilder("getprop", PROPERTY).start().inputStream.bufferedReader().use { it.readText() }.trim()
            }.getOrDefault("")
            val overrides = value.split(',').mapNotNull { entry ->
                entry.split('=', limit = 2).takeIf { it.size == 2 }?.let { (k, v) -> k.trim() to v.trim() }
            }.toMap()
            if (overrides.isEmpty())
                return base
            Log.w("WatermelonSettings", "lab overrides: $overrides")
            return LabPreferences(base, overrides)
        }
    }
}
