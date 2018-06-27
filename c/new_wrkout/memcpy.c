#include <stdio.h>
#include <string.h>

int main ()
{
				char str1[]="This is a line.-======ddsfsdmfksdkfmlsdflsdflmsdl";
				char str2[40];
				char str3[40];

				memcpy (str2, str1, strlen(str1) + 1);
				memcpy (str3, "copy successful", 16);

				printf ("str1= %s\n str2= %s\n str3= %s\n", str1, str2, str3);

				return 0;

}

