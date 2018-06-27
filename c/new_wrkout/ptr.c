 #include<stdio.h>
int main(){
    float **(*ptr)[4]=(float **(*)[4])0;
    ptr+=5;
    printf("%d  %d",ptr,sizeof ptr);
    return 0;
}

