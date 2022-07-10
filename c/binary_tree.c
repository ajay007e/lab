#include<stdio.h>
#include<stdlib.h>

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

struct nodeS
{
    int data;
    struct nodeS *link;
};

struct nodeS *stack =NULL;

void pushStack(int data)
{
    struct nodeS *temp = (struct nodeS*)malloc(sizeof(struct nodeS));
    temp->data=data;
    temp->link=stack;
    stack=temp;
}

int popStack()
{
    int x=0;
    if(stack == NULL)
    {
        //printf("Stack is Empty");
    }
    else
    {
        x = stack->data;
        stack = stack->link;
    }
    return x;
}

int isEmptyStack()
{
    if(stack == NULL)
        return 1;
    else
        return 0;
}

int stackTop()
{
    return stack->data;
}

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

struct node *root =NULL;


void create()
{
    struct node *p,*t;
    int x,s;

    printf("Enter the value of root node:");
    scanf("%d",&x);
    root = (struct node*)malloc(sizeof(struct node));
    root->data = x;
    root->llink = NULL;
    root->rlink = NULL;
    pushQueue(root);

    while(!isEmptyQueue())
    {
        p = popQueue();
        printf("Enter left Child of %d ,else press -1:",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct node*)malloc(sizeof(struct node));
            t->data = x;
            t->llink =NULL;
            t->rlink = NULL;
            p->llink = t;
            pushQueue(t);
        }
        printf("Enter right Child of %d ,else press -1:",p->data);
        scanf("%d",&x);
        if(x != -1)
        {
            t = (struct node*)malloc(sizeof(struct node));
            t->data = x;
            t->llink =NULL;
            t->rlink = NULL;
            p->rlink = t;
            pushQueue(t);
        }
    }

}

void preorder(struct node *t)
{
    if(t != NULL)
    {
        printf("%d   ",t->data);
        preorder(t->llink);
        preorder(t->rlink);
    }
}

void inorder(struct node *t)
{
    if(t != NULL)
    {
        inorder(t->llink);
        printf("%d   ",t->data);
        inorder(t->rlink);
    }
}

void postorder(struct node *t)
{
    if(t != NULL)
    {
        postorder(t->llink);
        postorder(t->rlink);
        printf("%d   ",t->data);
    }
}


void iInorder(struct node *t)
{
    while(t != NULL || !isEmptyStack())
    {
        if(t != NULL)
        {
            pushStack(t);
            t = t->llink;
        }
        else
        {
            t = popStack();
            printf("%d   ",t->data);
            t = t->rlink;
        }
    }
}

void iPreorder(struct node *t)
{
    while(t != NULL || !isEmptyStack())
    {
        if(t != NULL)
        {
            printf("%d   ",t->data);
            pushStack(t);
            t = t->llink;
        }
        else
        {
            t = popStack();
            t = t->rlink;
        }
    }
}


void iPostorder(struct node *t)
{
    struct node *temp;
    while (t != NULL)
	{
		while (t != NULL)
		{
			if (t->rlink)
				pushStack(t->rlink);
			pushStack(t);
			t = t->llink;
		}
		while(!isEmptyStack())
        {
            if(t != NULL)
            {
                while (t != NULL)
                {
                    if (t->rlink)
                        pushStack(t->rlink);
                    pushStack(t);
                    t = t->llink;
                }
            }
            else
            {
                t = stackTop();
                popStack();
                if(!isEmptyStack() && t->rlink!= NULL && t->rlink == stackTop())
                {
                    temp = popStack();
                    pushStack(t);
                    t = temp;
                }
                else
                {
                    printf("%d   ",t->data);
                    t = NULL;
                }
            }
        }
		t = popStack();
		if (t->rlink != NULL && stackTop() == t->rlink)
		{
			popStack();
			pushStack(t);

			t = t->rlink;
		}
		else
		{
			printf("%d  ",t->data);
			t = NULL;
		}


	};
}


void main()
{
    create();
    //preorder(root);
    //iPostorder(root);
    postorder(root);
}
