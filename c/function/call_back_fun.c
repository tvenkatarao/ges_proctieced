#include<stdio.h>
int (*fp)(int x,int y);

int fun1(int x,int y)
{

	printf("in fun1 x=%d y=%d \n",x,y);

	return x*y;


}
int fun2( int (*fp)(int n,int m))
{
	int res = fp;

	return res;
}
int main()
{
	int res1,res2;
	int (*fp)(int x, int y) = &fun1;
	printf("%d\n", res1 =(*fp)(10,20));
	res2 = fun2(fp);
	printf("in main :%d\n", res2);
	return 0;

}
