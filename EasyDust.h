/*

This Library is for SHARP gp2y1010 and gp2y1014 dust sensor.

yonoodle hsieh , yonoodle1@gmail.com , version 1  2017/06/10

  MIT License

*/




// ensure this library description is only included once

#ifndef EasyDust_h

#define EasyDust_h

// library interface description
class EasyDust {
  public:
    // constructors:

    EasyDust(uint8_t LED_pulse_pin, uint8_t analogRead_pin);  

    // methods

    int get_RawAvg(uint8_t pre_pulse_num, uint8_t sample_num);

    int get_ugm3(uint8_t pre_pulse_num, uint8_t sample_num);

  private:
       
    uint8_t _LED_pulse_pin;
    uint8_t _analogRead_pin;

    	int _value;

};

#endif

