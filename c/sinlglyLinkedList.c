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

void insert(int data,int key)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    temp->data = data;
    while(ptr->data != key && ptr->link !=NULL)
    {
        ptr = ptr->link;
    }
    if(ptr->link==NULL && ptr->data != key)
    {
        printf("Search Failed,Try Again\n");
    }
    else
    {
        temp->link = ptr->link;
        ptr->link = temp;
    }
}

void deleteF()
{
    if(head == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        head = head->link;
    }
}

void deleteR()
{
    struct node *current = head;
    struct node *previous = head;
    while(current->link != NULL)
    {
        previous = current;
        current = current->link;
    }
    previous->link = NULL;
}

void delete(int key)
{
    struct node *current = head;
    struct node *previous;
    if(current != NULL && current->data == key)
    {
        head = current->link;
    }
    while(current->link != NULL && current->data != key)
    {
        previous = current;
        current = current->link;
    }
    if(current == NULL)
    {
        printf("Canot Delete, Try Again");
    }
    else
    {
        previous->link = current->link;
    }
}

void main()
{
    int x,s=0,data,key;
    while(s != 3)
    {
        printf("Enter: 1.Insert\t 2.Delete\t 3.Exit\t:");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Insert :\t 1.At Front \t 2.At End \t 3.Using Key\t:");
                scanf("%d",&x);
                printf("Enter the data:");
                scanf("%d",&data);
                switch(x)
                {
                    case 1:
                        insertF(data);
                        traversal();
                        break;
                    case 2:
                        insertR(data);
                        traversal();
                        break;
                    case 3:
                        printf("Enter the Key:");
                        scanf("%d",&key);
                        insert(data,key);
                        traversal();
                        break;
                    default:
                        printf("Invalid\n");
                }
                break;
            case 2:
                printf("Delete :\t 1.At Front \t 2.At End \t 3.Using Key\t:");
                scanf("%d",&x);
                switch(x)
                {
                    case 1:
                        deleteF();
                        traversal();
                        break;
                    case 2:
                        deleteR();
                        traversal();
                        break;
                    case 3:
                        printf("Enter the Key:");
                        scanf("%d",&key);
                        delete(key);
                        traversal();
                        break;
                    default:
                        printf("Invalid\n");
                }
                break;
            case 3:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid\n");
        }
    }
}
