#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int palindromicString(char *string1)
{
	char *stringReverse = (char *)malloc(strlen(string1)*sizeof(char));
	int len = strlen(string1);
	int i,j;
	for(i=0,j=len-1;j>=0;i++,j--)
	{
		stringReverse[i] = string1[j];
	}
	if(strcmp(string1,stringReverse)==0)	
		return 1;
	else
		return 0;
}
int main()
{
	char *string1 = (char*)malloc(100*sizeof(char));
	printf("Enter the String \n");
	scanf(" %s",string1);
	if(palindromicString(string1))
		printf("String is Palindromic\n",string1);
	else
		printf("String is Not Palindromic\n",string1);
}
