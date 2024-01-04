#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *insertatbig(struct node *head, int data)
{
    struct node *newnode = createnode(data);
    newnode->next = head;
    return newnode;
}

struct node *insertatend(struct node *head, int data)
{
    struct node *newnode = createnode(data);

    if (head == NULL)
    {
        return newnode;
    }

    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newnode;
    return head;
}

struct node *delete_by_value(struct node *head, int value)
{
    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL && current->data != value)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return head;
    }

    if (prev == NULL)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
    return head;
}

void displayList(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    head = insertatbig(head, 10);
    head = insertatbig(head, 20);
    head = insertatbig(head, 30);
    head = insertatend(head, 40);

    displayList(head);

    head = delete_by_value(head, 20);

    printf("After deletion:\n");
    displayList(head);

    return 0;
}
