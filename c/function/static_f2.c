/* hidden function */
static int local_fun(int x)
{
	printf("in local_fun :%d\n",x);
	return x*x;
}


/*function pointer with external linkage*/
int (*fptr)(int) = local_fun;

