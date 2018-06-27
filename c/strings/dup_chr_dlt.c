#include<stdio.h>
#define ARRAY_LEN 256
#include<stdbool.h>

int main()
{
	bool demoArray[ARRAY_LEN] = {0};
	int i=0,j=0;
	char temp,*str;
	printf("enter the string :");
	scanf("%s",str);

	while(*(str+i)){

  		temp = *(str+i);
		if(demoArray[temp] == 0)
		{
			demoArray[temp]=1;
			*(str+j) = *(str+i);
			j++;
		}
		i++;

	}
str[j]='\0';
printf("\n%s\n",str);
}
