/*
 You cannot use pointers to reference objects that have the register storage class specifier.
 only You cannot use the register storage class specifier when declaring objects in global scope.
 only A register does not have an address. Therefore, you cannot apply the address operator (&) to a register variable.

*/
#include<stdio.h>
int main()
{
 register int x=1;
 int z=20;
 int *p;
 p = &z;

 printf("address of z p %x\n",&z);
// printf("address of x %x\n",&x);




}
