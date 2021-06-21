#include<stdio.h>
#include<stdlib.h>
void reverse(int arr[], int size)
{
	int i,j,temp;
	if(size%2!=0)
	{
		for(i=0,j=size-1;i!=j;i++,j--)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	else
	{
		for(i=0,j=size-1;i<=j;i++,j--)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}	
	}
}
int main()
{
	int size,i;
	printf("Enter the Size\n");
	scanf("%d",&size);
	int Array[size];
	for(i=0;i<size;i++)
	{
		printf("Enter the %d Element\n",i+1);
		scanf("%d",&Array[i]);
	}
	printf("Array Traversal\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",Array[i]);
	}
		printf("\n");
	reverse(Array,size);
	printf("Array Traversal\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",Array[i]);
	}
		printf("\n");
	return 0;
}
