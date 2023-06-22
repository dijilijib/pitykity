#include "pitykity.h"

int saat11;
int dakika11;
int saat21;
int dakika21;

// CONSTRUCTOR 
eprom::eprom(uint8_t address) {
      EEPROM.begin(255); // 255 bit alan ayırmaya yariyor
      _address = address;
}
// 
void eprom::setup()
{
      delay(20);
}

// zaman 1 yazmaya yarar
void eprom::time1(uint8_t hours, uint8_t minutes) 
{
  //  ilk zaman
  EEPROM.write(_address, hours);
  EEPROM.write(_address + 1, minutes);
  EEPROM.commit();
}
// zaman 2 yazmaya yarar
void eprom::time2(uint8_t hours, uint8_t minutes) 
{
  //  ikinci zaman
  EEPROM.write(_address+2, hours);
  EEPROM.write(_address+3, minutes);
  EEPROM.commit();
}

 // Kontroller
void eprom::kontroller(bool kontrol1, bool kontrol2) {
  EEPROM.write(_address+4, kontrol1);
  EEPROM.write(_address+5, kontrol2);
  EEPROM.commit();  
}

 // mama miktarı
void eprom::mamaMiktari(uint8_t miktar) {
  EEPROM.write(_address+6, miktar);
  EEPROM.commit();  
} 

// zamanı okumak için

int eprom::Saat1() {
  return EEPROM.read(_address);
}

int eprom::Dakika1() {
  return EEPROM.read(_address+1);
}

int eprom::Saat2() {
  return EEPROM.read(_address+2);
}

int eprom::Dakika2() {
  return EEPROM.read(_address+3);
}

bool eprom::Kontrol1(){
  return EEPROM.read(_address+4);
}

bool eprom::Kontrol2(){
  return EEPROM.read(_address+5);
}

int eprom::Mama() {
  return EEPROM.read(_address+6);
}

// KULLANIM
///////////
/* : SETUP
    eprom zaman(3); // EEPROM hafızada 3. alana yazmaya başlar
    zaman.setup();
////////////
  : LOOP
    zaman.time1(11, 26);
    zaman.time2(23, 44);
    saat1 = zaman.Saat1();
    dakika1 = zaman.Dakika1();
    saat2 = zaman.Saat2();
    dakika2 = zaman.Dakika2();
    test = zaman.Test();
    delay(2000);
    Serial.println(saat1);
    Serial.println(dakika1);
    Serial.println(saat2);
    Serial.println(dakika2);
    //Serial.println(test);
    delay(2000);
*/

void get_eprom()
{
    zaman.time1(11, 26);
    zaman.time2(23, 44);

    saat1 = zaman.Saat1();
    dakika1 = zaman.Dakika1();
    saat2 = zaman.Saat2();
    dakika2 = zaman.Dakika2();
    test = zaman.Test();

    delay(2000);
    Serial.println(saat1);
    Serial.println(dakika1);
    Serial.println(saat2);
    Serial.println(dakika2);
    //Serial.println(test);
    delay(2000);
}

void set_eprom()
{
    eprom zaman(3);
    zaman.setup();
}
