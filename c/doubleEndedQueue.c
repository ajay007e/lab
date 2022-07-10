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
    int f,v;
    printf("Enter:\t 0 for Push at Front\t 1 for Push at Rear\t:");
    scanf("%d",&f);
    if(f)
    {
        if(q.rear==q.size-1)
            printf("Overflow\n");
        else
        {
            printf("Enter the value to Add:");
            scanf("%d",&v);
            q.rear++;
            q.s[q.rear]=v;
        }
    }
    else
    {
        if(q.front==-1)
            printf("Overflow\n");
        else
        {
            printf("Enter the value to Add:");
            scanf("%d",&v);
            q.front--;
            q.s[q.front]=v;
        }
    }
}

void pop()
{
    int f;
    if(!(q.front==q.rear))
    {
        printf("Enter:\t 0 for Pop at Front\t 1 for Pop at Rear\t:");
        scanf("%d",&f);
        if(f)
        {
            if(q.rear==-1)
                printf("Underflow\n");
            else
                --q.rear;
        }
        else
        {
            if(q.front==q.size-1)
                printf("Underflow\n");
            else
                q.front++;
        }
        if(q.front==q.rear)
            q.rear=q.front=-1;
    }
    else
    {
        printf("Queue is Empty\n");
    }

}

void display()
{
    int i=0;
    if(q.rear==q.front)
        printf("Queue is Empty\n");
    else
    {
        if(q.front!=-1)
            i=q.front+1;
        for(i;i<=q.rear;i++)
            printf("%d\t",q.s[i]);
        printf("\n");
    }
}

int main()
{
    int option=0;
    printf("Enter the Size of the Queue:");
    scanf("%d",&q.size);
    q.front=-1;
    q.rear=-1;
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
                printf("Invalid");
        }
    }
}
