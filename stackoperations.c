#include <stdio.h>
#include <stdlib.h>
#define MAX 5  

int stack[MAX];
int top = -1;
void push();
void pop();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n STACK OPERATIONS MENU \n");
        printf("1. Push\n");
        printf("2. Pop \n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    return 0;
}

void push() {
    int value;
    if (top == MAX - 1) {
        printf("Error: Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Successfully pushed %d onto the stack.\n", value);
    }
}

void pop() {
        if (top == -1) {
        printf("Error: Stack Underflow! The stack is already empty.\n");
    } else {
        printf("Successfully popped %d from the stack.\n", stack[top]);
        top--;
    }
}

void display() {
  
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Current Stack elements (Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf(" %d \n", stack[i]);
        }
    }
}
