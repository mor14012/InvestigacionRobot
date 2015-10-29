

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

  // Navigation variables
int irLeft, irRight;                            // IR variables



int main()
{  

  low(26);                                      // D/A0 & D/A1 to 0 V
  low(27);
  drive_setRampStep(10); 
  
  while(1)
  {
    drive_ramp(55, 55); 
    
    
    freqout(11, 1, 38000);                      // Check left & right objects
    irLeft = input(10);

    freqout(1, 1, 38000);
    irRight = input(2);
   
      
    
    if (irLeft == 1 && irRight == 1 && ping_cm(8)==8){ 
      drive_goto(30,-26);
      push(5);
    }    
    if(irLeft == 0 && irRight==1) {   
      drive_goto(21,21);   
      push(2);  
      pause(200);               
      drive_goto(30, -26); 
    }        
   if(irRight == 0 && irLeft==1){
      drive_goto(21,21);       
      push(3);
      pause(200);                
      drive_goto(-24, 28);   
    }                 
    
   if (irLeft == 0 && irRight == 0 && ping_cm(8)<=10){
      drive_goto(59,-49);
      push(4); 
    }    
      
  }    
}

