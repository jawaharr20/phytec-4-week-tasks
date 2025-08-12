#include<stdio.h>
#include<stdlib.h>
int main(){

	FILE *fp=fopen("sample.txt","r");


	if(fp==NULL){
	
		printf(" nothing inside ");
	}
	
	int ch= fgets(fp);
	putchar(ch);

	return 0;
	
}
