 #include<stdio.h>
struct myStruct{
    int a;
    char b;
}*ptr;
int main(){
    struct myStruct ms={400,'A'};
    printf("%d  %d",ptr->a,ptr->b);
    return 0;
}
