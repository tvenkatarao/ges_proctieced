#include<stdio.h>
void rev_rec(char *str)
{
	if(*str){
		rev_rec(str+1);
		printf("%c",*str);
	}
}
int main()
{
	char s[] = "naveen";

	rev_rec(s);

}
