#include<stdio.h>
#include<signal.h>

int main(int argc,char **argv[])
{

if(argc!=3)
{
printf("Usage:-./a.out sig_no ,pid\n");
return ;
}
kill(atoi(argv[2]),atoi(argv[1]));
perror("kill");

}
