#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Fn     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt | Cmd|        Space          |Cmd| FN| alt|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  MO(_FL) , KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_PGDN, \
  KC_LCTL,KC_LALT, KC_LGUI,                KC_SPC,                        KC_RGUI,MO(_FL),KC_RALT, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * | ~ | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |    |
   * |----------------------------------------------------------------|
   * | Bksp|bdn|bup|exp| c~|Bl-|BL |BL+|   |   |   | M | M |     |    |
   * |----------------------------------------------------------------|
   * |  Fn  |mut|vdn|vup|ct |   |   |   |   |   |   | M |Num Ret |Hme |
   * |----------------------------------------------------------------|
   * |  CAPS  |prv|ply|nxt|   |   | M |   |   | M |   |      |   |End |
   * |----------------------------------------------------------------|
   * |    |    |    |            Enter     |   | Fn | F16|F17|F18|f19 |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  KC_TILD, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______ ,  \
  KC_BSPC,KC_SLCK, KC_PAUS, LCTL(KC_UP), LGUI(KC_TILD),BL_DEC,BL_TOGG,BL_INC,_______,_______, _______,    M(0),   M(1),_______,_______, \
  _______,KC_MUTE, KC_VOLD, KC_VOLU, LGUI(KC_TAB),_______,_______,_______,_______,_______,_______, M(2),    KC_PENT, KC_HOME, \
  KC_CAPS,KC_MRWD, KC_MPLY, KC_MFFD, _______,_______, M(4),_______,_______,M(3),_______,_______, _______, KC_END, \
  _______,_______,_______,                 KC_ENT,               _______,_______,KC_F16,KC_F17,KC_F18, KC_F19),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0: // block comment  / *
          if (record->event.pressed) {
          } else {
            return MACRO( T(SLSH), D(LSFT), T(8), U(LSFT),  END);
          }
          break;

        case 1: // block comment  * /
          if (record->event.pressed) {
          } else {
            return MACRO(  D(LSFT), T(8), U(LSFT), T(SLSH),  END);
          }
          break;

        case 2: // @"%@"
          if (record->event.pressed) {
          } else {
            return MACRO( D(LSFT), T(2), T(QUOT), T(5), T(2), T(QUOT), U(LSFT),  END);
          }
          break;

        case 3: // ->
          if (record->event.pressed) {
          } else {
            return MACRO( T(MINS), D(LSFT), T(DOT), U(LSFT),  END);
          }
          break;
	case 4: // NSString*
          if (record->event.pressed) {
          } else {
            return MACRO( D(LSFT), T(N), T(S), T(S), U(LSFT), T(T),T(R),T(I),T(N),T(G), D(LSFT), T(8), U(LSFT),  END);
          }
          break;
      }
    return MACRO_NONE;
};
