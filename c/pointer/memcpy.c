#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

    char src[20] ="amlendra";
 //   char* dst= NULL; // seg fault
 //   char dst[39];
    char *dst;
    dst = malloc(sizeof(char*)*30);
    //    memcpy(dst,src+2,sizeof(src));
    memcpy(dst,src+2,3);


printf("dst=%s \t src=%s\n",dst,src);
    return 0;
}
