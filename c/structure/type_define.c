#include<stdio.h>
#include<stdlib.h>

#define	cptr	char* 
typedef	char*  ptr;	

int main()
{

cptr a,b,c;
ptr x,y,z;

printf("sizeof cptr=%ld\n",sizeof(a));
printf("sizeof cptr=%ld\n",sizeof(b));
printf("sizeof cptr=%ld\n",sizeof(c));

printf("sizeof ptr=%ld\n",sizeof(x));
printf("sizeof ptr=%ld\n",sizeof(y));
printf("sizeof ptr=%ld\n",sizeof(z));
}
