/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define _MAIN 0
#define _FN 1
#define _SFX 2

// Fillers to make layering more clear
#define ______ KC_TRNS
#define bbbbbb KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // [0] = LAYOUT(
    //     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
    //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
    //     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
    //     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
    //     KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    // ),



[_MAIN] = LAYOUT( /* Basic QWERTY */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        F(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        MO(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

[_FN] = LAYOUT( /* Basic QWERTY */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_DEL,
        KC_CAPS, bbbbbb,  bbbbbb,  bbbbbb,  bbbbbb,  KC_INS,  KC_HOME, KC_PGUP, KC_UP , KC_PGDOWN,KC_END,  bbbbbb,  bbbbbb,  bbbbbb,           KC_PGUP,
        ______,  KC_VOLD, KC_VOLU, KC_MUTE, bbbbbb,  bbbbbb,  bbbbbb,  KC_LEFT, KC_DOWN, KC_RIGHT,bbbbbb,  bbbbbb,           ______,           KC_PGDN,
        ______,           KC_MPRV, KC_MPLY, KC_MNXT, bbbbbb,  bbbbbb,  bbbbbb,  _______, _______, ______,  ______,           ______,  KC_UP,   KC_END,
        ______,  ______,  ______,                             ______,                             ______,  ______,  TG(_SFX),KC_LEFT, KC_DOWN, KC_RGHT
    ),

[_SFX] = LAYOUT( /* Basic QWERTY */
        ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           ______,
        ______,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G, ______,  ______,  ______,  ______,  ______,           ______,
        ______,  BL_TOGG, BL_STEP, BL_DEC,  BL_INC,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  RESET,            ______,
        ______,  RGB_TOG, RGB_MOD, ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           ______,           ______,
        ______,           RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______,  ______,  ______,  ______,           ______,  ______,  ______,
        ______,  ______,  ______,                             ______,                             ______,  ______, TO(_MAIN),______,  ______,  ______
    ),

//
// ORIG
//
/*
[_FN] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL, \
        KC_CAPS, bbbbbb,  bbbbbb,  bbbbbb,  bbbbbb, KC_INS, KC_HOME, KC_PGUP,  KC_UP ,   KC_PGDOWN,KC_END, bbbbbb, bbbbbb, KC_DEL,  \
        ______,  KC_VOLD, KC_VOLU, KC_MUTE, bbbbbb, bbbbbb, bbbbbb,  KC_LEFT,  KC_DOWN,  KC_RIGHT, bbbbbb, bbbbbb, ______,   \
        ______,  KC_MPRV, KC_MPLY, KC_MNXT, bbbbbb, bbbbbb, bbbbbb,  TO(_DFT), _______, ______, ______, ______, ______,  \
        ______,  ______,  ______,           ______, ______, ______,                          ______, ______,TG(_SFX),______  \
    ),

[_SFX] = LAYOUT(
        ______,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G,______, ______, ______,  ______, ______, ______, \
        ______,  BL_TOGG, BL_STEP, BL_DEC,  BL_INC,  ______,  ______,  ______,  ______, ______, ______, ______,  ______,  RESET,  \
        ______,  RGB_TOG, RGB_MOD,______,  ______,  ______,  ______,  ______,  ______, ______, ______, ______,  ______,  \
        ______,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______,  ______, ______, ______, ______,  ______,  \
        ______,  ______,  ______,             ______, ______, ______,                   ______, ______,TO(_DFT),______   \
    )
*/


};


void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
}


enum function_id {
    SHIFT_ESC,
};

// rsm: custom esc-key behavior. There might be a better way to do this but I don't know what it
// is right now, and this works for my dz60, so...
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
