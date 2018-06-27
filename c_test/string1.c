#include<stdio.h>

int main()
{
    char *p;
    p="hello";
    printf("%s\n", *&*&p);
    return 0;
}
