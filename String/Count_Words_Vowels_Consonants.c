#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int wordCount (char *stringInput)
{
	int len= strlen(stringInput);
	//printf("Length of String:%d\n",len);
	int i,count=1;
	for(i=0;i<len;i++)
	{
		if(stringInput[i]==' ')
		{
			count++;
		}
	}
		return count;
}
int vowelCount (char *stringInput)
{
	int len = strlen(stringInput);
	int i,vcount=0;
	for(i=0;i<len;i++)
	{
		if(stringInput[i]=='A'||stringInput[i]=='E'||stringInput[i]=='I'||stringInput[i]=='O'||stringInput[i]=='U')
		{
			vcount++;
		}
		else if (stringInput[i]=='a'||stringInput[i]=='e'||stringInput[i]=='i'||stringInput[i]=='o'||stringInput[i]=='u')
		{
			vcount++;
		}
	}
		return vcount;
}
int consonantCount (char *stringInput)
{
	int cCount = vowelCount(stringInput);
	int spaceCount = wordCount(stringInput) - 1;
	int len = strlen(stringInput);
	len = len - (cCount + spaceCount);
	return len;
}
int main()
{
	char *inputString = (char*)malloc(250*sizeof(char));
	printf("Enter the Input String\n");
	scanf("%[^\n]%*c",inputString);
	printf("Input String : %s\n",inputString);
	printf("No of words in the Input=%d\n",wordCount(inputString));
	printf("No of vowels in the Input=%d\n",vowelCount(inputString));
	printf("No of Consontents in the Input=%d\n",consonantCount(inputString));
}
