#include<stdio.h>
#include<stdlib.h>
struct Array{
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
		printf("Enter the %d number\n",i+1);
		scanf("%d",&object.A[i]);
	}
}
int sum()
{
	int sum = 0,i;
	for(i=0;i<object.size;i++)
	{
		sum = sum + object.A[i];
	}
		return sum;
}
double avg()
{
	int total = sum();
	double avg = total/object.size;
	return avg;
}
void display()
{
	int i;
	printf("Array Elements\n");
	for(i=0;i<object.size;i++)
	{
		printf("%d ",object.A[i]);
	}
}
int main()
{
	int size,ch;
	printf("Enter the Size of Array\n");
	scanf("%d",&size);
	init(size);
	while(1)
	{
		printf("1. Sum of Array Elements\n");
		printf("2. Average of Array Elements\n");
		printf("3. Display Array Elements\n");
		printf("4. Exit\n");
		printf("Enter the Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("Sum of Elements are %d\n",sum());
					break;
				}
			case 2:
				{
					printf("Average of Elements are %lf\n",avg());
					break;
				}
			case 3:
				{
					display();
					break;
				}
			case 4:
				{
					exit(0);
					break;
				}
			default:
				{
					printf("Invalid Options\n");
				}
		}
	}
	return 0;
}
