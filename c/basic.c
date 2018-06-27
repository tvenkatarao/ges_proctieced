#include<stdio.h>
int main()
{
int a,b,c,d;
a=0;b=5;c=a,b;
d=(a,b);
printf("c-%d d-%d\n",c,d);
int x=21,y=564,z;
z=(c,d),a,b,(x,y),x;

printf("z=%d\n",z);
printf("d=%d\n",d=(a=0)?1222:1333);

char ch=125;
ch+=10;
printf("ch=%d\n",ch);

int xx = 10;
printf("xx++=%d\t++xx=%d\txx++=%d\t++xx=%d\n",xx++,++xx,xx++,++xx);

int yy = 0xfffd;
printf("yy&1=%d\n",yy&1);
return 0;


}
