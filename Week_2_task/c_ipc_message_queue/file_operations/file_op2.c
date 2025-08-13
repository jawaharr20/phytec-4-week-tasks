#include<stdio.h>
#include<string.h>
int main(){

	FILE *file=fopen("hello.txt","w");
	if(file==NULL){
	
		printf("failed ");
		return 1;
	}

	char text[]="hello from terminal";
	fwrite(text,sizeof(char),strlen(text),file);

	fclose(file);
	return 0;
}
