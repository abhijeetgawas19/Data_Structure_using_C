#include<stdio.h>
#include<stdlib.h>
int lengthFinder(char *s)
{
	int len=0,i;
	for(i=0;s[i]!='\0';i++)
	{
		len++;
	}
		return len;
}
int main()
{
	char String[100];
	printf("Enter the String\n");
	scanf("%[^\n]%*c",String);
	printf("Length of String %s is %d",String,lengthFinder(String));
}
