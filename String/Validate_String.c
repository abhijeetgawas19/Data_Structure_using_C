#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int spaceCounter(char *inputString)
{
	int len = strlen(inputString);
	int count=0,i;
	for(i=0;i<len;i++)
	{
		if(inputString[i]==' ')
			count++;
	}
		return count;
}
int validString(char *inputString)
{
	int len,validCount,i;
	validCount = 0;
	len = strlen(inputString);
	for(i=0;i<len;i++)
	{
		if((inputString[i]>=65 && inputString[i]<=90) || (inputString[i]>=97 && inputString[i]<=122))
		{
			validCount = validCount + 1;
		}
	}
	len = len - spaceCounter(inputString);
	if(validCount == len)
		return 1;
	else
		return 0;
}
int main()
{
	char *inputString = (char *)malloc(250*sizeof(char));
	printf("Enter the Input String\n");
	scanf("%[^\n]%*c",inputString);
	printf("Input String : %s\n",inputString);
	if(validString(inputString))
		printf("Valid String\n");
	else
		printf("Invalid String\n");
}
