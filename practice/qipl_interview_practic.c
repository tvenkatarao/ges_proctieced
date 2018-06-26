#include<stdio.h>

int *fun(int val) {
    int a = val;

    printf("&a=%d\n",&a);
    return &a;
    }
    int main() {
    int a =10;
   static int *p;
    p = fun(a);
    printf("*p=%d\n",*p);
*p=5;
    printf("*p=%d\n",*p);
    printf("p=%d\n",p);
     }



/*
main()
{

/*
char *p="123";
 int *a = (int *)p;
 printf("%s\n ",a);
////

   char *ptr = "Linux";
   printf("\n[%c]\n",*ptr++);
   printf("\n[%c]\n",*ptr);
*//*
char *p1 = "name";
   char *p2;
   p2 = (char *)malloc(20);
   memset(p2,0,20);
   while(*p2++ = *p1++);
   printf("%s\n",p2);
*//*/
char *p1 = "Cisco Systems";
   *p1++;
   printf("%s\n",p1);
   p1++;
   printf("%s\n",p1);

}*/
