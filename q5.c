#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    return newnode;
}
void enqueue(int data)
{
    struct node *newnode = createnode(data);
    if (front == NULL && rear == NULL)
    {
        newnode->next = NULL;
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue()
{
    if (front == NULL && rear == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void peek()
{
    printf("%d", front->data);
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();

    display();

    peek();
}