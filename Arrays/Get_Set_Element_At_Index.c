#include<stdio.h>
#include<stdlib.h>
struct Array{
	int *array;
	int size;
}object;
void init(int len)
{
	object.size = len;
	object.array = (int *)malloc(object.size*sizeof(int));
	int i;
	for(i=0;i<object.size;i++)
	{
		object.array[i] = i + 1;
	}
}
int get(int index)
{
	if(index>object.size)
		return -1;
	else
		return object.array[index];
}
int set(int index)
{
	if(index>object.size)
	{
		return -1;	
	}
	else
	{
		int element;
		printf("Enter the Element\n");
		scanf("%d",&element);
		object.array[index] = element;
		return 1;
	}
}
void display()
{
	int i;
	printf("Array Elements are:\n");
	for(i=0;i<object.size;i++)
	{
		printf("%d ",object.array[i]);
	}
		printf("\n");
}
int main()
{
	int size;
	printf("Enter the Size of Array\n");
	scanf("%d",&size);
	init(size);
	int ch;
	while(1)
	{
		printf("1. Get Element from Index\n");
		printf("2. Set Element to Index\n");
		printf("3. Display Array Elements\n");
		printf("4. Exit\n");
		printf("Enter the choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int index;
					printf("Enter the Index\n");
					scanf("%d",&index);
					int status = get(index);
					if(status==-1)
						printf("Array Index is Invalid\n");
					else
						printf("Element at %d index is %d\n",index,status);
					break;
				}
			case 2:
				{
					int index;
					printf("Enter the Index\n");
					scanf("%d",&index);
					int status = set(index);
					if(status==-1)
						printf("Array Index is Invalid\n");
					else
						printf("Element Updated\n");
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
					printf("Invalid Option\n");
				}
		}
	}
	return 0;
}
