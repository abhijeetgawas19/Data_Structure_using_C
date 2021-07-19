#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* sorting(char *string)
{
	int len = strlen(string);
	int i,j;
	char temp;
	for(i=0;i<len-1;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(string[j]>string[j+1])
			{
				temp = string[j];
				string[j] = string[j+1];
				string[j+1] = temp;
			}
		}
	}
		return string;
}
int anagramResult(char *string1, char *string2)
{
	string1 = sorting(string1);
	string2 = sorting(string2);
	if(strcmp(string1,string2)==0)
		return 1;
	else
		return 0;
}
int main()
{
	char *string1 = (char*)malloc(100*sizeof(char));
	char *string2 = (char*)malloc(100*sizeof(char));
	printf("Enter the String 1\n");
	scanf(" %s", string1);
	printf("Enter the String 2\n");
	scanf(" %s", string2);
	string1 = strlwr(string1);
	string2 = strlwr(string2);
	if(anagramResult(string1,string2))
		printf("Strings are Anagrams");
	else
		printf("String are not Anagrams");
	return 0;
}
