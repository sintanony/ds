#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct node *push(int data) // insert at begining
{
    struct node *newnode = createnode(data);
    newnode->next = top;
    top = newnode;
    return top;
}
struct node *pop() // delete at begining
{
    if (top == NULL)
    {
        printf("stack is empty");
    }
    else
    {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
}
void display()
{
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int peek()
{
    return top->data;
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    pop();

    display();

    int a = peek();
    return 0;
}