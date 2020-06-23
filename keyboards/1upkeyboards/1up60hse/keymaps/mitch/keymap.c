/* Copyright 2018 MechMerlin
 * Copyright 2018 Logan Huskins
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _DFT 0
#define _NOWINKEY 1
#define _FN 2
#define _SFX 3

#define ______ KC_TRNS
#define bbbbbb KC_NO
#define GUIOFF MAGIC_NO_GUI
#define GUION MAGIC_UNNO_GUI

#define GRAVE_ESC_CTRL_OVERRIDE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
   * |-----------------------------------------------------------------------------------------+
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * |  Caps   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |      Shift      |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl  |  GUI  |  Alt  |              Space              |  Alt  |  GUI  |  L1   | Ctrl  |
   * `-----------------------------------------------------------------------------------------'
   */
  // Note: using the grave-escape key here. See: https://docs.qmk.fm/#/feature_grave_esc
[_DFT] = LAYOUT_60_ansi(
    KC_GESC, KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FN), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                 KC_RGUI, MO(_FN), LT(_SFX, KC_RALT), KC_RCTL

),


/* Replace the windows key with another control key. easier copy/paste and other stuff in windows when needed */
[_NOWINKEY] = LAYOUT_60_ansi(
    ______,  ______, ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
    ______,  ______, ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
    ______,  ______, ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
    ______,  ______, ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
    ______,  ______, KC_LCTL,                 ______,                 KC_LCTL, ______, ______, ______   \
),


/* Fn Layer / Layer 1
 * ,-----------------------------------------------------------------------------------------.
 * |KC_GRV| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |   Del    |
 * |-----------------------------------------------------------------------------------------+
 * | CAPS  |     |     |     |     |     |Home | Pgup| Up  | PgDn| End |     |     |         |
 * |-----------------------------------------------------------------------------------------+
 * |        | Vol-| Vol+| Mute|     |     |     | Left| Down|Right|     |     |              |
 * |-----------------------------------------------------------------------------------------+
 * |           |Prev |Play |Next |     |     |     |     |     |     |     |          |      |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |       |               |       |               |      |      | LrSfx |     |
 * `-----------------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,     KC_F9,    KC_F10,   KC_F11, KC_F12, KC_DEL,
    KC_CAPS, bbbbbb,  bbbbbb,  bbbbbb,  bbbbbb, bbbbbb, KC_HOME, KC_PGUP, KC_UP ,    KC_PGDOWN,KC_END,   bbbbbb, bbbbbb, bbbbbb,
    ______,  KC_VOLD, KC_VOLU, KC_MUTE, bbbbbb, bbbbbb, bbbbbb,  KC_LEFT, KC_DOWN,   KC_RIGHT, bbbbbb,   bbbbbb, ______,
    ______,  KC_MPRV, KC_MPLY, KC_MNXT, bbbbbb, bbbbbb, bbbbbb,  TO(_DFT),TO(_NOWINKEY),bbbbbb,bbbbbb,   ______,
    ______,  ______,  ______,                   ______,                    ______,   ______,   TG(_SFX), ______
),


/* RGB
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |   Reset   |
   * |-----------------------------------------------------------------------------------------+
   * | BL Tog |BLInc|BLDec|BLStp|     |     |     |     |     |     |     |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * | RGB Tog |Mode |Hue I|Sat I|Val I|Spd I|Plain|Breat|Rnbow|Swirl|     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |           |RMode|Hue D|Sat D|Val D|Spd D|Snake|Knigh|Xmas |Gradi|     |                 |
   * |-----------------------------------------------------------------------------------------+
   * |       |       |       |                                 |       |       |       |       |
   * `-----------------------------------------------------------------------------------------'
   */
[_SFX] = LAYOUT_60_ansi(
    ______,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G,______, ______,   ______,  ______, ______,
    ______,  BL_TOGG, BL_STEP, BL_DEC,  BL_INC,  ______,  ______,  ______,  ______, ______, ______,   ______,  ______, RESET,
    ______,  RGB_TOG, RGB_MOD, ______,  ______,  ______,  ______,  ______,  ______, ______, ______,   ______,  ______,
    ______,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______,  ______, ______, ______,   ______,
    ______,  ______,  ______,                    ______,                    ______, ______, TO(_DFT), ______
    )

};
