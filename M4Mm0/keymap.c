#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  MAC_DND,
};



enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_NO,          
    KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,        
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_ENTER,       
    KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RIGHT_SHIFT, 
                                                    KC_LEFT_GUI,    MO(2),                                          MO(3),          KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    TD(DANCE_0),    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_LEFT_CTRL,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_HOME,        KC_END,         KC_NO,                                          KC_NO,          LGUI(KC_LBRC),  LGUI(KC_RBRC),  KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_HYPR),                                  KC_NO,          KC_LEFT,        KC_RIGHT,       KC_DOWN,        KC_UP,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          OSM(MOD_MEH),   KC_NO,                                          KC_NO,          LGUI(LSFT(KC_LBRC)),LGUI(LSFT(KC_RBRC)),KC_PGDN,        KC_PAGE_UP,     KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 MO(4),          KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_GRAVE,       KC_LBRC,        KC_LCBR,        KC_LPRN,        KC_NO,                                          KC_NO,          KC_RPRN,        KC_RCBR,        KC_RBRC,        KC_TILD,        KC_F11,         
    KC_TRANSPARENT, KC_DQUO,        KC_EXLM,        KC_EQUAL,       KC_MINUS,       KC_NO,                                          OSM(MOD_HYPR),  OSM(MOD_RGUI),  OSM(MOD_RALT),  OSM(MOD_RSFT),  OSM(MOD_RCTL),  KC_F12,         
    KC_TRANSPARENT, KC_QUOTE,       KC_AT,          KC_PLUS,        KC_UNDS,        KC_NO,                                          KC_NO,          OSM(MOD_MEH),   KC_AMPR,        KC_PIPE,        KC_BSLS,        KC_F13,         
                                                    KC_TRANSPARENT, MO(4),                                          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    TO(1),          LCTL(LSFT(KC_MEDIA_EJECT)),MAC_DND,        LALT(LGUI(KC_MEDIA_EJECT)),LGUI(LCTL(KC_Q)),LGUI(LSFT(KC_3)),                                KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_BOOT,        
    KC_NO,          KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,LGUI(LSFT(KC_4)),                                KC_NO,          KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_MS_WH_RIGHT, KC_MS_ACCEL0,   
    KC_NO,          KC_NO,          KC_NO,          KC_MS_BTN2,     KC_MS_BTN1,     KC_NO,                                          KC_NO,          KC_MS_LEFT,     KC_MS_RIGHT,    KC_MS_DOWN,     KC_MS_UP,       KC_MS_ACCEL1,   
    KC_NO,          KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,                                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_ACCEL2,   
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255}, {225,255,255} },

    [1] = { {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255}, {122,252,255} },

    [2] = { {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255}, {169,254,255} },

    [3] = { {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252}, {81,239,252} },

    [4] = { {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239}, {0,248,239} },

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
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
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
    case MAC_DND:
      HSS(0x9B);

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


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP: layer_move(0); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
};


// customization
const key_override_t delete_key_override =
    ko_make_basic(MOD_MASK_CSAG, KC_BSPC, KC_DEL);

const key_override_t *key_overrides_list[] = {
    &delete_key_override,
    NULL
};

const key_override_t **key_overrides = (const key_override_t **)key_overrides_list;