#include<stdio.h>
#define C_SIZE 50

union address{
    char name[C_SIZE];
    char housename[C_SIZE];
    char cityname[C_SIZE];
    char state[C_SIZE];
    char pin[C_SIZE];
}data1,data2;

int main()
{
    printf("Enter Name:\n");
    scanf("%s",data1.cityname);
    printf("Enter House Name:\n");
    scanf("%s",data1.housename);
    printf("Enter City Name:\n");
    scanf("%s",data1.cityname);
    printf("Enter State:\n");
    scanf("%s",data1.state);
    printf("Enter Pin:\n");
    scanf("%s",data1.pin);

    printf("Data\n");
    printf("Name:%s\n",data1.name);
    printf("House Name :%s\n",data1.housename);
    printf("City Name :%s\n",data1.cityname);
    printf("State :%s\n",data1.state);
    printf("Pin :%s",data1.pin);

    return 0;
}
