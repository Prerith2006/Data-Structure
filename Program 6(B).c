#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

void push(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d into Stack\n", x);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped %d from Stack\n", top->data);
    top = top->next;
    free(temp);
}

void displayStack()
{
    struct Node *temp = top;
    if (temp == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack Elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void enqueue(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    } else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into Queue\n", x);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued %d from Queue\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue()
{
    struct Node *temp = front;
    if (temp == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue Elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}
