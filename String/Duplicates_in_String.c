#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Result{
	char *string;
	int *count;
	int scount;
	int ccount;
};
void init(struct Result *p)
{
	p->string = (char *)malloc(100*sizeof(char));
	p->count = (int *)malloc(50*sizeof(int));
	p->scount=0;
	p->ccount=0;
}
void uniqueCharacterCheck(struct Result *p, char *stringInput)
{
	int i,j,flag;
	int ln = strlen(stringInput);
	char c;
	for(i=0;i<ln;i++)
	{
		c = stringInput[i];
		flag=0;
		// check in object string wheather the character avaliable
		for(j=0;j<p->scount;j++)
		{
			if(c==p->string[j])
			{
				flag++;
				break;	
			}
		}
		if(flag==0)
		{
			p->string[p->scount] = c;
			p->scount++;
		}
	}
	// Print Unique Characters
	printf("Characters: ");
	for(i=0;i<p->scount;i++)
	{
		printf("%c ",p->string[i]);
	}
		printf("\n");
	// Add count 
	for(i=0;i<p->scount;i++)
	{
		flag=0;
		for(j=0;j<ln;j++)
		{
			if(p->string[i]==stringInput[j])
			{
				flag++;
			}
		}
		p->count[p->ccount] = flag;
		p->ccount++;
	}
	// Print Unique Characters
	printf("Duplicates: ");
	for(i=0;i<p->ccount;i++)
	{
		printf("%d ",p->count[i]);
	}
	printf("\n");
	
}
int main()
{
	char *stringInput = (char *)malloc(100*sizeof(char));
	printf("Enter the Input String\n");
	scanf("%[^\n]%*c",stringInput);
	struct Result r;
	init(&r);
	uniqueCharacterCheck(&r,stringInput);
	return 0;
}
