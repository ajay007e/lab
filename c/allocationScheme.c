#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void insert(int data,struct node **temp)
{
    struct node *ptr1, *ptr2;
    ptr1 = *temp;
    if(ptr1 == NULL)
    {
        ptr2 = (struct node*)malloc(sizeof(struct node));
        ptr2->data = data;
        *temp = ptr2;
        ptr2->link = (struct node*)malloc(sizeof(struct node));
        ptr2 = ptr2->link;
        ptr2->link = NULL;
    }
    else
    {
        ptr2->data = data;
        ptr2->link = (struct node*)malloc(sizeof(struct node));
        ptr2 = ptr2->link;
        ptr2->link = NULL;
    }
}

void display(struct node *head)
{
    struct node *ptr = head;
    while(head->link != NULL)
    {
        printf("   %d",head->data);
        head=head->link;
    }
    printf("\n");
    head = ptr;
}

void firstFit(struct node **head1,struct node **head2,struct node **head3)
{
    struct node *processSize,*blockSize,*allocation;
    processSize = *head2;
    allocation = *head3;
    while(processSize->link != NULL)
    {
        int i=1;
        blockSize = *head1;
        while(blockSize->link != NULL && processSize->data > blockSize->data)
        {
            blockSize = blockSize->link;
            i++;
        }
        if(blockSize->data >= processSize->data && blockSize->link !=NULL)
        {
             blockSize->data = blockSize->data - processSize->data ;
             allocation->data = i;
        }
        allocation = allocation->link;
        processSize = processSize->link;
    }
}

void bestFit(struct node **head1,struct node **head2,struct node **head3)
{
    struct node *processSize,*blockSize,*allocation;
    processSize = *head2;
    allocation = *head3;
    while(processSize->link != NULL)
    {
        int i=1,j=1,v=9999,temp;
        blockSize = *head1;
        while(blockSize->link != NULL )
        {
            temp = blockSize->data - processSize->data ;
            if(temp >= 0)
            {
                if(v>temp)
                {
                    v=temp;
                    i=j;
                }
            }
            blockSize = blockSize->link;
            j++;
        }
        if(v != 9999)
        {
            blockSize = *head1;
            j=1;
            while(i!=j)
            {
                blockSize =blockSize->link;
                j++;
            }
             blockSize->data = v;
             allocation->data = i;
        }
        allocation = allocation->link;
        processSize = processSize->link;
    }
}

void worstFit(struct node **head1,struct node **head2,struct node **head3)
{
    struct node *processSize,*blockSize,*allocation;
    processSize = *head2;
    allocation = *head3;
    while(processSize->link != NULL)
    {
        int i=1,j=1,v=0,temp;
        blockSize = *head1;
        while(blockSize->link != NULL )
        {
            temp = blockSize->data - processSize->data ;
            if(temp >= 0)
            {
                if(v<temp)
                {
                    v=temp;
                    i=j;
                }
            }
            blockSize = blockSize->link;
            j++;
        }
        if(v != 0)
        {
            blockSize = *head1;
            j=1;
            while(i!=j)
            {
                blockSize =blockSize->link;
                j++;
            }
             blockSize->data = v;
             allocation->data = i;
        }
        allocation = allocation->link;
        processSize = processSize->link;
    }
}


void main()
{
    struct node *head1 =NULL,*head2 =NULL, *head3 =NULL;  // head1-> block  head2-> process head3->allocation
    int x,i,v;
    /*printf("Number of Blocks:");
    scanf("%d",&x);
    printf("Enter the Block sizes:");
    for(i=0;i<x;i++)
    {
        scanf("%d",&v);
        insert(v,&head1);
    }*/
    insert(100,&head1);
    insert(500,&head1);
    insert(200,&head1);
    insert(300,&head1);
    insert(600,&head1);
    /*printf("Number of Process:");
    scanf("%d",&x);
    printf("Enter the Process sizes:");
    for(i=0;i<x;i++)
    {
        scanf("%d",&v);
        insert(v,&head2);
    }*/
    insert(212,&head2);
    insert(417,&head2);
    insert(112,&head2);
    insert(426,&head2);
    for(i=0;i<4;i++)
    {
        insert(-1,&head3);
    }
    firstFit(&head1,&head2,&head3); //can use any of the three : firstFit(),bestFit() or worstFit()
    printf("Process SIZE :");
    display(head2);
    printf("firstFit-Allocation:");
    display(head3);
    printf("Block Size:");
    display(head1);

}
