// count the number of set bit in a bumber from 1 to n

#include<stdio.h>
#include<stdlib.h>

int countSetBits(unsigned int n)
{
    int count=0;
    unsigned int c; // the total bits set in n
    for (c = 0; n; n >>= 1)
    {
        c += n & 1;
        printf("count is %d\n",count++);
    }
    return c;
}

int main()
{
    unsigned int i ;
    for(i=255;i<350;i++)
        printf("num is %d no of set bits %d\n",i,countSetBits(i));

return 0;

}
