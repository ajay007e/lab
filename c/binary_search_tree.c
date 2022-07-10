#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

struct node *root =NULL;

void postorder(struct node *t)
{
    if(t != NULL)
    {
        postorder(t->llink);
        postorder(t->rlink);
        printf("%d   ",t->data);
    }
}

void insert(int key)
{
    struct node *r = NULL,*p,*t = root;
    while(t != NULL)
    {
        r = t;
        if (key == t->data)
            return;
        else if (key < t->data)
            t = t->llink;
        else
            t = t->rlink;
    }
    p = (struct node*)malloc(sizeof(struct node));
    p->data = key;
    p->llink = NULL;
    p->rlink = NULL;
    if (p->data < r->data)
        r->llink = p;
    else
        r->rlink = p;
}

struct node *Delete(struct node *p,int key)
{
    int x;
    if(p == NULL)
        return;
    else if(p->llink==NULL && p->rlink == NULL)
    {
        if(p==root)
            root = NULL;
        free(p);
        return NULL;
    }
    else if(p->data == key && (p->llink != NULL || p->rlink != NULL))
    {
        if(p->llink != NULL && p->rlink != NULL)
        {
            printf("Can't delete, it collapse the tree.\nIf you want delete, press 1 ,Else press 0 :");
            scanf("%d",&x);
            if (x==1)
            {
                p = NULL;
            }
        }
        else if(p->rlink == NULL)
        {
                p = p->llink;
        }
        else if(p->llink == NULL)
        {
                p = p->rlink;
        }
    }
    else if(key < p->data)
        p->llink = Delete(p->llink,key);
    else if(key > p->data)
        p->rlink = Delete(p->rlink,key);
}

void create()
{
    int x,s=0;

    printf("Enter the value of root node:");
    scanf("%d",&x);
    root = (struct node*)malloc(sizeof(struct node));
    root->data = x;
    root->llink = NULL;
    root->rlink = NULL;
    while(s!= -1)
    {
        printf("1 for insert\t 0 for delete\t -1 to exit : ");
        scanf("%d",&s);
        if (s==1)
        {
            printf("enter the value:");
            scanf("%d",&x);
            insert(x);
        }
        else if (s==0)
        {
            printf("enter the value:");
            scanf("%d",&x);
            Delete(root,x);
        }
        else if(s==9)
        {
            printf("\n");
            postorder(root);
            printf("\n");
        }
    }
}


void main()
{
    create();
}
