#include<stdio.h>
#include<stdlib.h>
int statusSorted(int arr[],int size)
{
	int i,j;
	for(i=0,j=i+1;j<size;i++,j++)
	{
		if(arr[i]>arr[j])
			return 0;
	}
			return 1;
}
int display(int arr[], int size)
{
	int i;
	printf("Array Elements\n");
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
		display(array,size);
	if(statusSorted(array,size))
		printf("Array is Sorted\n");
	else
		printf("Array is Unsorted\n");
	return 0;
}
