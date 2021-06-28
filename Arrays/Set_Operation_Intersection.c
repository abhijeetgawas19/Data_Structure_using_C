#include<stdio.h>
#include<stdlib.h>
int gcount = 0;
int duplichecker(int arr[], int size, int val)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==val)
			return 1;
	}
			return 0;
}
int* intersection_Array(int first[], int fsize, int second[], int ssize)
{
	int final_length = fsize + ssize;
	int i,j;
	int* array = (int*)malloc(final_length * sizeof(int));
	for(i=0;i<fsize;i++)
	{
		for(j=0;j<ssize;j++)
		{
			if(first[i]==second[j])
			{
				if(duplichecker(array,gcount,first[i])==0)
				{
					array[gcount] = first[i];
					gcount++;
				}
			}
		}
	}
		return array;
}
void display(int arr[], int size)
{
	int i;
	printf("Array Elements are\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
		printf("\n");
}
int main()
{
	// Array 1
	int size_1,i;
	printf("Enter the dimension of array 1\n");
	scanf("%d",&size_1);
	int array_1[size_1];
	printf("Enter the %d array elements\n",size_1);
	for(i=0;i<size_1;i++)
	{
		scanf("%d",&array_1[i]);
	}
		printf("Array 1 Elements\n");
		display(array_1,size_1);
	// Array 2
	int size_2;
	printf("Enter the dimension of array 2\n");
	scanf("%d",&size_2);
	int array_2[size_2];
	printf("Enter the %d array elements\n",size_2);
	for(i=0;i<size_2;i++)
	{
		scanf("%d",&array_2[i]);
	}
		printf("Array 2 Elements\n");
		display(array_1,size_2);
	// Intersection
	int *new_array = intersection_Array(array_1,size_1,array_2,size_2);
		printf("Intersection Result\n");
		display(new_array,gcount);
	
}
