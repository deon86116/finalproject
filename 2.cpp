// #include "mbed.h"
// #include "bbcar.h"

// Serial pc(USBTX, USBRX);
// Ticker servo_ticker;
// DigitalOut red_led(LED1);
// Ticker encoder_ticker;
// PwmOut pin9(D9), pin8(D8);
// BBCar car(pin8, pin9, servo_ticker);
// Serial uart(D1, D0);
// EventQueue xbee_queue;
// Serial xbee(D12, D11);
// Timer t;
// DigitalInOut pin10(D10);
// int task = 0;
// void XbeeFunction()
// {
//     xbee.baud(9600);
//     while(true) {
//         if(task == 0) {
//             xbee.printf("on the way to mission1\r\n");
//         }
//         else if(task == 1) {
//             xbee.printf("in mission1\r\n");
//         }
//         else if(task == 2) {
//             xbee.printf("on the way to mission2\r\n");
//         }
//         else if(task == 3) {
//             xbee.printf("in mission2\r\n");
//         }
//         else if(task == 4) {
//             xbee.printf("on the way to exit\r\n");
//         }
//         pc.printf("test\r\n");
//         wait(1.);
//     }
// }
// void PingFunction()
// {
//     pc.baud(9600);
//     int tmp;
//     parallax_ping  ping(pin10);
//     float val = (float) ping;
//     if(val > 0) {
//         xbee.printf("This is square\r\n");
//     }
//     else if(val > 5) {
//         xbee.printf("This is mountain\r\n", tmp);
//     }
//     else if(val > 10) {
//         xbee.printf("This is hole\r\n", tmp);
//     }
//     else if(val > 15) {
//         xbee.printf("This is slope\r\n", tmp);
//     }
// }
// void ClassifyImage()
// {
//     uart.baud(9600);
//     char s[21];
//     sprintf(s,"image_classification");
//     uart.puts(s);
//     pc.printf("QQ\r\n");
// }
// int main() {
//     red_led = 0;
//     Thread xbee_thread;
//     xbee_thread.start(callback(&xbee_queue, &EventQueue::dispatch_forever));
//     xbee_queue.call(XbeeFunction);
    
    

//     car.goStraight(-300);
//     wait(8);
//     car.stop();
//     wait(0.5);
//     task++;
// // mission 1 
//     // turn front left
//     car.turn(-30, -0.01);
//     wait(2.4);
//     car.stop();
//     wait(0.5);

//     car.goStraight(-300);
//     wait(3.3);
//     car.stop();
//     wait(0.5);

//     // turn front right
//     car.turn(-30, 0.01);
//     wait(2.5);
//     car.stop();
//     wait(0.5);

//     ClassifyImage();
//     wait(4);

//     // turn back right
//     car.turn(30, 0.01);
//     wait(3.);
//     car.stop();
//     wait(0.5);

//     car.goStraight(-300);
//     wait(1.2);
//     car.stop();
//     wait(0.5);

//     // turn front right
//     car.turn(-30, 0.01);
//     wait(3.);
//     car.stop();
//     wait(0.5);

//     car.goStraight(300);
//     wait(2.3);
//     car.stop();
//     wait(0.5);
//     // park done
//     wait(2.5);
    
//     car.goStraight(-300);
//     wait(2.6);
//     car.stop();
//     wait(0.5);

//     // turn front right
//     car.turn(-30, 0.01);
//     wait(3.);
//     car.stop();
//     wait(0.5);

//     car.goStraight(-300);
//     wait(3.);
//     car.stop();
//     wait(0.5);

//     // turn front right
//     car.turn(-30, 0.01);
//     wait(3.);
//     car.stop();
//     wait(0.5);
//     task++;
//     // exit mission 1

//     car.goStraight(-300);
//     wait(7.5);
//     car.stop();
//     wait(1.5);
//     task++;
// //mission 2 
//     car.turn(-30, 0.01);
//     wait(3.);
//     car.stop();
//     wait(0.5);

//     car.goStraight(-300);
//     wait(4.);
//     car.stop();
//     wait(0.5);

//     car.turn(-30, 0.01);
//     wait(3.);
//     car.stop();
//     wait(2);
//     // watch obstable
    
//     car.turn(-30, 0.01);
//     wait(1.5);
//     car.stop();
//     wait(0.5);

//     car.turn(30, 0.01);
//     wait(1.5);
//     car.stop();
//     wait(0.5);

//     car.turn(-30, -0.01);
//     wait(1.5);
//     car.stop();
//     wait(0.5);

//     car.turn(30, -0.01);
//     wait(1.5);
//     car.stop();
//     wait(0.5);
  

//     PingFunction();
//     wait(2);
    
//     //turn back right
//     car.turn(30, 0.01);
//     wait(2.);
//     car.stop();
//     wait(0.5);

//     car.goStraight(-300);
//     wait(2.5);
//     car.stop();
//     wait(1.5);

//     // turn front right
//     car.turn(-30, 0.01);
//     wait(3.);
//     car.stop();
//     wait(0.5);
//     task++;

//     car.goStraight(-300);
//     wait(8);
//     car.stop();
//     wait(0.5);

//     // -- front left
//     // -+ front right
//     // +- back left
//     // ++ back right
//     // 21cm 1s
// }