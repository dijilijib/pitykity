#include "pitykity.h"

void setup() {
    Serial.begin(115200);
    // Internet baglatisi wifi sifresi ve mevcut default
    // durumlar gecerlidir
    thingsboard_setup();
    led_pin_setup();
    ditance_sensor_setup();
    //set_buzzer();
    step_set();
    set_web_server();
    file_setup();
}

void loop() {
    // use_buzzer();
    // Mesafeye gore ledleri yakar ve sondurur
    led_distance(ditance_sensor_get());
    get_web_server();
    thingsboard_loop();
    delay(1000);
}
