#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int LinearSearch(int arr[],int,int);
int main()
{
	int size,i,key;
	printf("Enter the Size of the Array\n");
	scanf("%d",&size);
	int arrayInteger[size];
	printf("Enter the %d elements\n",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arrayInteger[i]);
	}
	printf("Enter the Key to be Searched\n");
	scanf("%d",&key);
	int status = LinearSearch(arrayInteger,size,key);
	if(status)
		printf("%d element exist\n",key);
	else
		printf("%d element absent\n",key);
}
int LinearSearch(int arrayInteger[],int size,int key)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arrayInteger[i]==key)
			return 1;
	}
		return 0;
}
