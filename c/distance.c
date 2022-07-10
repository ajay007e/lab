#include<stdio.h>
struct point{
    int x;
    int y;
}p1,p2;

int main()
{
    printf("Enter Coordinates of point one (x1,y1) :");
    scanf("%d%d",&p1.x,&p1.y);
    printf("Enter Coordinates of point two (x2,y2) :");
    scanf("%d%d",&p2.x,&p2.y);
    printf("New Coordinates:\n");
    printf("X=%d Y=%d",p1.x +p2.x ,p1.y +p2.y);
    return 0;
}
