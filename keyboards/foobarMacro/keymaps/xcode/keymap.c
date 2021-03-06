/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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
#include "foobarMacro.h"

#define _______ KC_TRNS

enum custom_keycodes {
    Z_NSSTR = SAFE_RANGE,
    Z_NSLOG,
};

enum tap_dance_declarations {
  TD_PL_MN = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // See https://docs.qmk.fm/keycodes.html

[0] = KEYMAP( /* Base - DEBUG */
  KC_ESCAPE, 	LGUI(KC_R), LGUI(KC_DOT), KC_NO,  TO(1),  \
  KC_NO, 		KC_F15,     KC_F16,       KC_F17, KC_F18, \
  KC_NO, 		KC_NO,      KC_NO,        KC_NO,  KC_NO   \
),

[1] = KEYMAP( /* First Layer */
  KC_NO, KC_NO, KC_NO,   	KC_NO,   TO(0), \
  KC_NO, KC_NO, Z_NSSTR, 	Z_NSLOG, KC_NO, \
  KC_NO, KC_NO, KC_NO, 		KC_NO,   KC_NO  \
),

};

qk_tap_dance_action_t tap_dance_actions[] = {
  // See https://docs.qmk.fm/tap_dance.html
  [TD_PL_MN] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PMNS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // See https://docs.qmk.fm/macros.html
  if (record->event.pressed) {
    switch(keycode) {
      case Z_NSSTR:
        SEND_STRING("NSString *");
        return false; break;
      case Z_NSLOG:
        SEND_STRING("NSLog(@\"\");"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        return false; break;
    }
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
