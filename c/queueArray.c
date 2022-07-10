#include <stdio.h>
int stack[100],n,top=-1,s=0,v;
void push()
{
if(top==n-1)
printf("Overflow\n");
else
{
printf("Enter the value to Add:");
scanf("%d",&v);
stack[++top]=v;
}
}
void pop()
{
if(top==-1)
printf("Underflow\n");
else
--top;
}
void display()
{
int i;
for(i=top;i>=0;i--)
printf("%d\t",stack[i]);
printf("\n");
if(top==-1)
printf("Stack is Empty\n");
}
int main()
{
printf("Enter the size of the Stack:");
scanf("%d",&n);
while(s!=4)
{
printf("Press:\t 1 for Push \t 2 for Pop \t 3 for Display \t 4 for Exit\t:");
scanf("%d",&s);
switch(s)
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
