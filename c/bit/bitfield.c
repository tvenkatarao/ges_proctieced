#include <stdio.h>
#include <stdlib.h>
typedef struct test
{
   unsigned int x: 2;
   unsigned int y: 3;
   unsigned int z: 2;
}TEST;
int main()
{
   TEST t={5,4,3};
  // t.x = 5; // larger int  x : 2 (two bits onle ) t.x need 3 bits 5= 101

//   t.y = 5;
   printf("t.x two bit=%d\n", t.x);
   printf("t.y three bit =%d\n", t.y);
   printf("t.z two bit =%d\n", t.z);
   return 0;
}

