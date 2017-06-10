
#include "Arduino.h"
#include "EasyDust.h"


/*
  This Library is for gp2y1014 dust sensor.

  yonoodle hsieh , yonoodle1@gmail.com , version 1  2017/06/10   MIT License


 */

EasyDust::EasyDust(uint8_t LED_pulse_pin, uint8_t analogRead_pin)
{
 
  this->_LED_pulse_pin = LED_pulse_pin ;
  this->_analogRead_pin = analogRead_pin;

  pinMode(_LED_pulse_pin, OUTPUT);  
  digitalWrite(_LED_pulse_pin, HIGH);
}





int EasyDust::get_RawAvg(uint8_t pre_pulse_num, uint8_t sample_num)
{ 

  _value = 0;


// send pre pulses
  for (int i=0 ; i<pre_pulse_num ; i++)
    {
      digitalWrite(_LED_pulse_pin, LOW);  //start pulse
      delayMicroseconds(320); // wait til 320us as suggested.
      digitalWrite(_LED_pulse_pin, HIGH); // pulse done
      delayMicroseconds(9680);  // wait til 10ms as suggested. (10000-320)
    }


  for (int i=0 ; i<sample_num ; i++)
    {
      digitalWrite(_LED_pulse_pin, LOW);  //start pulse
      delayMicroseconds(280);
      _value += analogRead(_analogRead_pin);  // read at 280us as suggested. 100us is needed for analogRead
      delayMicroseconds(40);  // wait til 320us as suggested.
      digitalWrite(_LED_pulse_pin, HIGH); // pulse done
      delayMicroseconds(9580);  // wait til 10ms as suggested. (10000-280-100-40)
    }

    _value = _value/sample_num;
    
    return _value;
}


int EasyDust::get_ugm3(uint8_t pre_pulse_num, uint8_t sample_num)
{ 

       _value = get_RawAvg(pre_pulse_num,sample_num);

      _value = map(_value,90,700,0,450); // re-map according to chart given in manual
      
      if(_value<0){_value=0;}  // below measure range
      if(_value>450){_value = 9999;}  //exceed measure range

      return _value;
}



