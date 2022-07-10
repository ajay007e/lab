#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe;
    int ex;
    struct node *link;
};

void create(int coe,int ex,struct node **temp)
{
    struct node *ptr1, *ptr2;
    ptr1 = *temp;
    if(ptr1 == NULL)
    {
        ptr2 = (struct node*)malloc(sizeof(struct node));
        ptr2->coe = coe;
        ptr2->ex = ex;
        *temp = ptr2;
        ptr2->link = (struct node*)malloc(sizeof(struct node));
        ptr2 = ptr2->link;
        ptr2->link = NULL;
    }
    else
    {
        ptr2->coe = coe;
        ptr2->ex = ex;
        ptr2->link = (struct node*)malloc(sizeof(struct node));
        ptr2 = ptr2->link;
        ptr2->link = NULL;
    }
}

void add(struct node *head1,struct node *head2,struct node *head)
{
    struct node *ptr1 = head1,*ptr2 = head2;
    while(head1->link != NULL && head2->link != NULL)
    {
        if(head1->ex > head2->ex)
        {
            head->ex = head1->ex;
            head->coe = head1->coe;
            head1 = head1->link;
        }
        else if(head1->ex < head2->ex)
        {
            head->ex = head2->ex;
            head->coe = head2->coe;
            head2 = head2->link;
        }
        else
        {
            head->ex = head1->ex;
            head->coe = head1->coe + head2->coe;
            head1 = head1->link;
            head2 = head2->link;
        }
        head->link = (struct node*)malloc(sizeof(struct node));
        head = head->link;
        head->link = NULL;
    }
    while(head1->link != NULL || head2->link != NULL)
    {
        if(head1->link != NULL)
        {
            head->ex = head1->ex;
            head->coe = head1->coe;
            head1 = head1->link;
        }
        if(head2->link != NULL)
        {
            head->ex = head2->ex;
            head->coe = head2->coe;
            head2 = head2->link;
        }
        head->link = (struct node*)malloc(sizeof(struct node));
        head = head->link;
        head->link = NULL;
    }
    head1 = ptr1;
    head2 = ptr2;
}

void multi(struct node *head1,struct node *head2,struct node *head)
{
    struct node *ptr1 = head1,*ptr2 =head,*temp;
    while(head1->link !=NULL)
    {
        temp = head2;
        while(head2->link != NULL)
        {
            head->coe = head1->coe * head2->coe;
            head->ex = head1->ex + head2->ex;
            head2 = head2->link;
            head->link = (struct node*)malloc(sizeof(struct node));
            head = head->link;
            head->link = NULL;
        }
        head1 = head1->link;
        head2 = temp;
    }
    head1 = ptr1;
    head = ptr2;
    ptr1 = head;
    while(head->link != NULL)
    {
        temp = head->link;
        while(temp->link != NULL)
        {
            if(head->ex == temp->ex)
            {
                head->coe += temp->coe;
                temp->coe = 0;
                temp = temp->link;

            }
            else
            {
                temp = temp->link;
            }
        }
        head = head->link;
    }
    head = ptr1;
}

void display(struct node *head)
{
    struct node *ptr = head;
    while(head->link != NULL)
    {
        if(head->coe != 0)
        {
            if(head->ex != 0)
            {
                if(head->coe != 1)
                {
                    printf("%dX^%d ",head->coe,head->ex);
                }
                else
                {
                    printf("X^%d ",head->ex);
                }
            }
            else
            {
                printf("%d ",head->coe);
            }
            head = head->link;
            if(head->link != NULL)
            {
                if(head->coe >= 0 )
                {
                    printf("+");
                }
            }
        }
        else
        {
            head = head->link;
        }
    }
    printf("\n");
    head = ptr;
}

void main()
{
    struct node *head1 = NULL,*head2 = NULL,*headR = NULL,*headP = NULL;
    create(5,2,&head1);
    create(4,1,&head1);
    create(2,0,&head1);
    create(5,1,&head2);
    create(5,0,&head2);
    printf("1st Polynomial:\t\t");
    display(head1);
    printf("2st Polynomial:\t\t");
    display(head2);
    headR = (struct node*)malloc(sizeof(struct node));
    add(head1,head2,headR);
    printf("Resultant Polynomial:   ");
    display(headR);
    headP = (struct node*)malloc(sizeof(struct node));
    multi(head1,head2,headP);
    printf("Product Polynomial:\t");
    display(headP);
}
