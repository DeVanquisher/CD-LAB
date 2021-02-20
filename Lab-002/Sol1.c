#include <stdio.h> 
#include <string.h>

//Defining DFA
int defineDFA(){
	int NUMBER_OF_STATES;
	printf("............................Setting the states of DFA......................\n");
	printf("How many states you want to set for your DFA: ");
	//Total number of states
	scanf("%d",&NUMBER_OF_STATES);
	char states[NUMBER_OF_STATES];
	int NUMBER_OF_INPUT_SYMBOLS = NUMBER_OF_STATES-1;
	char inputSymboles[NUMBER_OF_INPUT_SYMBOLS];
	printf("\nGive the names for the %d states in single character:\n",NUMBER_OF_STATES);
	for (int i = 0; i < NUMBER_OF_STATES; ++i)
	{
		printf("State-%d :",i+1);
		scanf("%s",&states[i]);
	}
	printf("Enter the sequence of %d input symboles to reach final state: \n",NUMBER_OF_INPUT_SYMBOLS);
	//Setting input symboles
	for (int i = 0; i < NUMBER_OF_INPUT_SYMBOLS; ++i)
	{
		printf("Input-%d, from state-%c to state-%c:",i+1,states[i],states[i+1]);
		scanf("%s",&inputSymboles[i]);
	}
	//Diagram of DFA
	printf("Diagram of the DFA\n");
	for (int i = 0; i < NUMBER_OF_STATES; ++i)
	{
		if (i < NUMBER_OF_STATES-1)
		
			printf("-->%c--(%c)",states[i],inputSymboles[i]);
		
		else if(i == NUMBER_OF_STATES-1)
			printf("-->%c\n",states[i]);
	}
	return 0;
}
int checkString(){
	
	return 0;
}
int main()
{
	printf("------------------------------(DFA defining)------------------------------\n");
	defineDFA();
	return 0;
}