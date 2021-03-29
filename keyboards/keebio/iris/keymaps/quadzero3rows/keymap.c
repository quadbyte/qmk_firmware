#include QMK_KEYBOARD_H
#include "rgb.c"

enum layer_names {
    _QWERTY,
    _NAV_NUM,
    _SYMBOLS,
    _SYSTEM,
};

#define L_NAVNUM MO(_NAV_NUM)
#define L_SYMBOL MO(_SYMBOLS)
#define L_SYSTEM MO(_SYSTEM)

#define LALT_ESC MT(MOD_LALT, KC_ESC)
#define BSPC_LT3 LT(3,KC_BSPC)


// clipboard
// #define PRT_CLIP LGUI(KC_INS) // print
// #define UPL_CLIP G(S(KC_INS)) // upload
// #define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
// #define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
// #define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
// #define KC_CPYP LCTL(KC_PSCREEN)  // Copy portion of screen
// #define KC_ESCC MT(MOD_LCTL, KC_ESC)
// #define KC_GRVF LT(_FKEYS, KC_GRV)
// #define KC_ENTS MT(MOD_LSFT, KC_ENT)
// #define CALTDEL LCTL(LALT(KC_DEL))
// #define TSKMGR LCTL(LSFT(KC_ESC))ee

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,          XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, KC_SPC,                    L_NAVNUM,L_SYMBOL,L_SYSTEM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

 [_NAV_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,                            KC_7,    KC_8,    KC_9,    KC_PMNS, KC_PPLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,                            KC_4,    KC_5,    KC_6,    KC_PSLS, KC_PAST, KC_PERC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PDOT, KC_EQL,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_0,    _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MINS, KC_EQL,  KC_EXLM, KC_AT,   KC_LPRN,                            KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_UNDS, KC_ASTR, KC_DLR,  KC_HASH, KC_LBRC,                            KC_RBRC, XXXXXXX, KC_AMPR, KC_CIRC, KC_PIPE, KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PLUS, KC_LT,   KC_GT,   KC_PERC, KC_LCBR, XXXXXXX,          XXXXXXX, KC_RCBR, KC_TILD, KC_COMM, KC_DOT,  KC_BSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYSTEM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              XXXXXXX, RGB_HUD, RGB_HUI, RGB_RMOD,RGB_MOD, RGB_TOG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             XXXXXXX, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};


void encoder_update_user(uint8_t index, bool clockwise) {
  if(IS_LAYER_ON(_SYMBOLS)) {
    if (index == 0) {
      if (clockwise) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
      } else {
        alt_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
      }
    }
  }
  else if(IS_LAYER_ON(_NAV_NUM)) {
    if (index == 0) {
      if (clockwise) {
        tap_code(KC_DOWN);
      }
      else {
        tap_code(KC_UP);
      }
    }
  }
  else {
    if (index == 0) {
      if (clockwise) {
        tap_code(KC_MS_WH_DOWN);
      }
      else {
        tap_code(KC_MS_WH_UP);
      }
    }
  }
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1250) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

// void keyboard_post_init_user(void) {
//   // Default RGB colors and animations
//   rgblight_sethsv_noeeprom_red();
//   rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//   switch (biton32(state)) {
//     case _QWERTY:
//       rgblight_sethsv_noeeprom_red();
//       rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
//       break;
//     case _NAV_NUM:
//       rgblight_sethsv_noeeprom_cyan();
//       rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
//       break;
//     case _SYMBOLS:
//       rgblight_sethsv_noeeprom_magenta();
//       rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
//       break;
//     default:
//       rgblight_sethsv_noeeprom_white();
//       rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
//       break;
//   }

//   return state;
// }

void suspend_power_down_user(void) {
  rgblight_disable();
}

void suspend_wakeup_init_user(void) {
  rgblight_enable();
}
