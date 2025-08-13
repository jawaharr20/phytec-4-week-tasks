#include<stdio.h>
int multiply(int a,int b){
	return a*b;
}
int add(int a,int b,(*gg)(int,int)()){
gg=multiply;
gg();

}

int main(){

	int (* fp)(int ,int ,multiply);
	fp =add;
	printf("%d",fp(5,10,multiply));
	return 0;

}///// correct one

/* 
 #include <stdio.h>

int multiply(int a, int b) {
    return a * b;
}

int add(int a, int b, int (*gg)(int, int)) {
    return gg(a, b);  // call the passed function
}

int main() {
    int result = add(5, 10, multiply);  // pass function as argument
    printf("Result = %d\n", result);    // Output: 50
    return 0;
}
*/
