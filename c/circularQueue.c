#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int size;
  int front;
  int rear;
  int *s;
}q;

void push()
{
    if((q.rear+1) % q.size == q.front)
        printf("Queue is Full\n");
    else
    {
        q.rear=(q.rear+1)%q.size;
        printf("Enter the Number:");
        scanf("%d",&q.s[q.rear]);
    }
}

void pop()
{
    if(q.front==q.rear)
        printf("Queue is Empty\n");
    else
    {
        q.front=(q.front+1)%q.size;
    }
}

void display()
{
    int i;
    if(q.front==q.rear)
        printf("Queue is Empty\n");
    else if(q.front<q.rear)
    {
        for(i=q.front+1;i<=q.rear;i++)
            printf("%d\t",q.s[i]);
        printf("\n");
    }
    else
    {
        for(i=q.front+1;i<=q.size-1;i++)
            printf("%d\t",q.s[i]);
        for(i=0;i<=q.rear;i++)
            printf("%d\t",q.s[i]);
        printf("\n");
    }
}

int main()
{
    int option=0;
    printf("Enter the Size of the Queue:");
    scanf("%d",&q.size);
    q.size++;
    q.front=0;
    q.rear=0;
    q.s = (int *) malloc(q.size * sizeof(int));
    while(option!=4)
    {
        printf("Press:\t 1 for Push \t 2 for Pop \t 3 for Display \t 4 for Exit\t:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                push();
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
                printf("Invalid\n");
        }
    }
}
