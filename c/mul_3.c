#include <stdio.h>

int main (void)
{
  int i=0;
printf("enter the numbe ..:\n");
scanf("%d",&i);
  
unsigned int mask = 0x00;

//  for (i=0; i<100;i++)
 // {
    if ((i&0x03) == mask)
    {
      printf ("\n%d", i);
      mask = (mask + 3) & 0x03;
    }
 // }
  printf ("\n");
  return 0;
}
