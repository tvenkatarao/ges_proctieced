#include<stdio.h>
#include<stdlib.h>

int main()
{
printf("running ps with system\n");
system("ps -ax");
printf("done\n");
exit(0);
}
