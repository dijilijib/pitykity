#include "pitykity.h"

void setup() {
    Serial.begin(115200);
    thingsboard_setup();
    led_pin_setup();
    connecting_wifi();
    ditance_sensor_setup();
    //set_buzzer();
    step_set();
    set_web_server();
    set_eprom();
}

void loop() {
    get_time_c();
    led_distance(ditance_sensor_get());
    // use_buzzer();
    get_web_server();
    get_eprom();
    thingsboard_loop();
    delay(1000);
}
