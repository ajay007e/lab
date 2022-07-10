#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

struct node *head =NULL;

void traversal()
{
    struct node *ptr = head;
    while(ptr !=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->rlink;
    }
    printf("\n");
}

void insertF(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp != NULL)
    {
        temp->data = data;
        temp->rlink = head;
        head = temp;
    }
}

void insertR(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    temp->data = data;
    if(head==NULL)
    {
        temp->llink=NULL;
        temp->rlink=NULL;
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->rlink!=NULL)
        {
            ptr = ptr->rlink;
        }
        ptr->rlink = temp;
        temp->llink =ptr;
    }
}

void insert(int data,int key)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr=head;
    temp->data = data;
    while(ptr->rlink !=NULL && ptr->data != key )
    {
        ptr = ptr->rlink;
    }
    if(ptr->rlink==NULL && ptr->data != key)
    {
        printf("Search Failed,Try Again\n");
    }
    else if (ptr->rlink == NULL && ptr->data == key)
    {
        insertR(data);
    }
    else
    {
        temp->rlink = ptr->rlink;
        ptr->rlink->llink = temp;
        temp->llink = ptr;
        ptr->rlink = temp;
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
        head->rlink->llink = NULL;
        head = head->rlink;
    }
}

void deleteR()
{
    struct node *current = head;
    struct node *previous;
    while(current->rlink != NULL)
    {
        previous = current;
        current = current->rlink;
    }
    previous->rlink = NULL;
}

void delete(int key)
{
    struct node *current = head;
    struct node *previous;
    if(current != NULL && current->data == key)
    {
        head = current->rlink;
    }
    while(current->rlink != NULL && current->data != key)
    {
        previous = current;
        current = current->rlink;
    }
    if(current == NULL)
    {
        printf("Canot Delete, Try Again");
    }
    else if (current->rlink == NULL && current->data == key)
    {
        deleteR(key);
    }
    else
    {
        previous->rlink = current->rlink;
        current->rlink->llink = current->llink;
    }
}

void main()
{
    int x,s=0,data,key;
    while(s != 3)
    {
        printf("Enter:\t 1.Insert\t 2.Delete\t 3.Exit\t:");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Insert : 1.At Front \t 2.At End \t 3.Using Key\t");
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
                printf("Delete : 1.At Front \t 2.At End \t 3.Using Key\t:");
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
