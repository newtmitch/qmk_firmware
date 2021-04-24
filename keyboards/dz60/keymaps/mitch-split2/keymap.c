#include "dz60.h"

#define _DFT 0
#define _HHKB 1
#define _NGUI 2
#define _VIM 3
#define _FN 4
#define _VIMFN 5
#define _MS 6
#define _SFX 7
#define _NOWINKEY 8

// Fillers to make layering more clear
#define ______ KC_TRNS
#define bbbbbb KC_NO
#define GUIOFF MAGIC_NO_GUI
#define GUION MAGIC_UNNO_GUI

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

/* TODO: create handy quick-ref list here for easy grokking of the actual shortcuts in place */
/*
 * NOTE: Putting keymap definitions here in order to not modify the dz60.h file just for my
 * specific keymap definitions. I'm assuming that's not a bad idea...
 */

/* Mitch's keymap, "MITCHSPLIT2":
 *  Standard 60% base, split right shift, 3-split space, split backspace, standard modifier row.
 *  Split shift is 2.75u + 1.25u + 2.25u (total of 6.25u). Might not work with other orientations.
 */
/*
 * ,-----------------------------------------------------------------------------------------.
 * |K000 |K001 |K002 |K003 |K004 |K005 |K006 |K007 |K008 |K009 |K010 |K011 |K012 |K013 |K014 |
 * |-----------------------------------------------------------------------------------------+
 * | K100  |K102 |K103 |K104 |K105 |K106 |K107 |K108 |K109 |K110 |K111 |K112 |K113 |  K114   |
 * |-----------------------------------------------------------------------------------------+
 * |  K200  |K202 |K203 |K204 |K205 |K206 |K207 |K208 |K209 |K210 |K211 |K212 |     K213     |
 * |-----------------------------------------------------------------------------------------+
 * |    K300    |K302 |K303 |K304 |K305 |K306 |K307 |K308 |K309 |K310 |K311 |   K313   |K314 |
 * |-----------------------------------------------------------------------------------------+
 * | K400 | K401 | K403 |       K404      | K406 |      K408     | K410 | K411 | K413 | K414 |
 * `-----------------------------------------------------------------------------------------'
 */
#define MITCHSPLIT2( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, \
	K100,       K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, \
	K200,       K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,       \
	K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, \
	K400, K401,       K403, K404,       K406,       K408,       K410, K411,       K413, K414  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014 }, \
	{ K100,  KC_NO, K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114 }, \
	{ K200,  KC_NO, K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  KC_NO }, \
	{ K300,  KC_NO, K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO, K313,  K314 }, \
	{ K400,  K401,  KC_NO, K403,  K404,  KC_NO, K406,  KC_NO, K408,  KC_NO, K410,  K411,  KC_NO, K413,  K414 }  \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * This is Mitch's default ACR60 layout (also DZ60, on which the ACR60 is based). This is a
 * Mac-oriented layout, as noted by the GUI keys immediately next to the space bar area of the
 * lower modifier row. This uses the MITCHSPLIT2 keymap as defined in arc60.h, which uses a
 * 3-split space bar and a split right shift. Otherwise it's a standard 60% layout (for now).
 *
 * For me, this is a great place to start getting used to a split key setup and still mostly
 * sticking to a standard staggered 60% layout so my entire game isn't thrown off.
 *
 * Layers (0-based index because we're devs!):
 *
 *    0: Default QWERTY layer
 *      Note Fn and Alt keys on the right side of the spacebar, not sure if those are
 *      normal position but that's what I'm used to at this point. YMMV
 *
 *    1: Function Layer
 *      Function keys, Grave Key, Delete, Caps lock on the tab, media keys, and directional
 *      keys. Also you can hit the Alt key position to switch (and lock) into the 3rd layer
 *      if you really want to mess with your SFX for a bit.
 *
 *    2: Special Effects Layer
 *      RGB and backlight settings access. RGB cycle on "S" key position and if locked into
 *      the third layer you can hold shift to cycle backwards (see notes below). Bootloader
 *      access is on this layer. If layer locked, hit right Alt key to get back to layer 0.
 *
 * The keymap layer definitions below look pretty bad when soft-wrapped by your IDE / text editor.
 * Be sure to disable wrapping to make things more readable with lines preserved.
 */
/* QWERTY "standard" layer
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |Bcksp| Del |
 * |-----------------------------------------------------------------------------------------+
 * | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \     |
 * |-----------------------------------------------------------------------------------------+
 * |   Fn   |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter     |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  / | RShift     | FN  |
 * |-----------------------------------------------------------------------------------------+
 * | LCtrl | LAlt | LGUI  |      Space      | Space|   Space    | RGUI |  Fn  | RAlt | RCtrl |
 * `-----------------------------------------------------------------------------------------'
 */
/* Qwerty gui/alt/space/alt/gui /
 *
 * Esc key is F(0) which outputs tilde on shift+ESC and grave accent on Fn+ESC.
 *
 * Hit MO(_FN) and Alt in that order to lock into the _FN layer.
 */
  [_DFT] = MITCHSPLIT2( /* Basic QWERTY */
      F(0),    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, \
      KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  \
      MO(_FN), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
      KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_MS), \
      KC_LCTL, KC_LALT, KC_LGUI,        KC_SPC, KC_SPC, KC_SPC,                  KC_RGUI, MO(_FN), LT(_SFX, KC_RALT),KC_RCTL \
      ),

/* Kill windows Key
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |    |     |     |     |     |     |     |     |         |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |BLOCKED|               |       |             |BLOCKED|      |       |      |
 * `-----------------------------------------------------------------------------------------'
 */
/* Replace the windows key with another control key. easier copy/paste and other stuff in windows when needed */
  [_NOWINKEY] = MITCHSPLIT2(
      ______,  ______, ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,  ______, ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,  ______, ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,  ______, ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,  ______, KC_LCTL,          ______, ______, ______,                 KC_LCTL, ______, ______, ______   \
      ),

/* Fn Layer / Layer 1
 * ,-----------------------------------------------------------------------------------------.
 * |KC_GRV| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |   Del    |
 * |-----------------------------------------------------------------------------------------+
 * | CAPS  |     |     |     |     | Ins |Home | Pgup| Up  | PgDn| End |     |     |         |
 * |-----------------------------------------------------------------------------------------+
 * |        | Vol-| Vol+| Mute|     |     |     | Left| Down|Right|     |     |              |
 * |-----------------------------------------------------------------------------------------+
 * |         |Prev |Play |Next |     |     |     |LrDft|LrNGui|LrHHKB|     |          |      |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |       |               |       |               |      |      | LrSfx |     |
 * `-----------------------------------------------------------------------------------------'
 */
/*
 * Pok3r-style layer switching on M and "," keys (_DFT and _NGUI layers, respectively). Note that
 * these don't enable/disable those layers (i.e. latching keys), they actually switch to that layer.
 * To go to the _NGUI layer, Fn+comma, to go to _DFT from _NGUI, hit Fn+M.
 */
 /* Function Layer: Functions, primary layer switching, media controls, directional */
  [_FN] = MITCHSPLIT2(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL, \
      KC_CAPS, bbbbbb,  bbbbbb,  bbbbbb,  bbbbbb, KC_INS, KC_HOME, KC_PGUP,  KC_UP ,   KC_PGDOWN,KC_END, bbbbbb, bbbbbb, KC_DEL,  \
      ______,  KC_VOLD, KC_VOLU, KC_MUTE, bbbbbb, bbbbbb, bbbbbb,  KC_LEFT,  KC_DOWN,  KC_RIGHT, bbbbbb, bbbbbb, ______,   \
      ______,  KC_MPRV, KC_MPLY, KC_MNXT, bbbbbb, bbbbbb, bbbbbb,  TO(_DFT),TO(_NOWINKEY), ______, ______, ______, ______,  \
      ______,  ______,  ______,           ______, ______, ______,                          ______, ______,TG(_SFX),______  \
      ),

/* Special Effects Layer / Layer 2
 * ,-----------------------------------------------------------------------------------------.
 * |     |Plain|Brth |Rnbw |Swirl|Snake|Knght|Xmas |Grdnt|     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        | BL  |BLSTEP| BL- | BL+ |    |     |     |     |     |     |     |     |Bootldr |
 * |-----------------------------------------------------------------------------------------+
 * |         | RGBT| RGBM|     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           | Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |       |               |       |              |      |      |LrDflt |      |
 * `-----------------------------------------------------------------------------------------'
 */
/* Tap RAlt to get back to default layer (0).
 *
 * See https://docs.qmk.fm/feature_rgblight.html#rgblight-keycodes for details about
 * RGB codes. Quick summary, though:
 *
 *    RGB_MODE_PLAIN         RGB_M_P	    Switch to the static no animation mode
 *    RGB_MODE_BREATHE       RGB_M_B	    Switch to the breathing mode
 *    RGB_MODE_RAINBOW       RGB_M_R	    Switch to the rainbow mode (cycles through colors)
 *    RGB_MODE_SWIRL         RGB_M_SW	    Switch to the swirl mode (like an animated gradient)
 *    RGB_MODE_SNAKE         RGB_M_SN	    Switch to the snake mode
 *    RGB_MODE_KNIGHT        RGB_M_K	    Switch to the knight animation
 *    RGB_MODE_XMAS          RGB_M_X	    Switch to the Christmas animation
 *    RGB_MODE_GRADIENT      RGB_M_G	    Switch to the static gradient mode
 *
 *    Note that there are more animation variations, usually timer-based variations, by using the
 *    "S" key to cycle through modes. Use one of the deciated keys to get to
 *    the general mode where you want it, then cycle through variations of that mode to get
 *    something specific more quickly.
 */
 /* "special effects" Layer: RGB lighting, backlighting, bootloader */
  [_SFX] = MITCHSPLIT2(
      ______,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_M_X, RGB_M_G,______, ______, ______,  ______, ______, ______, \
      ______,  BL_TOGG, BL_STEP, BL_DEC,  BL_INC,  ______,  ______,  ______,  ______, ______, ______, ______,  ______,  RESET,  \
      ______,  RGB_TOG, RGB_MOD,______,  ______,  ______,  ______,  ______,  ______, ______, ______, ______,  ______,  \
      ______,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______,  ______, ______, ______, ______,  ______,  \
      ______,  ______,  ______,             ______, ______, ______,                   ______, ______,TO(_DFT),______   \
      )

};

/*
 * BACKUP LAYOUT CONFIGS
 * I'm not using these right now but wanted to keep them just in case.
 */

/* HHKB-style keys
 * ,-----------------------------------------------------------------------------------------.
 * | ESC |     |     |     |     |     |     |     |     |     |     |     |     |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |    |     |     |     |     |     |     |     |  Bcksp  |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |       |               |       |             |       |      |       |      |
 * `-----------------------------------------------------------------------------------------'
 */
/*
 * NOTE 2021-04-24: This looks like it isn't set up very well. This is likely best implemented as
 * a layer on top of the base layer to override the backslash and split backspace keys. But I'm
 * leaving this as-is for now.
 *
 * ---- ORIGINAL COMMENTS BELOW ----
 *
 * This layer allows me to play around with an HHKB style mapping, specifically for the location
 * of the backspace/delete key, the backslash, and the backtick/tilde. Given that this layout already
 * basically maps over to HHKB (except for the bottom row) I can build a layer that can sit on top of
 * default and pass almost everything through except those three keys.
 *
 * Also note that I'm replacing the F(0) call from the default layout on the ESC key to just a regular
 * escape - this means the grave key moves entirely to the right side, which I believe is more true to the
 * HHKB layout itself. However, because of where this layer is positioned, FN+ESC will still trigger the
 * Grave key because that activates the _FN layer from the base layout. For now I'm just going to leave
 * this be.
 */
/* HHKB Layer: Base QWERTY layer in (mostly) HHKB format */
/* rsm: 2020-06-08 - not used
[_HHKB] = MITCHSPLIT2(
  KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,  \
  MO(_FN), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(_MS), \
  KC_LCTL, KC_LALT, KC_LGUI,        KC_SPC, KC_SPC, KC_SPC,                  KC_RGUI, MO(_FN), LT(_SFX, KC_RALT), KC_RCTL   \
  ),
*/

/* VIM-arrows on the function layer
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |    |     |     |     |     |     |     |     |         |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     | Left | Down | Up |Right|     |     |            |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 * |      |      |       |               |       |               |      |      |       |     |
 * `-----------------------------------------------------------------------------------------'
 */
// overrides other arrows on the Fn layer
/* rsm: disabled 2020-06-08 - I don't really use these
[_VIMFN] = MITCHSPLIT2(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,\
  KC_CAPS, bbbbbb,  bbbbbb,  bbbbbb,  bbbbbb, bbbbbb, KC_HOME, KC_PGUP, bbbbbb ,  KC_PGDOWN,KC_END, bbbbbb, bbbbbb, bbbbbb,  \
  ______,  KC_VOLD, KC_VOLU, KC_MUTE, bbbbbb, bbbbbb, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, bbbbbb, bbbbbb, ______,   \
  ______,  KC_MPRV, KC_MPLY, KC_MNXT, bbbbbb, bbbbbb, bbbbbb,TO(_DFT),TO(_VIM), TO(_NGUI),   bbbbbb, ______, ______,  \
  ______,  ______,  ______,           ______, ______, ______,                    ______,   ______,TG(_SFX),______  \
  ),
*/