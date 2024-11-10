#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_B,           KC_L,           KC_D,           KC_C,           KC_V,                                           KC_P,           KC_F,           KC_O,           KC_U,           KC_COMMA,       KC_TRANSPARENT, 
    TD(DANCE_0),    MT(MOD_LSFT, KC_N),MT(MOD_LCTL, KC_R),MT(MOD_LALT, KC_T),MT(MOD_LGUI, KC_S),KC_G,                                           KC_Y,           MT(MOD_RGUI, KC_H),MT(MOD_RALT, KC_A),MT(MOD_RCTL, KC_E),MT(MOD_RSFT, KC_I),KC_QUOTE,       
    KC_TRANSPARENT, KC_X,           KC_Z,           KC_M,           KC_W,           KC_J,                                           KC_Q,           KC_K,           KC_COMMA,       KC_SLASH,       KC_DOT,         KC_TRANSPARENT, 
                                                    LT(1,KC_SPACE), KC_TAB,                                         KC_ENTER,       LT(2,KC_BSPC)
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_N):
            return TAPPING_TERM -15;
        case MT(MOD_LCTL, KC_R):
            return TAPPING_TERM -15;
        case MT(MOD_LALT, KC_T):
            return TAPPING_TERM -15;
        case MT(MOD_LGUI, KC_S):
            return TAPPING_TERM -15;
        case MT(MOD_RGUI, KC_H):
            return TAPPING_TERM -15;
        case MT(MOD_RALT, KC_A):
            return TAPPING_TERM -15;
        case MT(MOD_RCTL, KC_E):
            return TAPPING_TERM -15;
        case MT(MOD_RSFT, KC_I):
            return TAPPING_TERM -15;
        default:
            return TAPPING_TERM;
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
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
        tap_code16(KC_TAB);
    }
    if(state->count > 3) {
        tap_code16(KC_TAB);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_TAB); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_TAB); register_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_TAB); register_code16(KC_TAB);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_TAB); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_TAB); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};
