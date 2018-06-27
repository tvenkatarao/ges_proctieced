#include<stdio.h>
int find_substr(char *s1,char *s2)
{
	register int t;
	char *p,*q;
	for(t=0;s1[t];t++){
		p=&s1[t];
		q = s2;

		while(*q && *q == *p)
		{
			p++;
			q++;

		}
		if(!*q) return t;
	}

	return -1;
}

int main()
{
if(find_substr("c is fun","is") != -1)
printf("sub string is found.");
return 0;

}
