#include<stdio.h>
#include<stdlib.h>
void mergeArray(int arr[], int asize, int brr[], int bsize)
{
	int array[asize+bsize];
	int i,j,k=0;
	for(i=0;i<asize;i++)
	{
		array[k] = arr[i];
		k++;
	}
	for(j=0;j<bsize;j++)
	{
		array[k] = brr[j];
		k++;
	}
	printf("Merged Array Content:\n");
	for(i=0;i<(asize+bsize);i++)
	{
		printf("%d ",array[i]);
	}
		printf("\n");
}
int main()
{
	int fsize,ssize,i;
	// Array 1 Content
	printf("Enter the Size of First Array\n");
	scanf("%d",&fsize);
	int arr[fsize];
	for(i=0;i<fsize;i++)
	{
		printf("Enter the %d element of First Array\n",i+1);
		scanf("%d",&arr[i]);
	}
	// Array 2 Content
	printf("Enter the Size of Second Array\n");
	scanf("%d",&ssize);
	int brr[ssize];
	for(i=0;i<ssize;i++)
	{
		printf("Enter the %d element of Second Array\n",i+1);
		scanf("%d",&brr[i]);
	}
	mergeArray(arr,fsize,brr,ssize);
}
