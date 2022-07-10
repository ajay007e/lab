#include<stdio.h>
#include<stdlib.h>

struct node
{
    int edge;
    struct node *link;
};

struct list
{
    int vertex;
    struct node *headNode;
    struct list *link;
};

struct list *head = NULL;

void createTable(int vertex)
{
    struct list *temp = (struct list*)malloc(sizeof(struct list));
    struct list *ptr=head;
    temp->vertex = vertex;
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

void insert(int edge,int vertex)
{
    struct list *ptr1=head;
    while(ptr1->vertex != vertex && ptr1->link !=NULL)
    {
        ptr1 = ptr1->link;
    }
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr2 = ptr1->headNode;
    temp->edge = edge;
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


void create_list(int vertice, int edges)
{
    int i,j,value;
    for(i=0;i<vertice;i++)
    {
        createTable(i);
    }
    for(i=0;i<vertice;i++)
    {
        for(j=0;j<vertice;j++)
        {
            printf("%d-->%d ? 1 for yes 0 for no : ",i,j);
            scanf("%d",&value);
            if (value == 1)
                insert(j,i);
        }
    }
    printf("\nAdjacency List\n\n");
    display();

}

void display()
{
    struct list *ptr1 = head;
    while(ptr1 !=NULL)
    {
        struct node *ptr2 = ptr1->headNode;
        {
            printf("%d :",ptr1->vertex);
            while(ptr2 != NULL)
            {
                printf("    %d",ptr2->edge);
                ptr2 = ptr2->link;
            }
            printf("\n");
        }
        ptr1 = ptr1->link;
    }
    printf("\n");
}


void create_matrix(int vertice)
{
    int i,j,matrix[vertice][vertice];
    for(i=0;i<vertice;i++)
    {
        for(j=0;j<vertice;j++)
        {
            printf("%d-->%d ? 1 for yes 0 for no : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("\nAdjacency Matrix\n\n");
    for(i=0;i<vertice;i++)
    {
        for(j=0;j<vertice;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    };
}

void main()
{
    int v,e,i,j;
    printf("Enter Vertice : ");
    scanf("%d",&v);
    printf("Enter Edges : ");
    scanf("%d",&e);
   // create_matrix(v);
    create_list(v,e);

}
