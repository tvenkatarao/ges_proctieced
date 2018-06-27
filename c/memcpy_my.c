#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mymemcpy(void *dest, void *src,size_t n)
{
char *csrc = (char *) src;
char *cdest = (char *) dest;
int i;
for (i=0;i<n;i++)
cdest[i] = csrc[i];

}


int main()
{
char csrc[] = "hello world .";
char cdest[100];
mymemcpy(cdest,csrc,strlen(csrc)+1);
printf("copied string is %s",cdest);

int isrc[] = {10,20,30,40,50};
int n = sizeof(isrc)/sizeof(isrc[0]);
int idest[n],i;
mymemcpy(idest,isrc,sizeof(isrc));
for(i=0;i<n;i++)
printf("%d ",idest[i]);

return 0;
}
