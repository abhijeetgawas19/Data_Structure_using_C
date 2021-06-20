#include<stdio.h>
#include<stdlib.h>
struct Array
{
	int *A;
	int size;
}object;
void init(int size)
{
	object.size = size;
	object.A = (int *)malloc(object.size * sizeof(int));
	int i;
	for(i=0;i<object.size;i++)
	{
		printf("Enter the Element\n");
		scanf("%d",&object.A[i]);
	}
}
void maximumElement()
{
	int max,i;
	for(i=0;i<object.size;i++)
	{
		if(max<object.A[i])
		{
			max = object.A[i];
		}
	}
		printf("Maximum Element of Array:%d\n",max);
}
void minimumElement()
{
	int min,i;
	for(i=0;i<object.size;i++)
	{
		if(min>object.A[i])
		{
			min = object.A[i];
		}
	}
		printf("Minimum Element of Array:%d\n",min);
}
int main()
{
	int size;
	printf("Enter the Size of Array\n");
	scanf("%d",&size);
	init(size);
	maximumElement();
	minimumElement();
}
