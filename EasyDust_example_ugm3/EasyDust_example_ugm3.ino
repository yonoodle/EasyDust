/* 
 EasyDust.h  example


This Library is for SHARP gp2y1010 and gp2y1014 dust sensor.

for sending pre-pulses to get correct Sensor Led current and then get avg of several reads , make blocking codes possible to acheive.


yonoodle hsieh , yonoodle1@gmail.com , version 1  2017/06/10

  MIT License



KEYWORD

------------------
CONSTRUCTOR

    EasyDust


-------------------
METHODS


    get_RawAvg(uint8_t pre_pulse_num, uint8_t sample_num)


    get_ugm3(uint8_t pre_pulse_num, uint8_t sample_num)


-------------------

*/





#include "EasyDust.h"

EasyDust mysensor(3,7); // mysensor(LED_pulse_pin,analogRead_pin)



void setup()
{

Serial.begin(9600);

}
void loop()
{


/*
 * get_RawAvg(uint8_t pre_pulse_num , uint8_t sample_num)
 * 
 * pre send 5 pulse and read 10 times to get avg , get a nice result.
 * 
 * time spent = ( pre_pulse_num + sample_num )*10ms = 150 ms 
 * 
 */



// get dust density in ug/m3  ,about 0~500 ug/m3 , showing 0 for below measure range, 9999 for exceed measure range.


Serial.println(mysensor.get_ugm3(10,10));
delay(100);  

Serial.println(mysensor.get_ugm3(5,5));
delay(500);

Serial.println(mysensor.get_ugm3(5,10));
delay(1000);




}
