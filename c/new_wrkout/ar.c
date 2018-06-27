 #include<stdio.h>
//#include<conio.h>
void main(){
    int a[]={5,10,15};
    int i=0,num;
    num=a[++i]+ ++i+(++i);
    printf("%d",num);
}

