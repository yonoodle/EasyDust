EasyDust.h


This Library is for SHARP gp2y1010 and gp2y1014 dust sensor.

Designed to send pre-pulses and then do several reads to get average value to reduce noise , with the pre-pulses , correct value can be achived at any time no matter blocking code used or not.


yonoodle hsieh , yonoodle1@gmail.com , version 1  2017/06/10


KEYWORD

------------------
CONSTRUCTOR

    EasyDust


-------------------
METHODS


    get_RawAvg(uint8_t pre_pulse_num, uint8_t sample_num)


    get_ugm3(uint8_t pre_pulse_num, uint8_t sample_num)


-------------------