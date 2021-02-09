//This code is exclusively written by Mustafa Kamaal
#include <stdio.h>
#include <ctype.h>
int main()    
{
	int totCount=0;
	int digCount=0;
	int spaceCount=0;
	int lineCount=1;
	int spCharCount=-1;
	int alphCount=0;
	FILE *fp ;  
	char ch ;  
	fp = fopen("sample.txt","r") ;  
	while ( 1 )  
	{  
		ch = fgetc ( fp ) ;
		//counting for digits
		if (isdigit(ch)!=0)
		 	digCount++;
		//counting for spaces
		if (ch==' ')
		{
		 	spaceCount++;
		}
		if (ch=='\n')
		{
			lineCount++;
		}
		if (isdigit(ch)==0 && isalpha(ch)==0 && ch!=' ' && ch!='\n')
		{
			spCharCount++;
		}
		if (isalpha(ch)!=0)
		{
			alphCount++;
		}
		//checking end of the file
		if ( ch == EOF )  
			break ;  
		printf("%c",ch) ;
		//total characters count
		totCount++; 
	}  
	fclose (fp ) ;
	//part-a
	printf("\n\nTotal characters:\t%d\n",totCount);
	//part-b
	printf("Number of digits:\t%d\n",digCount);
	//part-c
	printf("Number of spaces:\t%d\n",spaceCount);
	//part-d
	printf("Number of lines:\t%d\n",lineCount);
	//part-e
	printf("Number of specialChar:\t%d\n",spCharCount);
	//part-f
	printf("Number of alphabet:\t%d\n",alphCount);
}
