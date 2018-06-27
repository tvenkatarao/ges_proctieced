#include<stdio.h>
void trim(char *s);
int main()
{
	char str[]=" www . firm codes . com ";
	trim(str);
	printf("%s",str);
	return 0;
}
void trim(char *s)
{
	char *trimed=s;
	while(*s) // Check for end of string until null character appear
	{
		*trimed=*s; //shift each character
		if( *(s+1)==' ' ) //Check for space if space appear jump that address
			++s;
		if( *(s+1)=='\0' ) //look for null character if null present, terminate	shifting
				*(trimed+1)='\0';
		trimed++;
		s++;
	}
}
