#include<stdio.h>
#include<stdlib.h>

struct array
{
    int size;
    int *A;
}s,l,r;

bubbleSort(struct array *a,int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n-1;i++)
        {
            if(a->A[i]>a->A[i+1])
            {
                int t = a->A[i];
                a->A[i] = a->A[i+1];
                a->A[i+1] = t;
            }
        }
    }
}
insertionSort(struct array *a,int n)
{
    for(int i=0;i<n;i++)
    {
        int value = a->A[i];
        int hole = i;
        while(hole>0 && a->A[hole-1]>value)
        {
            a->A[hole] = a->A[hole-1];
            hole--;
        }
        a->A[hole] = value;
    }
}
selectionSort(struct array *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a->A[j]<a->A[min])
            {
                min=j;
            }
        }
        int t=a->A[i];
        a->A[i]=a->A[min];
        a->A[min]=t;
    }
}
partition(int start,int end)
{
    int pivot =s.A[end];
    int pl = start;
    for(int i=start;i<end;i++)
    {
        if(s.A[i]<=pivot)
        {
            int t=s.A[i];
            s.A[i]=s.A[pl];
            s.A[pl]=t;
            pl++;
        }
    }
    int t=s.A[pl];
    s.A[pl]=s.A[end];
    s.A[end]=t;
    return pl;
}

quickSort(int start,int end)
{
    int pl;
    if(start<end)
    {
        pl = partition(start,end);
        quickSort(start,pl-1);
        quickSort(pl+1,end);
    }
}
merge(struct array *left,struct array *right,struct array *arr)
{
    int l=left->size;
    int r=right->size;
    int i=0,j=0,k=0;
    while(i<l && j<r)
    {
        if(left->A[i]<=right->A[j])
        {
            arr->A[k++]=left->A[i++];
        }
        else
        {
            arr->A[k++]=right->A[j++];
        }
    }
}
mergeSort(struct array *a,int l,int r)
{
    int n=a->size,i,j=0;
    if(n<2)
    {
        return;
    }
    int mid = n/2;
    l.A = (int *) malloc(mid * sizeof(int));
    r.A = (int *) malloc(n-mid * sizeof(int));
    l.size=mid;
    r.size=n-mid;
    for(i=0;i<mid;i++)
            l.A[i]=a->A[i];
    for(i=mid;i<n;i++)
            r.A[j++]=a->A[i];
    mergeSort(&l);
    mergeSort(&r);
    merge(&l,&r,&a);



}

void main()
{
    printf("enter the size of array:");
    scanf("%d",&s.size);
    s.A = (int *) malloc(s.size * sizeof(int));
    printf("enter the element\n");
    for(int i=0;i<s.size;i++)
    {
        scanf("%d",&s.A[i]);
    }
    //sorting
    bubbleSort(&s,s.size);
        //insertionSort(&s,s.size);
        //selectionSort(&s,s.size);
        //quickSort(0,s.size-1);
        //mergeSort(&s);
    printf("element after sorting\n");
    for(int i=0;i<s.size;i++)
    {
        printf("%d\t",s.A[i]);
    }
}
