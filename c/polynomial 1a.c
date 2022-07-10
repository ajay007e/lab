#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coe;
    int ex;
};

struct poly
{
    int n;
    struct term *terms;
};

void create(struct poly *p)
{
    int i;
    printf("Enter number of terms:");
    scanf("%d",&p->n);
    p->terms = (struct term*)malloc(p->n * sizeof(struct  term));
    printf("Enter terms:\n");
    for(i=0;i<p->n;i++)
    {
        scanf("%d%d",&p->terms[i].coe,&p->terms[i].ex);
    }
}

void display(struct poly p)
{
    int i;
    for(i=0;i<p.n;i++)
    {
        if(p.terms[i].coe!=0)
        {
            if(p.terms[i].ex!=0)
            {
                if(p.terms[i].coe!=1)
                {
                    printf("%dX^%d ",p.terms[i].coe,p.terms[i].ex);
                }
                else
                {
                    printf("X^%d ",p.terms[i].ex);
                }
            }
            else
            {
                printf("%d ",p.terms[i].coe);
            }
            if(i!=p.n-1)
            {
                if(p.terms[i+1].coe>0 || (p.terms[i+1].coe==0 && p.terms[i+1].ex==-1))
                {
                    printf("+");
                }
            }
        }
    }
    printf("\n");
}

struct poly *add(struct poly *p1,struct poly *p2)
{
    int i=0,j=0,k=0;
    struct poly *sum;
    sum = (struct poly *)malloc(sizeof(struct poly));
    sum->terms = (struct term *)malloc((p1->n + p2->n)*sizeof(struct term));
    while(i< p1->n && j<p2->n)
    {
        if(p1->terms[i].ex > p2->terms[j].ex)
        {
            sum->terms[k++]=p1->terms[i++];
        }
        else if(p1->terms[i].ex < p2->terms[j].ex)
        {
            sum->terms[k++]=p2->terms[j++];
        }
        else
        {
            sum->terms[k].ex = p1->terms[i].ex;
            sum->terms[k++].coe = p1->terms[i++].coe + p2->terms[j++].coe ;
        }
    }
    for(;i<p1->n;i++)
    {
        sum->terms[k++]=p1->terms[i];
    }
    for(;j<p2->n;j++)
    {
        sum->terms[k++]=p2->terms[j];
    }
    sum->n = k;
    return sum;
};

struct poly *sub(struct poly *p1,struct poly *p2)
{
    int i=0,j=0,k=0;
    struct poly *sub;
    sub = (struct poly *)malloc(sizeof(struct poly));
    sub->terms = (struct term *)malloc((p1->n + p2->n)*sizeof(struct term));
    while(i< p1->n && j<p2->n)
    {
        if(p1->terms[i].ex > p2->terms[j].ex)
        {
            sub->terms[k++]=p1->terms[i++];
        }
        else if(p1->terms[i].ex < p2->terms[j].ex)
        {
            sub->terms[k]=p2->terms[j++];
            sub->terms[k++].coe*=-1;
        }
        else
        {
            sub->terms[k].ex = p1->terms[i].ex;
            sub->terms[k++].coe = p1->terms[i++].coe - p2->terms[j++].coe ;
        }
    }
    for(;i<p1->n;i++)
    {
        sub->terms[k++]=p1->terms[i];
    }
    for(;j<p2->n;j++)
    {
        sub->terms[k]=p2->terms[j];
        sub->terms[k++].coe*=-1;
    }
    sub->n = k;
    return sub;
};

struct poly *multi(struct poly *p1,struct poly *p2)
{
    int i,j,k=0;
    struct poly *multi;
    multi = (struct poly *)malloc(sizeof(struct poly));
    multi->terms = (struct term *)malloc((p1->n * p2->n)*sizeof(struct term));
    for(i=0;i<p1->n;i++)
    {
        for(j=0;j<p2->n;j++)
        {
            multi->terms[k].coe=p1->terms[i].coe*p2->terms[j].coe;
            multi->terms[k++].ex=p1->terms[i].ex+p2->terms[j].ex;
        }
    }
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            if(multi->terms[i].ex==multi->terms[j].ex)
            {
                multi->terms[i].coe+=multi->terms[j].coe;
                multi->terms[j].coe=0;
                multi->terms[j].ex=-1;
            }
        }
    }
    multi->n=(p1->n * p2->n);
    return multi;
};

int main()
{
    struct poly p1,p2,*p3,*p4,*p5;
    printf("Polynomial 1\n");
    create(&p1);
    display(p1);
    printf("\nPolynomial 2\n");
    create(&p2);
    display(p2);
    p3=add(&p1,&p2);
    printf("\nAdditional Result:");
    display(*p3);
    p4=sub(&p1,&p2);
    printf("\nSubtraction Result:");
    display(*p4);
    p5=multi(&p1,&p2);
    printf("\nMultiplication Product:");
    display(*p5);
    return 0;
}

