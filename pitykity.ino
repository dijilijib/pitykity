#include "pitykity.h"

void setup() {
    Serial.begin(115200);
    // Led setup
    //led_pin_setup();
    // wifi setup
    connecting_wifi();
    // uzaklik sensoru setup
    ///ditance_sensor_setup();
    //set_buzzer();
    //step_set();
    set_web_server();
}

void loop() {
    // saati cekmek icin
    // connect_wifi.h 
    // get_time_c();
    // uzaklik senseru
    // led_distance(ditance_sensor_get());
    // use_buzzer();
    get_web_server();
    delay(1000);
}
