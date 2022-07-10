#include<stdio.h>
#include<stdlib.h>

int matrix[32][32],visited[32],v,e;

//QUEUE SETUP
struct nodeQ
{
    int data;
    struct nodeQ *link;
};

struct nodeQ *queue =NULL;

void pushQueue(int data)
{
    struct nodeQ *temp = (struct nodeQ*)malloc(sizeof(struct nodeQ));
    struct nodeQ *ptr=queue;
    temp->data = data;
    if(queue==NULL)
    {
        temp->link=NULL;
        queue = temp;
    }
    else
    {
        ptr=queue;
        while(ptr->link!=NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
        temp->link =NULL;
    }
}

int popQueue()
{
    int x =0;
    if(queue == NULL)
    {
        printf("Queue is Empty");
    }
    else
    {
        x =queue->data;
        queue = queue->link;
    }
    return x;
}

int isEmptyQueue()
{
    if(queue == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//MATRIX
void create_matrix(int vertice, int edges)
{
    int i,j;
    matrix[vertice][edges];
    for(i=0;i<vertice;i++)
    {
        for(j=0;j<edges;j++)
        {
            printf("%d-->%d ? 1 for yes 0 for no : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    /*for(i=0;i<vertice;i++)
    {
        for(j=0;j<edges;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    };*/
}


//SEARCHING
void BFS(int i)
{
    int u,k;
    printf("%d\t",i);
    visited[i]==1;
    pushQueue(i);
    while(!isEmptyQueue())
    {
        u = popQueue();
        for(k=0;k<v;k++)
        {
            if(matrix[u][k]==1 && visited[k]==0)
            {
                printf("%d\t",k);
                visited[k]=1;
                pushQueue(k);
            }
        }
    }
}

void DFS(int u)
{
    int i;
    if (visited[u]==0)
    {
        printf("%d\t",u);
        visited[u]=1;
        for(i=1;i<v;i++)
        {
            if(matrix[u][i]==1 && visited[i]!=1)
            {
                DFS(i);
            }
        }
    }
}


void main()
{
    int i,j;
    printf("Enter Vertice : ");
    scanf("%d",&v);
    printf("Enter Edges : ");
    scanf("%d",&e);
    create_matrix(v,v);
    printf("\n\nDFS\n\n");
    DFS(0);
    // printf("\n\nBFS\n\n");
    // BFS(0);
}
