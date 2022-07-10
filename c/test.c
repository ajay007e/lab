#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe;
    int ex;
    struct node *link;
};
struct node *poly1=NULL;
struct node *poly2=NULL;
struct node *poly3=NULL;
struct node *temp;

void create(struct node *num)
{
    int i=1,term=0,ex,coe;
    struct node *ptr1, *ptr2;
    ptr1 = num;
    while(i==1){
        printf("enter coefficient of %d term\n",term+1);
        scanf("%d",&coe);
        printf("enter exponenet of %d term\n",term+1);
        scanf("%d",&ex);

        if(ptr1 == NULL)
        {
            ptr2 = (struct node*)malloc(sizeof(struct node));
            ptr2->coe = coe;
            ptr2->ex = ex;
            num = ptr2;
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

        printf("if you want another node press 1 ,else press 0");
        scanf("%d",&i);
        term++;
    }
}

void addpoly(struct node *poly1,struct node *poly2,struct node *poly3){
    while(poly1->link!=NULL&&poly2->link!=NULL){
        if((poly1->ex) > (poly2->ex)){
            poly3->ex=poly1->ex;
            poly3->coe=poly1->coe;
            poly1=poly1->link;
        }
        else if((poly1->ex)<(poly2->ex)){
            poly3->ex=poly2->ex;
            poly3->coe=poly2->coe;
            poly2=poly2->link;
        }
        else{
            poly3->ex=poly1->ex;
            poly3->coe=((poly1->coe)+(poly2->coe));
            poly1=poly1->link;
            poly2=poly2->link;
        }
        poly3->link=(struct node *)malloc(sizeof(struct node));
        poly3=poly3->link;
        poly3->link=NULL;
    }
    while(poly1->link!=NULL||poly2->link!=NULL){
        if(poly1!=NULL){
            poly3->ex=poly1->ex;
            poly3->coe=poly1->coe;
            poly1=poly1->link;
        }
        if(poly2!=NULL){
            poly3->ex=poly2->ex;
            poly3->coe=poly2->coe;
            poly2=poly2->link;
        }
        poly3->link=(struct node *)malloc(sizeof(struct node));
        poly3=poly3->link;
        poly3->link=NULL;
    }
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
    printf("enter first polynomial\n");
    create(poly1);
    //printf("first polynomial is\n");
    display(poly1);

    printf("enter second polynomial\n");
    create(poly2);
//    printf("second polynomial is\n");

    addpoly(poly1,poly2,poly3);
    printf("added polynomial is\n");


    }
