#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head =NULL;

void display()
{
    struct node *ptr = head;
    while(ptr !=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
}

void insertF(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=head;
    head=temp;
}

void insertR(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    temp->data = data;
    if(head==NULL)
    {
        temp->link=NULL;
        head = temp;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
        temp->link =NULL;
    }
}

void reverse(struct node** Rptr)
{
    struct node* prev = NULL;
    struct node* current =*Rptr;
    struct node* next;
    while(current !=NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *Rptr = prev;
}

void main()
{
    insertR(10);
    insertR(20);
    insertR(30);
    insertR(40);
    insertR(50);
    printf("Linked List:");
    display();
    printf("\n");
    printf("Reversed Linked List:");
    reverse(&head);
    display();
}
