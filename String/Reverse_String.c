#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* reverseString(char *inputString)
{
	int len,i,j;
	len = strlen(inputString); 
	char *resultString = (char*)malloc(len*sizeof(char));
	for(i=len-1,j=0;i>=0;i--,j++)
	{
		resultString[j] = inputString[i];
	}
		return resultString;
}
int main()
{
	char *string = (char*)malloc(250*sizeof(char));
	printf("Enter the Input\n");
	scanf("%[^\n]%*c",string);
	printf("Input %s\n",string);
	printf("Reverse Input %s\n",reverseString(string));
	return 0;
}
