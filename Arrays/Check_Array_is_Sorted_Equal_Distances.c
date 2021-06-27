#include<stdio.h>
#include<stdlib.h>
int checkArraySorted(int arr[], int size)
{
	int diff = arr[1] - arr[0];
	int i,j;
	for(i=1,j=i+1;j<size;i++,j++)
	{
		if(arr[j]-arr[i]!=diff)
			return 0;	
	}
			return 1;
}
void display(int arr[],int size)
{
	int i;
	printf("Array Elements:\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
		printf("\n");
}
int main()
{
	int i,size;
	printf("Enter the Size of Array\n");
	scanf("%d",&size);
	int array[size];
	for(i=0;i<size;i++)
	{
		printf("Enter the %d element\n",i+1);
		scanf("%d",&array[i]);
	}
	if(checkArraySorted(array,size))
	{
		printf("Array is Sorted\n");
		display(array,size);
	}
	else
	{
		printf("Array is Unsorted\n");
	}
}
