#include<stdio.h>
int main()
{
	// size of array
	int size,i;
	printf("Enter the Size of Array\n");
	scanf("%d",&size);
	// Create array of size 'size'
	int array[size];
	// Accept Input from User
	for(i=0;i<size;i++)
	{
		printf("Enter the %d element\n",i+1);
		scanf("%d",&array[i]);
	}
	// Display Array 
	printf("Array Elements\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",array[i]);
	}
		printf("\n");
	return 0;
}
