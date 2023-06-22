#include "pitykity.h"

void setup_buzzer()
{
    pinMode(PIN_BUZZER, OUTPUT);
}

void use_buzzer()
{
    int z;

    z = 0;
    if (z)
        digitalWrite(PIN_BUZZER, HIGH);
    else 
        digitalWrite(PIN_BUZZER, LOW);
}
