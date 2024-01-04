#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;

struct node *createnode(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

struct node *insertatbig(int data)
{
    struct node *newnode = createnode(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

struct node *insertatend(int data)
{
    struct node *newnode = createnode(data);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

struct node *insertatposition(int data, int position)
{
    if (position == 1)
    {
        insertatbig(data);
        return;
    }
    struct node *newnode = createnode(data);
    struct node *temp = head;
    for (int i = 0; i < position - 2 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void delete_by_value(int value)
{
    struct node *current = head;
    while (current != NULL && current->data != value)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Value %d not found in the list\n", value);
        return;
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        head = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Value %d deleted from the list\n", value);
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insertatbig(10);
    insertatend(20);
    insertatend(30);
    insertatposition(12, 2);

    printf("Original List: ");
    display();

    delete_by_value(20);

    printf("List after deletion: ");
    display();

    return 0;
}