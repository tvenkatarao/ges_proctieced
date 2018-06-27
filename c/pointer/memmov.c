#include <stdio.h>
#include <string.h>
int main()
{
    char csrc[100] = "Geeksfor";
    char des[100];
    //memmove(des, csrc+5, strlen(csrc)+1);
    memmove(des, csrc+5, 2);
    printf("%s\n", csrc);
    printf("%s\n", des);
    return 0;
}
