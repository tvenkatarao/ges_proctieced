#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,j,count=1,k=0;
void fun_str(char *);
int main()
{
	char s[20];
	printf("enter the string :\n");
	scanf("%s",s);

	for(i=0,k=i+1;i<strlen(s)-1;i++)
	{
		if(s[i] == s[k])
		{
			for(j=i;j<strlen(s)-1;j++)
			{
				if(s[j] == s[j+1])
					++count;
				else{

				break;
				}
			}
	
		}

		printf("%d\n",count);
		switch(count)
		{
			case 2: s[i+1] = '2';
				count =1;
				fun_str(s);
				i=j;
				break;
			case 3: s[i+1] = '3';
				count =1;
				fun_str(s);
				i=j;
				break;

			case 4: s[i+1] = '4';
				count =1;
				fun_str(s);
				i=j;
				break;

			case 5: s[i+1] = '5';
				count =1;
				fun_str(s);
				i=j;
				break;

			case 6: s[i+1] = '6';
				count =1;
				fun_str(s);
				i=j;
				break;

			case 7: s[i+1] = '7';
				count =1;
				fun_str(s);
				i=j;
				break;

			case 8: s[i+1] = '8';
				count =1;
				fun_str(s);
				i=j;
				break;

			case 9: s[i+1] = '9';
				count =1;
				fun_str(s);
				i=j;
				break;
			default:exit(0);
		}


		//	i=i+1;
		/*fun(char *s)
		  {
		  for(i=i+2;i<strlen(s);i++)
		  {
		  s[i] =s[j+1]; 
		  j++;
		  }
		  }*/


	}



	s[i]='\0';
	printf("string: %s\n",s);

	return 0;

}

void fun_str(char *s)
{
	for(i=i+2;i<strlen(s);i++)
	{
		int k=j;
		s[i] = s[k+1];
		k++;
	}
}
