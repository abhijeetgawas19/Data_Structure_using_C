#include<stdio.h>
#include<stdlib.h>
void add(int *A, int index, int data)
{
	A[index] = data;
}
void display(int *A,int size)
{
	int i;
	printf("\nArray Elements\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t",A[i]);
	}
		printf("\n");
}
int main()
{
	int size,ch,i;
	printf("\nEnter the Size of Array\n");
	scanf("%d",&size);
	int *A = (int *)malloc(size * sizeof(int));
	// Initialize Array
	for(i=0;i<size;i++)
	{
		A[i] = 0;
	}
	while(1)
	{
		printf("\n1. Enter the Element to Array\n");
		printf("\n2. Display Array\n");
		printf("\n3. Exit\n");
		printf("\n Enter Your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int index;
					printf("\n Enter the Index \n");
					scanf("%d",&index);
					if(index<size)
					{
						int data;
						printf("\n Enter the Element\n");
						scanf("%d",&data);
						add(A,index,data);
					}
					else
					{
						printf("\n Error: ArrayIndexOutOfBound \n");
					}
					break;
				}
			case 2:
				{
					display(A,size);
					break;
				}
			default:
				{
					printf("\n Invalid Option Encountered \n");
				}
		}
	}
}
