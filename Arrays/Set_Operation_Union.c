#include<stdio.h>
#include<stdlib.h>
int gcount=0;
int dupliChecker(int arr[], int size,int val)
{
	int i,result=0;
	for(i=0;i<size;i++)
	{
		if(arr[i]==val)
		{
			result = 1;
			return result;
		}
	}
		return result;
}
int* unionOperation (int arr_1[], int size_1, int arr_2[], int size_2)
{
	int size_3 = size_1 + size_2;
	int *arr_3 = (int *)malloc(size_3 * sizeof(int));
	int i,j,flag;
	// Array 1
	arr_3[gcount] = arr_1[0];
	gcount++;
	for(i=1;i<size_1;i++)
	{
		int status = dupliChecker(arr_3,gcount,arr_1[i]);
		if(status==0)
		{
			arr_3[gcount]=arr_1[i];
			gcount++;
		}
	}
	// Array 2
	for(j=0;j<size_2;j++)
	{
		int status = dupliChecker(arr_3,gcount,arr_2[j]);
		if(status==0)
		{
			arr_3[gcount]=arr_2[j];
			gcount++;
		}
	}
		return arr_3;
}
void display(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
		printf("\n");
}
int main()
{
	// Array 1
	int i,size_1;
	printf("Enter the dimension of Array 1\n");
	scanf("%d",&size_1);
	int arr_1[size_1];
	printf("Enter the %d Elements of Array 1\n",size_1);
	for(i=0;i<size_1;i++)
	{
		scanf("%d",&arr_1[i]);
	}
	printf("Array 1\n");
	display(arr_1,size_1);
	// Array 2
	int size_2;
	printf("Enter the dimension of Array 2\n");
	scanf("%d",&size_2);
	int arr_2[size_2];
	printf("Enter the %d Elements of Array 2\n",size_2);
	for(i=0;i<size_2;i++)
	{
		scanf("%d",&arr_2[i]);
	}
	printf("Array 2\n");
	display(arr_2,size_2);
	int *array_3 = unionOperation(arr_1,size_1,arr_2,size_2);
	printf("Union of Arrays\n");
	display(array_3,gcount);
}
