#include<stdio.h>
struct employee{
    char name[25];
    int id;
    int salary;
}emp[50];

int main()
{
    int i,n;
    printf("Enter number of Employees:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Employee Details:\n");
        printf("Employee ID:\n");
        scanf("%d",&emp[i].id);
        printf("Employee Name:\n");
        scanf("%s",emp[i].name);
        printf("Employee Salary:\n");
        scanf("%d",&emp[i].salary);
    }
    for(i=0;i<n;i++)
    {
        printf("Employee%d Details:\n",i+1);
        printf("Employee Name:%s\n",emp[i].name);
        printf("Employee ID:%d\n",emp[i].id);
        printf("Employee Salary:%d\n",emp[i].salary);
        printf("\n");
    }
    return 0;
}
