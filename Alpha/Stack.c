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

int main(){
	printf("Hi\n");

	push(1);
	push (2);

	int number = pop();

	printf("The number is %d \n", number);

	number = pop();

	printf("The number is %d \n", number);
}

//http://www.c4learn.com/c-programs/c-program-to-implement-stack-operations-using-array.html