// Copyright 2021 Swiftrax <swiftrax@gmail.com>
// Copyright 2026 ilEtik
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "dynamic_keymap.h"

enum layers {
    _BASE, // 0: default
    _FN,   // 1: hotkeys
    _DE,   // 2: German letters
};

/* Right Win (LY_NEXT) steps through the layers: 0 -> 1 -> 2 -> 0.
 * Layers 3-7 join the cycle once they have keys set in Vial. */

/*
 * German letters. Each one sends Right Alt (AltGr) + a key, so the computer
 * must use the EurKEY layout (US-based: every other key types exactly like US):
 *   AltGr+A = ä, AltGr+O = ö, AltGr+U = ü, AltGr+S = ß, AltGr+5 = €
 * They are custom keycodes (not plain RALT(KC_A)) so they show up by name in
 * Vial's "User" tab, and so the output can be changed here in one place.
 */
enum custom_keycodes {
    UM_AE = QK_KB_0, // ä, Ä with Shift
    UM_OE,           // ö, Ö with Shift
    UM_UE,           // ü, Ü with Shift
    UM_SS,           // ß (also with Shift; ß has no capital)
    UM_EUR,          // €
    LY_NEXT,         // next layer (cycles, skips empty layers)
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* 0 Base: stock KL-90 layout, with right Win replaced by the layer key. */
[_BASE] = LAYOUT_all(
    KC_DEL ,   KC_ESC ,   KC_F1  ,   KC_F2  ,   KC_F3  ,   KC_F4  ,   KC_F5  ,   KC_F6  ,   KC_F7  ,   KC_F8  ,   KC_F9  ,   KC_F10 ,   KC_F11 ,   KC_F12 ,   KC_PSCR,   KC_MPLY,
    KC_F13 ,   KC_GRV ,   KC_1   ,   KC_2   ,   KC_3   ,   KC_4   ,   KC_5   ,   KC_6   ,   KC_7   ,   KC_8   ,   KC_9   ,   KC_0   ,   KC_MINS,   KC_EQL ,   KC_BSPC,   KC_INS ,
    KC_F14 ,   KC_TAB ,   KC_Q   ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,   KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   ,   KC_P   ,   KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_DEL ,
    KC_F15 ,   KC_CAPS,   KC_A   ,   KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,   KC_H   ,   KC_J   ,   KC_K   ,   KC_L   ,   KC_SCLN,   KC_QUOT,   KC_NUHS,   KC_ENT ,   KC_PGUP,
    KC_F16 ,   KC_LSFT,   KC_NUBS,   KC_Z   ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,   KC_N   ,   KC_M   ,   KC_COMM,   KC_DOT ,   KC_SLSH,   KC_RSFT,   KC_UP  ,   KC_PGDN,
    KC_F17 ,   KC_LCTL,   KC_LGUI,   KC_LALT,              KC_SPC ,   KC_SPC ,   KC_SPC ,   KC_SPC ,              KC_RALT,   LY_NEXT,   KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT),

/* 1 Hotkeys: media on F-row, € on E, Win lock on left Win,
 * arrows -> Home/PgUp/PgDn/End. */
[_FN] = LAYOUT_all(
    _______,   _______,   KC_BRID,   KC_BRIU,   _______,   _______,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MSTP,   _______,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_SCRL,   KC_MUTE,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_DEL ,   _______,
    _______,   _______,   _______,   _______,   UM_EUR ,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_HOME,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_PGUP,   KC_END ,
    _______,   _______,   GU_TOGG,   _______,              _______,   _______,   _______,   _______,              _______,   _______,   _______,   KC_HOME,   KC_PGDN,   KC_END ),

/* 2 German: only four keys, everything else is blank (does nothing):
 *   A -> ä    O -> ö    U -> ü    S -> ß     (hold Shift for Ä Ö Ü)
 * The Shifts and the layer key (right Win) stay, so capitals work and you can
 * get back out. */
[_DE] = LAYOUT_all(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   UM_UE  ,   XXXXXXX,   UM_OE  ,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   UM_AE  ,   UM_SS  ,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,   XXXXXXX,   XXXXXXX,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX)
};

#ifdef ENCODER_MAP_ENABLE
/* Encoder 0: volume, layer 1 = prev/next track. Encoder 1: scroll, layer 1 = screen brightness. */
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
    [_FN]   = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [_DE]   = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif
// clang-format on

/* ---------- Layers ---------- */

static bool layer_has_keys(uint8_t layer) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            if (dynamic_keymap_get_keycode(layer, row, col) != KC_TRNS) {
                return true;
            }
        }
    }
    return false;
}

/* Bitmask of layers that have at least one key set (in Vial). Rechecked once
 * a second, so a layer filled or emptied in Vial counts without a restart. */
static uint8_t layers_in_use(void) {
    static uint8_t  mask  = 0;
    static uint32_t timer = 0;
    if (mask == 0 || timer_elapsed32(timer) >= 1000) {
        timer = timer_read32();
        mask  = 1; // layer 0 always
        for (uint8_t layer = 1; layer < DYNAMIC_KEYMAP_LAYER_COUNT && layer < 8; layer++) {
            if (layer_has_keys(layer)) {
                mask |= 1 << layer;
            }
        }
    }
    return mask;
}

/* LY_NEXT: switch to the next layer that has keys, wrapping back to 0. */
static void next_layer(void) {
    uint8_t mask    = layers_in_use();
    uint8_t current = get_highest_layer(layer_state);
    for (uint8_t i = 1; i <= 8; i++) {
        uint8_t layer = (current + i) % 8;
        if (mask & (1 << layer)) {
            layer_move(layer); // only this layer on; layer 0 stays underneath
            return;
        }
    }
}

/* ---------- German letters ---------- */

static bool process_umlaut(uint16_t keycode, bool pressed) {
    if (!pressed) {
        return false;
    }
    switch (keycode) {
        case UM_AE:
            tap_code16(RALT(KC_A));
            break;
        case UM_OE:
            tap_code16(RALT(KC_O));
            break;
        case UM_UE:
            tap_code16(RALT(KC_U));
            break;
        case UM_SS: {
            // ß has no capital; drop Shift so it can't turn into EurKEY's §.
            uint8_t mods = get_mods();
            del_mods(MOD_MASK_SHIFT);
            tap_code16(RALT(KC_S));
            set_mods(mods);
            break;
        }
        case UM_EUR:
            tap_code16(RALT(KC_5));
            break;
    }
    return false;
}

#ifdef CAPS_WORD_ENABLE
/* Keep Caps Word going through ä ö ü (and capitalise them), like letters. */
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case UM_AE:
        case UM_OE:
        case UM_UE:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case UM_SS:
            return true;
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // "-" becomes "_" in Caps Word
            return true;
        default:
            return false;
    }
}
#endif

/* ---------- OLED ---------- */

#ifdef OLED_ENABLE
#    include "bongocat.h"

/*
 * 128x32 OLED: a status panel on the left, the bongo cat on the right.
 *
 *   0 1 2   |   <- layers in use; the active one is bold and underlined
 *   WPM 087 |   bongo cat
 *   CAP     |   <- CAP = Caps Lock, WRD = Caps Word
 *
 * The cat art spans columns 12..118, so it is shifted right by CAT_SHIFT to
 * end at column 127. That leaves the first 48px of pages 0-2 free for status.
 */
#    define CAT_SHIFT 9
#    define STATUS_PAGES 3
#    define STATUS_WIDTH_PX 48

#    define BONGO_IDLE_WPM 20 // above this, paws stay up between key presses
#    define BONGO_TAP_MS 150  // how long a paw stays down after a key press
#    define BONGO_IDLE_FRAME_MS 200

static void draw_cat(const char *frame) {
    for (uint8_t page = 0; page < OLED_DISPLAY_HEIGHT / 8; page++) {
        // Leave the status panel alone so the text never flickers.
        uint8_t x = page < STATUS_PAGES ? STATUS_WIDTH_PX : 0;
        for (; x < OLED_DISPLAY_WIDTH; x++) {
            char byte = x < CAT_SHIFT ? 0 : pgm_read_byte(frame + page * OLED_DISPLAY_WIDTH + (x - CAT_SHIFT));
            oled_write_raw_byte(byte, page * OLED_DISPLAY_WIDTH + x);
        }
    }
}

/* Every key press slaps a paw down, alternating left and right. */
static uint32_t tap_timer = 0;
static uint8_t  tap_paw   = 0;
static bool     tapped    = false;

static void bongo_on_keypress(void) {
    tap_timer = timer_read32();
    tap_paw ^= 1;
    tapped = true;
}

static void render_bongocat(void) {
    static const char *shown      = NULL;
    static uint32_t    idle_timer = 0;
    static uint8_t     idle_frame = 0;
    const char        *frame;

    if (tapped && timer_elapsed32(tap_timer) < BONGO_TAP_MS) {
        frame = bongo_tap[tap_paw % ARRAY_SIZE(bongo_tap)];
    } else if (get_current_wpm() > BONGO_IDLE_WPM) {
        frame = bongo_prep[0];
    } else {
        if (timer_elapsed32(idle_timer) >= BONGO_IDLE_FRAME_MS) {
            idle_timer = timer_read32();
            idle_frame = (idle_frame + 1) % ARRAY_SIZE(bongo_idle);
        }
        frame = bongo_idle[idle_frame];
    }

    // Only redraw when the picture changes; drawing costs time on every loop.
    if (frame != shown) {
        draw_cat(frame);
        shown = frame;
    }
}

/* Digits 0-9 from QMK's OLED font (5 columns each, top row = bit 0). */
static const uint8_t PROGMEM digit_glyphs[10][5] = {
    {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
    {0x00, 0x42, 0x7F, 0x40, 0x00}, // 1
    {0x72, 0x49, 0x49, 0x49, 0x46}, // 2
    {0x21, 0x41, 0x49, 0x4D, 0x33}, // 3
    {0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
    {0x27, 0x45, 0x45, 0x45, 0x39}, // 5
    {0x3C, 0x4A, 0x49, 0x49, 0x31}, // 6
    {0x41, 0x21, 0x11, 0x09, 0x07}, // 7
    {0x36, 0x49, 0x49, 0x49, 0x36}, // 8
    {0x46, 0x49, 0x49, 0x29, 0x1E}, // 9
};

/* Draw one digit in a 6px cell on page 0. Active: bold (each column OR'd with
 * the one to its left) and underlined (bottom row of the page). */
static void draw_digit(uint8_t x, uint8_t digit, bool active) {
    uint8_t prev = 0;
    for (uint8_t i = 0; i < 6; i++) {
        uint8_t col  = i < 5 ? pgm_read_byte(&digit_glyphs[digit][i]) : 0;
        uint8_t byte = col;
        if (active) {
            byte |= prev | 0x80;
        }
        oled_write_raw_byte(byte, x + i);
        prev = col;
    }
}

/* Line 0: "0 1 2" with the active layer bold + underlined. Up to 4 layers are
 * spaced out; with more, they are packed next to each other to fit. */
static void render_layers(void) {
    uint8_t active = get_highest_layer(layer_state | default_layer_state);
    uint8_t mask   = layers_in_use() | (1 << active);
    uint8_t count  = 0;
    for (uint8_t i = 0; i < 8; i++) {
        count += (mask >> i) & 1;
    }
    uint8_t step = count <= 4 ? 2 * OLED_FONT_WIDTH : OLED_FONT_WIDTH;

    uint8_t x   = 0;
    uint8_t end = 0; // first column after the last digit drawn
    for (uint8_t layer = 0; layer < 8; layer++) {
        if (mask & (1 << layer)) {
            draw_digit(x, layer, layer == active);
            end = x + OLED_FONT_WIDTH;
            x += step;
        }
    }
    // Clear the rest of the line (e.g. after a layer was emptied in Vial).
    for (uint8_t i = end; i < STATUS_WIDTH_PX; i++) {
        oled_write_raw_byte(0, i);
    }
}

static void render_status(void) {
    render_layers();

    // Line 1: words per minute
    oled_set_cursor(0, 1);
    oled_write_P(PSTR("WPM "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);

    // Line 2: Caps Lock / Caps Word
    oled_set_cursor(0, 2);
    if (is_caps_word_on()) {
        oled_write_P(PSTR("WRD"), false);
    } else if (host_keyboard_led_state().caps_lock) {
        oled_write_P(PSTR("CAP"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
}

bool oled_task_user(void) {
    // Blank the screen after OLED_SLEEP_MS without input; any key press or
    // encoder turn wakes it.
    if (last_input_activity_elapsed() > OLED_SLEEP_MS) {
        oled_off();
        return false;
    }
    oled_on();

    render_bongocat();
    render_status();
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        bongo_on_keypress();
    }
#endif
    switch (keycode) {
        case LY_NEXT:
            if (record->event.pressed) {
                next_layer();
            }
            return false;
        case UM_AE ... UM_EUR:
            return process_umlaut(keycode, record->event.pressed);
    }
    return true;
}
