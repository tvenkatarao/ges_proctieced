#include<stdio.h>
#include<stdlib.h>

struct st
{
	int a,b;
	char ch;
};

void f1(struct st parm);

int main()
{
	struct st arg;
	arg.a = 100;
	f1(arg);
	return 0;
}
void f1(struct st parm)
{
	printf("%d ",parm.a);

}
