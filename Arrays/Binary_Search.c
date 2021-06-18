#include<stdio.h>
#include<stdlib.h>
int* sortArray(int arr[],int size)
{
	int i,j,temp;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
		return arr;
}
int BinarySearch(int brr[],int size,int key)
{
	int low,high,mid,status=0;
	low = 0;
	high = size;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(brr[mid]==key)
		{
			status = 1;
			break;
		}
		
		if(brr[mid]>key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
		return status;
}
int main()
{
	int size,i;
	printf("Enter the Size\n");
	scanf("%d",&size);
	int arr[size];
	int *brr;
	for(i=0;i<size;i++)
	{
		printf("Enter the %d Element\n",i+1);
		scanf("%d",&arr[i]);
	}
		brr = sortArray(arr,size);
	printf("Sorted Array\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",brr[i]);
	}
		printf("\n");
	int key;
	printf("Enter the Key\n");
	scanf("%d",&key);
	int status = BinarySearch(brr,size,key);
	if(status)
		printf("Element Exist\n");
	else
		printf("Element Didn't Exist\n");
}
