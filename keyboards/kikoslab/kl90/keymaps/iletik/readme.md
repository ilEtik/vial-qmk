# ilEtik's KL-90 keymap

Vial keymap with a status panel and a bongo cat on the OLED.

    make kikoslab/kl90:iletik

## OLED

    0 1 2   |
    WPM 087 |   bongo cat
    CAP     |

- Line 1: the layers that have keys set (0-7). The active one is **bold and underlined**. Layers you
  fill in Vial appear within a second.
- Line 2: words per minute
- Line 3: `CAP` = Caps Lock, `WRD` = Caps Word
- The cat slaps a paw down on every key press (alternating paws), keeps its paws up while you type
  fast, and idles otherwise.
- The screen blanks after 2 minutes without input (`OLED_SLEEP_MS` in `config.h`).

Cat frames are from `keyboards/torn/bongocat.c`.

## Layers

| # | Layer | How to reach it |
|---|---|---|
| 0 | Base (US) | default |
| 1 | Hotkeys | press right Win once from layer 0 |
| 2 | German | press right Win again |

Right Win is the **layer key**: each press moves to the next layer (0 → 1 → 2 → 0). Layers 3-7
join the cycle once you set keys on them in Vial; empty layers are skipped. The OLED shows where
you are.

These are only the defaults written after flashing; change anything in Vial.

| Key / encoder | Base (0) | Hotkeys (1) |
|---|---|---|
| F1 / F2 | F1 / F2 | Screen brightness down / up |
| F5 - F8 | F5 - F8 | Prev / Play-Pause / Next / Stop |
| F10 - F12 | F10 - F12 | Mute / Vol down / Vol up |
| Print Screen | Print Screen | Scroll Lock |
| Backspace | Backspace | Delete |
| E | E | € |
| Left Win | Win | Win lock (toggle) |
| Arrows | Arrows | Home / PgUp / PgDn / End |
| PgUp / PgDn | PgUp / PgDn | Home / End |
| Knob (encoder 0) | Volume | Prev / next track |
| Second knob (encoder 1) | Scroll | Screen brightness |

### German layer (2)

Only four keys do something; every other key is blank:

| Key | German layer | With Shift |
|---|---|---|
| A | ä | Ä |
| O | ö | Ö |
| U | ü | Ü |
| S | ß | ß |

Both Shifts and the layer key (right Win) keep working, so you can type capitals and get back out.

The letters are sent as AltGr (right Alt) combos, so **the computer must use the EurKEY layout**
(KDE: "EurKEY (US)"; Windows: install EurKEY from eurkey.steffen.bruentjen.eu). EurKEY types exactly
like US for every other key. A keyboard can't produce ä on a plain US layout by itself; it only
sends keys, and the computer turns them into characters. To use another method, change
`process_umlaut()` in `keymap.c`.

In Vial the four keys (plus €) are in the **User** tab, so you can put them anywhere.

- **Caps Word**: tap both Shifts together. Types the next word in caps (including ä ö ü) and turns
  itself off at a space or punctuation.
- **8 layers** are available in Vial (the default is 4).
- **Vial unlock**: hold Esc + Enter.

## Flashing

The KL-90's bootloader only works on a USB port directly on the PC (not through a hub or monitor).
Enter it with the reset button on the PCB, or by unlocking in Vial and pressing a `QK_BOOT` key.
Then:

    dfu-programmer at90usb1286 erase --force
    dfu-programmer at90usb1286 flash --force kikoslab_kl90_iletik.hex
    dfu-programmer at90usb1286 reset
