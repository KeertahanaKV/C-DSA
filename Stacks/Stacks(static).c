#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
int stack[MAX_SIZE];
int top = -1;
void push() {
 if (top == MAX_SIZE - 1)
 printf("Stack Overflow\n");
 else {
 int value;
 printf("Enter the value to push: ");
 scanf("%d",&value);
 stack[++top] = value;
 }
}
int pop() {
 if (top == -1) {
 printf("Stack Underflow\n");
 return -1;
 }
 else {
 int popped = stack[top--];
 return popped;
 }
}
void display() {
 if (top == -1)
 printf("Stack is empty\n");
 else {
 printf("Stack elements: ");
 for (int i = 0; i <=top; i++) {
 printf("%d ", stack[i]);
 }
 printf("\n");
 }
}
void stacktop() {
 if (top == -1)
 printf("Stack is empty\n");
 else
 printf("Top element of stack: %d\n", stack[top]);
}
int main() {
 int choice, value;
 while (1) {
 printf("\nStack Operations:\n");
 printf("1. Push \n");
 printf("2. Pop \n");
 printf("3. Peek\n");
 printf("4. Display \n");
 printf("99. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1: push();
 break;
 case 2: printf("Popped element: %d\n", pop());
 break;
 case 3: stacktop();
 break;
 case 4: display();
 break;
 case 99: printf("Exiting program\n");
 exit(0);
 default: printf("Invalid choice\n");
 }
 }
 return 0;
}
