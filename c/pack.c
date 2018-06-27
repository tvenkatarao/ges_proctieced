#include<stdio.h>
#pragma pack (2)
struct st
{
    int x ;
    char ch1;
    double y ;
    char ch;
};
int main()
{
struct st s={10,20,'f','d'};

printf("sizeof double:%d\n",sizeof(double));

    printf("size of st:%d\n",sizeof(struct st));


return 0;
}
