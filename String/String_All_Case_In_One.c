#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* UpperCase(char *UpperCaseString)
{
	int len,i = strlen(UpperCaseString);
	for(i=0;i<len;i++)
	{
		if(UpperCaseString[i]>=97 && UpperCaseString[i]<=122)
		{
			UpperCaseString[i] = UpperCaseString[i] - 32;
		}
	}
		return UpperCaseString;
}
char* LowerCase(char *LowerCaseString)
{
	int len,i = strlen(LowerCaseString);
	for(i=0;i<len;i++)
	{
		if(LowerCaseString[i]>=65 && LowerCaseString[i]<=90)
		{
			LowerCaseString[i] = LowerCaseString[i] + 32;
		}
	}
		return LowerCaseString;
}
char* MixedCase(char *MixedCaseString)
{
	int len,i = strlen(MixedCaseString);
	for(i=0;i<len;i++)
	{
		if(MixedCaseString[i]>=65 && MixedCaseString[i]<=90)
		{
			MixedCaseString[i] = MixedCaseString[i] + 32;
		}
		else if(MixedCaseString[i]>=97 && MixedCaseString[i]<=122)
		{
			MixedCaseString[i] = MixedCaseString[i] - 32;
		}
	}
		return MixedCaseString;
}
int main()
{
	int ch;
	while(1)
	{
		printf("1. Convert String to Uppercase\n");
		printf("2. Convert String to LowerCase\n");
		printf("3. Convert String based on Text\n");
		printf("4. Exit\n");
		printf("Enter the Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					char *inputString =(char*)malloc(100*sizeof(char));
					printf("Enter the Input String\n");
					scanf("%s ",inputString);
					printf("String is %s\n",inputString);
					inputString = UpperCase(inputString);
					printf("String is Converted to UpperCase=%s\n",inputString);
					free(inputString);
					break;
				}
			case 2:
				{
					char *inputString =(char*)malloc(100*sizeof(char));
					printf("Enter the Input String\n");
					scanf("%s ",inputString);
					printf("String is %s\n",inputString);
					inputString = LowerCase(inputString);
					printf("String is Converted to LowerCase=%s\n",inputString);
					free(inputString);
					break;
				}
			case 3:
				{
					char *inputString =(char*)malloc(100*sizeof(char));
					printf("Enter the Input String\n");
					scanf("%s ",inputString);
					printf("String is %s\n",inputString);
					inputString = MixedCase(inputString);
					printf("String is Converted to Mixcase=%s\n",inputString);
					free(inputString);
					break;
				}
			case 4:
				{
					exit(0);
					break;
				}
			default:
				{
					printf("Invalid Choice\n");
				}
		}	
	}
}
