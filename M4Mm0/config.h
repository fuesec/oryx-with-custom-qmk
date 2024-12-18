/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2500

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 180000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 10

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 40

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 65

#define SERIAL_NUMBER "M4Mm0/gW0me"
#define LAYER_STATE_8BIT
#define HSS(report) host_system_send(record->event.pressed ? report : 0); return false

#define RGB_MATRIX_STARTUP_SPD 60

#define VOYAGER_USER_LEDS // disable default LED activation based on layer

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
