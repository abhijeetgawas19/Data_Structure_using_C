#include<stdio.h>
#include<stdlib.h>
struct Array{
	int *A;
	int size;
}object;
void init(int length)
{
	object.size=length;
	object.A = (int *)malloc(object.size * sizeof(int));
	int i;
	for(i=0;i<object.size;i++)
	{
		object.A[i] = i+1;
	}
}
int delete_index(int index)
{
	int value = -1,i,j;
	if(index>object.size)
	{
		return value;
	}
	else
	{
		value = object.A[index];
		printf("%d\n",value);
		for(i=index,j=index+1;j<object.size;i++,j++)
		{
			object.A[i] = object.A[j];
		}
			object.A[i]=0;
	}
		return value;	
}
int display()
{
	int i;
	for(i=0;i<object.size;i++)
	{
		printf("%d ",object.A[i]);
	}
		printf("\n");
}
int main(void)
{
	int size;
	printf("Enter the Size of Array\n");
	scanf("%d",&size);
	init(size);
	int ch;
	while(1)
	{
		printf("1. Delete an Element \n");
		printf("2. Display the Array\n");
		printf("3. Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int x;
					printf("Enter the Index from 0 to %d\n",object.size-1);
					scanf("%d",&x);
					int val = delete_index(x);
					if(val!=-1)
						printf("%d element is deleted from index %d\n",val,x);
					else
						printf("Invalid Index\n");
					break;
				}
			case 2:
				{
					printf("Array Elements are as follows\n");
					display();
					break;
				}
			case 3:
				{
					exit(0);
					break;
				}
			default:
				{
					printf("Invalid Choice\n");
				}
		}
	}
}
