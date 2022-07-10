#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

struct node *head =NULL;
int l=1;

void check()
{
        int i;
        struct node *ptr = head;
        while(ptr !=NULL && ptr->data != -1)
        {
            ptr=ptr->rlink;
            i++;
        }
        printf("%d allocations are done, %d allocations are available\n",i,l-i);
}

void insert(int data)
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

void setFree()
{
    head->rlink->llink = NULL;
    head = head->rlink;
    insert(-1);
}

void allocate()
{

    struct node *ptr = head;
    while(ptr !=NULL && ptr->data != -1)
    {
        ptr=ptr->rlink;
    }
    if(ptr !=NULL && ptr->data == -1)
    {
        ptr->data = 1;
    }
    if(ptr == NULL)
    {
        printf("Empty\n");
    }
}


void main()
{
    int x,s=0,data=-1,i=0;
    while(l==1)
    {
        insert(data);
        printf("Allocation Space :%d , do you want to continue ?",i);
        scanf("%d",&l);
        if(l==1)
        {
            i++;
        }
        else
        {
            l=i;
            i=10;
        }
    }
    printf("Total allocation Space : %d\n",l);
    while(s != 3)
    {
        printf("1 for allocation\t2 for free\t3 for exist\t:");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Number of allocation:");
                scanf("%d",&x);
                while(x!=0)
                {
                    allocate();
                    x--;
                }
                check();
                break;
            case 2:
                printf("Number of De-allocation:");
                scanf("%d",&x);
                while(x!=0)
                {
                    setFree();
                    x--;
                }
                check();
                break;
            case 3:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid\n");
        }
    }
}
