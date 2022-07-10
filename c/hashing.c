#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node *link
};

struct hashTable
{
    int index;
    int data;
    struct node *headNode;
    struct hashTable *link;
};

struct hashTable *head = NULL;

void createTable(int index)
{
    struct hashTable *temp = (struct hashTable*)malloc(sizeof(struct hashTable));
    struct hashTable *ptr=head;
    temp->index = index;
    temp->data = -1;
    temp->headNode = NULL;
    if(head==NULL)
    {
        temp->link = NULL;
        head = temp;
    }
    else
    {
        while(ptr->link!=NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
        temp->link =NULL;
    }
}

int isTableFree(int index)
{
    struct hashTable *ptr=head;
    while(ptr->index != index )
    {
        ptr = ptr->link;
    }
    if(ptr->data == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert(int data,int index)
{
    struct hashTable *ptr=head;
    while(ptr->index != index && ptr->link !=NULL)
    {
        ptr = ptr->link;
    }
    if(ptr->link==NULL && ptr->index != index)
    {
        printf("Search Failed,Try Again\n");
    }
    else
    {
        ptr->data = data;
    }
}

//division method as hashing function
int hashFunction(int data,int size)
{
    return (data%size);
}

//Separate chaining is used as collision resolution technique
void collisionResolution(int data,int index)
{
    struct hashTable *ptr1=head;
    while(ptr1->index != index && ptr1->link !=NULL)
    {
        ptr1 = ptr1->link;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr2 = ptr1->headNode;
    temp->data = data;
    if(ptr1->headNode == NULL)
    {
        temp->link = NULL;
        ptr1->headNode = temp;
    }
    else
    {
        while(ptr2->link!=NULL)
        {
            ptr2 = ptr2->link;
        }
        ptr2->link = temp;
        temp->link =NULL;
    }
}

void display()
{
    struct hashTable *ptr1 = head;
    while(ptr1 !=NULL)
    {
        struct node *ptr2 = ptr1->headNode;
        if(ptr2 == NULL)
        {
            if(ptr1->data == -1)
            {
                printf("%d : \n",ptr1->index);
            }
            else
            {
                printf("%d : %d\n",ptr1->index,ptr1->data);
            }
        }
        else
        {
            printf("%d : %d",ptr1->index,ptr1->data);
            while(ptr2 != NULL)
            {
                printf("    %d",ptr2->data);
                ptr2 = ptr2->link;
            }
            printf("\n");
        }
        ptr1 = ptr1->link;
    }
    printf("\n");
}

void main()
{
    int n,i,x,key;
    printf("Enter the size of Hash Table:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        createTable(i);
    }
    printf("Enter the Records\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        key = hashFunction(x,n);
        if(isTableFree(key))
        {
            insert(x,key);
        }
        else
        {
            collisionResolution(x,key);
        }
    }
    printf("\nHASH TABLE\n\n");
    display();
}
