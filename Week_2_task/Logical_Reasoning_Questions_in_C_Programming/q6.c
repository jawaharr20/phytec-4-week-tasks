#include<stdio.h>
int main(){

	int a = 10;
int b = a++ + ++a;
printf("%d", b); // 23 
	return 0;
}

/*
tep 1: a++
Use a = 10 for now

Then a = a + 1 → a = 11

Value used in expression: 10

🧠 Step 2: ++a
Now a = 11, then increment it first → a = 12

Value used in expression: 12

🧠 Final Addition:
c
Copy
Edit
b = 10 + 12 = 22

*/
