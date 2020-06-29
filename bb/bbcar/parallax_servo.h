#ifndef PARALLAX_SERVO_H
#define PARALLAX_SERVO_H
#include "mbed.h"

// #define CENTER_BASE 1500

class parallax_servo {
    public:
        parallax_servo(PwmOut& pin);

        void set_speed( double value );
        void set_factor( double value );
        void control();

        void set_calib_table( int len, double pwm_calib_table[], double speed_calib_table[] );
        void set_speed_by_cm( double value );

    // private:

        PwmOut *pwm;
        double factor;
        double pwm_value;

        // the calibration table
        int table_len = 0;
        double *pwm_table;
        double *speed_table;
        double CENTER_BASE;
};

#endif
