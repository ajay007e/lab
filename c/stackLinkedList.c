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
    temp->data=data;
    temp->link=head;
    head=temp;
    traversal();
}

void pop()
{
    if(head == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        head = head->link;
    }
    traversal();
}

int isEmpty()
{
    if(head == NULL)
        return 1;
    else
        return 0;
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
            case 4:
                printf("%d\n",isEmpty());
                break;
            default:
                printf("Invalid\n");
        }
    }
}
