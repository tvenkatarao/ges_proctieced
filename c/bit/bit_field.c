#include<stdio.h>
#include<stdlib.h>
struct FP {
// the order of the members depends on the
// endian scheme of the underlying machine
      unsigned int mantissa : 23;
     unsigned int exponent : 8;
      unsigned int sign : 1;
} *fp;
 
int main() {
       float f = -1.0f;
       fp = (struct FP *)&f;
 
printf(" sign = %s, biased exponent = %u,mantissa = %u ", fp->sign ? "negative" : "positive",fp->exponent, fp->mantissa);
}
