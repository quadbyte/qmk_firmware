/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#include "config.h"

enum layer_names {
    _QWERTY,
    _NAV_NUM,
    _SYMBOLS,
    _SYSTEM,
    _GAME,
};

#define LNAVNUM MO(_NAV_NUM)
#define LSYMBOL MO(_SYMBOLS)
#define LSYSTEM MO(_SYSTEM)

// #define LALT_ESC MT(MOD_LALT, KC_ESC)
// #define BSPC_LT3 LT(3,KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LALT,  KC_SPC,   LNAVNUM,  LSYMBOL, LSYSTEM
                                      //`--------------------------'  `--------------------------'

  ),


  [_NAV_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_PMNS,    KC_7,    KC_8,    KC_9, KC_PPLS,                      XXXXXXX, KC_HOME,   KC_UP,  KC_END, KC_PGUP, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_EQL,    KC_4,    KC_5,    KC_6, KC_PERC,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PSLS,    KC_1,    KC_2,    KC_3, KC_PAST,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_PDOT,  KC_EQL, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_0, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_MINS,  KC_EQL, KC_EXLM,   KC_AT, KC_LPRN,                      KC_RPRN, XXXXXXX, XXXXXXX, KC_PMNS, KC_PPLS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDS, KC_ASTR,  KC_DLR, KC_HASH, KC_LBRC,                      KC_RBRC, XXXXXXX, KC_AMPR, KC_CIRC, KC_PIPE,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PLUS,   KC_LT,   KC_GT, KC_PERC, KC_LCBR,                      KC_RCBR, KC_TILD, KC_COMM,  KC_DOT, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  [_SYSTEM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                  DF(_QWERTY), RGB_HUD, RGB_HUI,RGB_RMOD, RGB_MOD, RGB_TOG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                    DF(_GAME), KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
   ),

  [_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_T,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                      _______, _______,   KC_UP, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|1828
         KC_G, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_B, KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
   ),
};



// Light LEDs when keyboard layer is active
const rgblight_segment_t PROGMEM my_navnum_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 9, HSV_CYAN},
    {18, 1, HSV_CYAN},
    {21+7, 1, HSV_CYAN},
    {21+10, 2, HSV_CYAN},
    {21+13, 1, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_navnum_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _NAV_NUM));
    return state;
}
