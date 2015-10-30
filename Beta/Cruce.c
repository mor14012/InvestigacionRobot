#include "simpletools.h"                      // Include simpletools header
#include "abdrive.h"                          // Include abdrive header
#include "ping.h"                             // Include ping header  
#include <stdio.h>
#define capacity 100

struct Stack{
	int top;	
	int data[capacity];
} stack;

void push(int value){
	stack.top++;
	stack.data[stack.top] = value;
}

int pop(){
	int value;
	value = stack.data[stack.top];
	stack.top--;
	return (value);
}

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
  push(1);
  drive_ramp(0, 0);
  
  freqout(11, 1, 38000);                      // Check left & right objects
  irLeft = input(10);

  freqout(1, 1, 38000);
  irRight = input(2);
  
  
  if(irRight == 0 && irLeft == 0){          // Obstaculos 
   drive_goto(59,-49);
   push(4);
  }
  
  else if(irRight == 0) {                   // Just right obstacle?
    drive_goto(-24,28);                // ...rotate left
	push(3);
  }
  else if(irLeft == 0)   {                     // Just left obstacle?
    drive_goto(30, -26);                // ...rotate right
	  push(2);
 }
  else if (irLeft == 1 && irRight == 1){
    drive_goto(30,-26);
	push(5);
  }
}  
 
}
