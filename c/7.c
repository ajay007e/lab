#include <stdio.h>
#include<stdlib.h>

void getdata(int *ptr,int r,int c)
{
    int i, j;


    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", (*(ptr + i) + j));
        }
    }
}

void add(int *ptr1, int *ptr2, int *ptr3,int r,int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            *(*(ptr3 + i) + j) = *(*(ptr1 + i) + j) + *(*(ptr2 + i) + j);
        }
    }
}

void showdata(int *ptr,int r,int c)
{
    int i, j;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", *(*(ptr + i) + j));
        }
        if(j==c-1)
            printf("\n");
    }
}

int main()
{
    int r,c,i,j,*f,*s,*m;
    printf("Enter row and coloum");
    scanf("%d%d",&r,&c);
    f=(int *)malloc(r*c*sizeof(int));
    s=(int *)malloc(r*c*sizeof(int));
    m=(int *)malloc(r*c*sizeof(int));
    printf("Enter elements in first matrix of size %dx%d: \n",r,c);
    getdata(f,r,c);


    printf("\nEnter elemetns in second matrix of size %dx%d: \n",r,c);
    getdata(s,r,c);

    add(f,s,m,r,c);

    printf("\nSum of first and second matrix: \n");
    showdata(m,r,c);


    return 0;
}
