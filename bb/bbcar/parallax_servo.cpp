#include "parallax_servo.h"

parallax_servo::parallax_servo (PwmOut& pin) {
    pin.period(0.02);
    pwm = &pin;
    factor = 1;
    pwm_value = 0;
}

void parallax_servo::set_speed( double value ){
    pwm_value = value;
}

void parallax_servo::set_factor( double value ){
    factor = value;
}

void parallax_servo::control(){
    double value = factor * pwm_value;

    if (value > 200) value = 200;
    else if (value < -200) value = -200;
    
    pwm->write((CENTER_BASE + value) / 20000);
}

void parallax_servo::set_calib_table( int len, double pwm_calib_table[], double speed_calib_table[] ) {
    table_len = len;
    pwm_table = pwm_calib_table;
    speed_table = speed_calib_table;
}

// input value is speed : cm/s
void parallax_servo::set_speed_by_cm( double value ){
    int i;
    double pwm_diff;
    double speed_diff;

    for (i=0; i<table_len; i++) {
        // values of speed table should be stored from small to large
        if (value < speed_table[i]) {
            // if less then table, take smallest value
            if (i==0) {
                pwm_value = pwm_table[0];
                return;
            }
            // interpolation
            pwm_diff = pwm_table[i] - pwm_table[i-1];
            speed_diff = speed_table[i] - speed_table[i-1];
            pwm_value = pwm_table[i-1] + pwm_diff * ((value-speed_table[i-1])/speed_diff);
            return;
        }
    }
    // if exceed the table, take largest value
    pwm_value = pwm_table[table_len-1];
}
