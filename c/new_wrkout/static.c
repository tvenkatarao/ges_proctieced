 #include<stdio.h>
int main(){
    int a=5;
    static int b=a;
    printf("%d %d",a,b);
    return 0;
}

