#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size,front,rear;
    int *Q;
}q;

void push(int value){
    if(q.front==(q.rear+1)%q.size){
        printf("Queue Full\n");
    }
    else{
        q.rear = (q.rear + 1) % q.size ;
        q.Q[q.rear] = value;
    }
    show();
}

void pop(){
    if(q.front == q.rear){
        printf("Queue Empty\n");
    }
    else{
        q.front = (q.front + 1) % q.size ;
    }
    show();
}

void show(){
    int i;
    if(q.front==q.rear)
        printf("Queue Empty\n");
    else if(q.front<q.rear)
    {
        for(i=q.front+1;i<=q.rear;i++)
            printf("%d    ",q.Q[i]);
        printf("\n");
    }
    else
    {
        for(i=q.front+1;i<=q.size-1;i++)
            printf("%d    ",q.Q[i]);
        for(i=0;i<=q.rear;i++)
            printf("%d    ",q.Q[i]);
        printf("\n");
    }
}

void main(){
    int choice=0,v;
    printf("Enter the size of the Queue : ");
    scanf("%d",&q.size);
    q.size++;
    q.Q = (int*)malloc(q.size*sizeof(int));
    q.front = 0;
    q.rear = 0;
    while(choice!=3){
        printf("Press 1.Add 2.Delete 3.Exit  :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value:");
                scanf("%d",&v);
                push(v);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("program ends.\n");
                break;
            default:
                printf("Invalid.\n");
        }
    }
}
