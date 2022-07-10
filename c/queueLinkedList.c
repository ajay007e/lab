#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head =NULL;

void traversal()
{
    struct node *ptr = head;
    while(ptr !=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void push(int data)
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
    traversal();
}

void pop()
{
    if(head == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        head = head->link;
    }
    traversal();
}

void main()
{
    int s=0,x;
    while(s !=3)
    {
        printf("Enter:1.Add Element\t2.Delete Element\t3.Exit\t:");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Enter the number to insert:");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid\n");
        }
    }
}
