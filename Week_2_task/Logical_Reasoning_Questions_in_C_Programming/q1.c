#include<stdio.h>
int main(){

	int a=5;
	printf("%d ",a++ + ++a);
	return 0;

}


/*
 Step-by-step breakdown (Assume: a = 5)
Expression:

c
Copy
Edit
a++ + ++a
➤ Evaluation Order:
⚠️ Not strictly defined in C, but we assume left to right for explanation.

1️⃣ a++
Value of a++ is 5 (original value of a)

Then a becomes 6

2️⃣ ++a
Now a is incremented again: a = 7

Value of ++a is 7

3️⃣ Add them:
c
Copy
Edit
a++ (5) + ++a (7) = 12
*/

