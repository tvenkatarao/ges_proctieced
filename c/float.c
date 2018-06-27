#include<stdio.h>
void main(){
   int i;
//   double a=5.2; // no error
float a=5.2; // 4bytes
   char *ptr;
   ptr=(char *)&a;
//   for(i=0;i<=7;i++)
   for(i=0;i<=3;i++)
      printf("%d ",*ptr++);
}
