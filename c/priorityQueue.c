#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int size;
  int top;
  int *s;
}q;

void push(int x)
{
    int t,i;
    if(q.top==q.size-1)
        printf("Queue is Full\n");
    else
    {
        if(q.top==-1)
        {
            q.top++;
            q.s[q.top]=x;
        }
        else
        {
            q.top++;
            q.s[q.top]=x;
            for(i=q.top;i>0;i--)
            {
                if(q.s[i]<q.s[i-1])
                {
                    t=q.s[i];
                    q.s[i]=q.s[i-1];
                    q.s[i-1]=t;
                }
                else
                    break;
            }
        }
    }
}

void pop()
{
    if(q.top==-1)
        printf("Queue is Empty\n");
    else
    {
        q.top--;
        for(int i=0;i<=q.top;i++)
            q.s[i]=q.s[i+1];
    }
}

void display()
{
    if(q.top==-1)
        printf("Queue is Empty\n");
    else
    {
        for(int i=0;i<=q.top;i++)
            printf("%d\t",q.s[i]);
        printf("\n");
    }
}

int main()
{
    int option=0,value;
    printf("Enter the Size of the Queue:");
    scanf("%d",&q.size);
    q.top=-1;
    q.s = (int *) malloc(q.size * sizeof(int));
    while(option!=4)
    {
        printf("Press:\t 1 for Push \t 2 for Pop \t 3 for Display \t 4 for Exit\t:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the Number:");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting");
                break;
            default:
                printf("Invalid");
        }
    }
}
