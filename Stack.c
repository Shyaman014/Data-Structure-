#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN
#define SIZE 100

// Create a stack with a capacity of 100 elements
int stack[SIZE];
// Initially, the stack is empty
int top = -1;

/* Function declarations for push and pop operations */
void push(int element);
int pop();

int main()
{
    int choice, data;

    while (1) {
        /* Menu */
        printf("------------------------------------\n");
        printf(" STACK IMPLEMENTATION PROGRAM \n");
        printf("------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Size\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to push into stack: ");
            scanf("%d", &data);
            // Push element to stack
            push(data);
            break;

        case 2:
            data = pop();
            // If stack is not empty
            if (data != INT_MIN)
                printf("Data => %d\n", data);
            break;

        case 3:
            printf("Stack size: %d\n", top + 1);
            break;

        case 4:
            printf("Exiting from the application.\n");
            exit(0);

        default:
            printf("Invalid choice, please try again.\n");
        }

        printf("\n\n");
    }

    return 0;
}

/**
 * Function to push a new element onto the stack.
 */
void push(int element)
{
    // Check for stack overflow
    if (top >= SIZE - 1) {
        printf("Stack Overflow, can't add more elements to stack.\n");
        return;
    }

    // Increase element count in the stack
    top++;
    // Push element onto the stack
    stack[top] = element;
    printf("Data pushed to stack.\n");
}

/**
 * Function to pop an element from the top of the stack.
 */
int pop()
{
    // Check for stack underflow
    if (top < 0) {
        printf("Stack is empty.\n");
        // Return minimum integer value as error value
        return INT_MIN;
    }

    // Return the top element and decrease element count
    return stack[top--];
}
