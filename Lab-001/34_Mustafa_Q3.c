

#include <stdio.h>
#include <string.h>
int show(char* a){
	printf("Operator name: %s\n",a);
	return 0;
}
int main()
{
	char input;
	printf("Enter input: ");
	scanf("%c",&input);
	switch(input){
		case '+':
			show("Addition");
			break;
		case '-':
			show("Subtraction");
			break;
		case '*':
			show("Multipication");
			break;
		case '/':
			show("Division");
			break;
		case '%':
			show("Modulus");
			break;
		default:
			show("Unknown");
			break;
	}
	return 0;
}