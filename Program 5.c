#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void createList()
{
    head = NULL;
    printf("Linked list created successfully.\n");
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted first element: %d\n", temp->data);
    free(temp);
}

void deleteElement(int value)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head->data == value)
    {
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element %d not found.\n", value);
    } else
    {
        prev->next = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = head;

    if (head->next == NULL)
    {
        printf("Deleted last element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next->next != NULL)
     {
        temp = temp->next;
    }

    printf("Deleted last element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL)
     {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value;

    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = NULL;
    head = n1;

    while (1)
     {
        printf("\n---- MENU ----\n");
        printf("1. Create Linked List\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specific Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createList();
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteElement(value);
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
