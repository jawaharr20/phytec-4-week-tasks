#include<stdio.h>
int add(int a,int b){
    return a+b;
}
int main(){
    int a=5,b=10;
    int (*ptr)(int,int);
    ptr=add;
    printf("%d",ptr(a,b));
    return 0;
}
