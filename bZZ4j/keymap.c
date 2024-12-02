#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_B,           KC_L,           KC_D,           KC_C,           KC_V,                                           KC_P,           KC_F,           KC_O,           KC_U,           KC_COMMA,       KC_TRANSPARENT, 
    TO(2),          MT(MOD_LSFT, KC_N),MT(MOD_LCTL, KC_R),MT(MOD_LALT, KC_T),MT(MOD_LGUI, KC_S),KC_G,                                           KC_Y,           MT(MOD_RGUI, KC_H),MT(MOD_RALT, KC_A),MT(MOD_RCTL, KC_E),MT(MOD_LSFT, KC_I),KC_QUOTE,       
    KC_TRANSPARENT, KC_X,           KC_Z,           KC_M,           KC_W,           KC_J,                                           KC_Q,           KC_K,           KC_COMMA,       KC_SLASH,       KC_DOT,         KC_TRANSPARENT, 
                                                    LT(1,KC_SPACE), TO(2),                                          KC_ENTER,       LT(2,KC_BSPC)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,        KC_SLASH,       KC_RABK,        KC_AT,                                          KC_AMPR,        KC_DQUO,        KC_LBRC,        KC_RBRC,        KC_SCLN,        KC_F12,         
    KC_TRANSPARENT, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_HASH,                                        KC_PIPE,        KC_COLN,        KC_LPRN,        KC_RPRN,        KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_ASTR,        KC_PERC,        KC_TRANSPARENT,                                 KC_TILD,        KC_QUOTE,       KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       QK_LLCK,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, QK_DYNAMIC_TAPPING_TERM_PRINT,QK_DYNAMIC_TAPPING_TERM_UP,QK_DYNAMIC_TAPPING_TERM_DOWN,KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, TO(0),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_N):
            return g_tapping_term -15;
        case MT(MOD_LCTL, KC_R):
            return g_tapping_term -15;
        case MT(MOD_LALT, KC_T):
            return g_tapping_term -15;
        case MT(MOD_LGUI, KC_S):
            return g_tapping_term -15;
        case MT(MOD_RGUI, KC_H):
            return g_tapping_term -15;
        case MT(MOD_RALT, KC_A):
            return g_tapping_term -15;
        case MT(MOD_RCTL, KC_E):
            return g_tapping_term -15;
        case MT(MOD_LSFT, KC_I):
            return g_tapping_term -15;
        default:
            return g_tapping_term;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {205,189,255}, {205,189,255} },

    [1] = { {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {205,189,255}, {205,189,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}


