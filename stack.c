#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;


void push()
{
    int item;
    if (top == MAX - 1)
    {
        printf("\nStack Overflow! Cannot push element.\n");
    }
    else
    {
        printf("Enter element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("%d pushed onto stack.\n", item);
    }
}


void pop()
{
    if (top == -1)
        {
        printf("\nStack Underflow! No element to pop.\n");
    }
    else
        {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}


void display()
{
    if (top == -1)
        {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


int main()
{
    int choice;
    while (1)
        {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}
