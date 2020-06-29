#include "bbcar.h"

BBCar::BBCar( PwmOut &pin_servo0, PwmOut &pin_servo1, Ticker &servo_ticker ):servo0(pin_servo0), servo1(pin_servo1){
    servo0.set_speed(0);
    servo1.set_speed(0);
    servo0.CENTER_BASE = 1495;
    servo1.CENTER_BASE = 1500;
    servo_ticker.attach(callback(this, &BBCar::controlWheel), 0.5);
}

void BBCar::controlWheel(){
    servo0.control();
    servo1.control();
}

void BBCar::stop(){
    servo0.set_speed(0);
    servo1.set_speed(0);
    servo0.set_factor(1);
    servo1.set_factor(1);
}

void BBCar::goStraight( double speed ){
    servo0.set_speed(speed);
    servo1.set_speed(-speed);
}

void BBCar::setCalibTable( int len0, double pwm_table0[], double speed_table0[], int len1, double pwm_table1[], double speed_table1[] ){
    servo0.set_calib_table(len0, pwm_table0, speed_table0);
    servo1.set_calib_table(len1, pwm_table1, speed_table1);
}
void BBCar::goStraightCalib ( double speed ){
    servo0.set_speed_by_cm(speed);
    servo1.set_speed_by_cm(-speed);
}

/*	speed : speed value of servo
    factor: control the speed value with 0~1
            control left/right turn with +/-
*/
void BBCar::turn( double speed, double factor ){
    servo0.set_speed(speed);
    servo1.set_speed(-speed);
    if(factor>0){
        servo0.set_factor(factor);
        servo1.set_factor(1);
    }
    else if(factor<0){
        servo0.set_factor(1);
        servo1.set_factor(-factor);
    }
}

float BBCar::clamp( float value, float max, float min ){
    if (value > max) return max;
    else if (value < min) return min;
    else return value;
}

int BBCar::turn2speed( float turn ){
    return 25+abs(25*turn);
}


