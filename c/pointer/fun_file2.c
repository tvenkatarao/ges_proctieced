/* hidden function */
static int local_foo(int x)
{
return x*x;
}


/*function with external linkage*/
int foo(int x)
{

return local_foo(x);

}


/*function pointer with external linkage*/
int (*foop)(int) = local_foo;


