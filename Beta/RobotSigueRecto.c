/*
  Follow with Ping.c

  Maintain a constant distance between ActivityBot and object.

  http://learn.parallax.com/activitybot/follow-objects-ultrasound
*/

#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header  

int distance, setPoint, errorVal, kp, speed;  // Navigation variables
int irLeft, irRight;                            // IR variables
int turn;
int setPoint;


int main()
{  
  setPoint = 10;
  low(26);                                      // D/A0 & D/A1 to 0 V
  low(27);
 
  drive_setRampStep(10);                      // 10 ticks/sec / 20 ms

   while (1){
  drive_ramp(64, 64);                       // Forward 2 RPS
  
  
  while(ping_cm(8) >= 10) pause(5); 
  
  drive_ramp(0, 0);
  
  freqout(11, 1, 38000);                      // Check left & right objects
  irLeft = input(10);

  freqout(1, 1, 38000);
  irRight = input(2);
  
  
  if(irRight == 0 && irLeft == 0)             // Obstaculos 
   drive_goto(59,-49);
  else if(irRight == 0)                       // Just right obstacle?
    drive_goto(-24,28);                // ...rotate left
  else if(irLeft == 0)                        // Just left obstacle?
    drive_goto(30, -26);                // ...rotate right
  else if (irLeft == 1 && irRight == 1)
    drive_goto(30,-26);
}  
 
}
