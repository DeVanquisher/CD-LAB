#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
//common function for comparing strings
int compString(char userAString[], char definedString[], char userString[])
{
	if (strcmp(userAString,definedString) == 0)
		printf("\nResult--> %s satisfies the defined DFA 'ACCEPTED'\n",userString);
	else
		printf("\nResult--> %s does not satisfy the defined DFA 'NOT ACCEPTED'\n",userString);
	return 0;
}
//test string with defined DFA
int substring(char userString[], char definedString[],int userStringLen, int NUMBER_OF_INPUT_SYMBOLS)
{
	char userAString[NUMBER_OF_INPUT_SYMBOLS];
	if (userStringLen > NUMBER_OF_INPUT_SYMBOLS)
	{
		for (int i = 0; i < userStringLen/NUMBER_OF_INPUT_SYMBOLS; ++i)
		{
			for (int j = 0; j < NUMBER_OF_INPUT_SYMBOLS; ++j)
			{
				userAString[i] = userString[i];
			}
			if (strcmp(userAString,definedString)==0)
			{
				printf("%s ACCEPTED\n",userString);
				//goto end;

			}
		}
	}
	else if (userStringLen < NUMBER_OF_INPUT_SYMBOLS)
	{
		printf("Less number of input symboles:(\nDefined DFA required %d input symbols.\n",NUMBER_OF_INPUT_SYMBOLS);
	}
	else
		strcpy(userAString, userString);
	//Comparing user string with correct string value
	compString(userAString,definedString,userString);	
	return 0;
}
int endWith(char userString[], char definedString[],int userStringLen, int NUMBER_OF_INPUT_SYMBOLS)
{

	char userAString[NUMBER_OF_INPUT_SYMBOLS];//New veriable to hold the user's string
	int startingIndex = userStringLen-NUMBER_OF_INPUT_SYMBOLS;
	if (userStringLen > NUMBER_OF_INPUT_SYMBOLS)
	{
		for (int i = 0; i < NUMBER_OF_INPUT_SYMBOLS; ++i)
		{
			//Inserting characters from user string to new veriable
			userAString[i] = userString[startingIndex+i];			
		}
	}
	else if (userStringLen < NUMBER_OF_INPUT_SYMBOLS)
	{
		printf("Less number of input symboles:(\nDefined DFA required %d input symbols.\n",NUMBER_OF_INPUT_SYMBOLS);
	}
	else
		//Copying character as it is from user input to new veriable 
		strcpy(userAString, userString);
	//Comparing user string with correct string value
	compString(userAString,definedString,userString);
	return 0;
}

int begWith(char userString[], char definedString[],int userStringLen, int NUMBER_OF_INPUT_SYMBOLS)
{
	char userAString[NUMBER_OF_INPUT_SYMBOLS];
	if (userStringLen > NUMBER_OF_INPUT_SYMBOLS)
	{
		for (int i = 0; i < NUMBER_OF_INPUT_SYMBOLS; ++i)
		{
			// Inserting characters from user string to new veriable
			userAString[i] = userString[i];
			
		}
	}
	else if (userStringLen < NUMBER_OF_INPUT_SYMBOLS)
	{
		printf("Less number of input symboles:(\nDefined DFA required %d input symbols.\n",NUMBER_OF_INPUT_SYMBOLS);
	}
	else
		strcpy(userAString, userString);
	//Comparing user string with correct string value
	compString(userAString,definedString,userString);	
	return 0;
}
//Defining DFA
int defineDFA(){
	int NUMBER_OF_INPUT_SYMBOLS;
	printf("How many input symbols you want to set for your DFA: ");
	//Total number of states
	scanf("%d",&NUMBER_OF_INPUT_SYMBOLS);
	int NUMBER_OF_STATES = NUMBER_OF_INPUT_SYMBOLS+1;
	char inputSymboles[NUMBER_OF_INPUT_SYMBOLS];
	int states[NUMBER_OF_STATES];
	// printf("\nGive the names for the %d states in single character:\n",NUMBER_OF_STATES);
	// for (int i = 0; i < NUMBER_OF_STATES; ++i)
	// {
	// 	printf("State-%d :",i+1);
	// 	scanf("%s",&states[i]);
	// }
	//Creating names for states
	for (int i = 0; i < NUMBER_OF_STATES; ++i)
	{
		states[i] = i;
	}
	printf("Enter the sequence of %d input symboles to reach final state: \n",NUMBER_OF_INPUT_SYMBOLS);
	//Setting input symboles
	for (int i = 0; i < NUMBER_OF_INPUT_SYMBOLS; ++i)
	{
		printf("Input-%d, from state-Q%d to state-Q%d:",i+1,states[i],states[i+1]);
		scanf("%s",&inputSymboles[i]);
	}
	//Select type of DFA
	int KEY;
	printf("What type of DFA you want to create?\nEnter a correct key to select type..\n");
	typeOfDFA:
		printf("Enter\t1 for beginning with given string\n\t2 for ending with given string\n\t3 for substring\n--> ");
	scanf("%d",&KEY);
	if (KEY == 1 || KEY == 2 || KEY == 3)
	{
		//Diagram of DFA
		printf("\n\nDefined DFA :\n\n\t");
		for (int i = 0; i < NUMBER_OF_STATES; ++i)
		{
			if (i < NUMBER_OF_STATES-1)
			
				printf("-->Q%d--(%c)",states[i],inputSymboles[i]);
			
			else if(i == NUMBER_OF_STATES-1)
				printf("-->|Q%d|\n\nInitial state:\tQ0\nFinal state:\tQ%d\n",states[i],states[i]);
		}
		printf("\n......DFA has been generated sucessfully......\n");
		//User given string
		char inputString[20];
		userString:
			printf("To check the DFA enter the string: ");
		scanf("%s",inputString);
		int len = strlen(inputString);
		printf("-------------(Inserting the string into defined DFA)-------------\n");
		//Analysis
		switch(KEY)
		{
			case 1:
				begWith(inputString,inputSymboles,len,NUMBER_OF_INPUT_SYMBOLS);
				break;
			case 2:
				endWith(inputString,inputSymboles,len,NUMBER_OF_INPUT_SYMBOLS);
				break;
			case 3:
				substring(inputString,inputSymboles,len,NUMBER_OF_INPUT_SYMBOLS);
				break;
			default:
				printf("Unidentified type of DFA assigned\n");
				goto typeOfDFA;
				break;
		}
	}
	else
	{
		printf(".........Wrong key.........");
		goto typeOfDFA;
	}

	return 0;
}
int main()
{
	printf("#######################################(Defining the DFA)#######################################\n");
	defineDFA();
	end: 
		printf("\n\n###########################################(End)################################################\n");
	return 0;
}