#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
struct Stack
{
	int data;
	int top;
	int *A;
};
struct Stack obj;
void init()
{
	obj.top = -1;
	obj.A = (int *)malloc(MAXSIZE * sizeof(int));
}
void push(int data)
{
	obj.top = obj.top + 1;
	obj.A[obj.top] = data;
}
int pop()
{
	int x = obj.A[obj.top];
	obj.top--;
	return x;
	
}
int stackEmpty()
{
	if(obj.top==-1)
		return 1;
	else
		return 0;
}
int stackFull()
{
	if(obj.top==4)
		return 1;
	else
		return 0;	
}
void display()
{
	int i;
	for(i=obj.top;i>=0;i--)
	{
		printf("%d\n",obj.A[i]);
	}
		printf("\n");
}
int main()
{
	int n;
	init();
	while(1)
	{
		printf("\n1. Insert into Stack\n");
		printf("\n2. Delete from Stack\n");
		printf("\n3. Display Stack\n");
		printf("\n4. Exit \n");
		printf("\n Enter the choice\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				{
					if(!stackFull())
					{
						int x;
						printf("\nEnter the Data\n");
						scanf("%d",&x);
						push(x);	
						printf("Top:%d\n",obj.top);
					}
					else
					{
						printf("\nStack is Full\n");
					}
					break;
				}
			case 2:
				{
					if(!stackEmpty())
					{
						int x = pop();
						printf("Deleted Element:%d\n",x);
					}
					else
					{
						printf("\n Stack is Empty \n");
					}
					break;
				}
			case 3:
				{
					printf("\nStack Content\n");
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
