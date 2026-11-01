#include <stdio.h>
#include <stdlib.h>

#define MAX 5 


int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int element);
void dequeue();
void display();

int main() {
    int choice, element;

    while (1) {
        printf("\nCIRCULAR QUEUE OPERATION ");
        printf("\n1. Insert Element (Enqueue)");
        printf("\n2. Delete Element (Dequeue)");
        printf("\n3. Display Queue Elements");
        printf("\n4. Exit Program");
        printf("\n");
        printf("\nEnter choice selection (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer element value to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Terminating execution loop safely.\n");
                exit(0);

            default:
                printf("Invalid selection, Select options between 1 and 4.\n");
        }
    }
    return 0;
}

void enqueue(int element) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow. Cannot insert %d.\n", element);
        return;
    }
    
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    
    queue[rear] = element;
    printf("Value %d inserted.\n", element);
}

void dequeue() {
    if (front == -1) {
        printf(" Queue Underflow detected.\n");
        return;
    }

    printf(" Removed element [%d] from head pointer.\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}


void display() {
    if (front == -1) {
        printf(" Current queue contains zero items\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break; 
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}