/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x04, 0x29, 0xA2, 0xA1, 0x55, 0xB8, 0x05, 0x0D}

/* Unlock combo for Vial: hold Esc + Enter */
#define VIAL_UNLOCK_COMBO_ROWS { 0, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 1, 14 }

/* 8 layers instead of Vial's default 4 (the AT90USB1286 has 4KB of EEPROM) */
#define DYNAMIC_KEYMAP_LAYER_COUNT 8

/* Caps Word: tap both Shift keys to toggle it */
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* OLED: blank after 2 minutes without input to avoid burn-in.
 * The keymap handles this itself, so the driver's own timeout is off. */
#define OLED_SLEEP_MS 120000
#define OLED_TIMEOUT 0

