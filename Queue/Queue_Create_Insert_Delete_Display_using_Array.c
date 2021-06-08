#include<stdio.h>
#include<stdlib.h>
struct Queue{
	int *A;
	int front;
	int rear;
	int size;
};
struct Queue queueList;
void init(int size)
{
	queueList.A = (struct Queue*)malloc(size * sizeof(struct Queue));
	queueList.front=-1;
	queueList.rear=-1;
	queueList.size=size;
}
void enqueue(int data)
{
	if(queueList.front==-1 && queueList.rear==-1)
	{
		// First Element 
		queueList.front++;
		queueList.rear++;
		queueList.A[queueList.front]=data;
	}
	else
	{
		queueList.rear++;
		queueList.A[queueList.rear]=data;
	}
}
int dqueue()
{
	int val = queueList.A[queueList.front];
	queueList.front++;
	return val;
}
// Queue Full
int queueFull()
{
	if(queueList.rear==queueList.size-1)
		return 1;
	else
		return 0;
}
// Queue Empty
int queueEmpty()
{
	if(queueList.front>queueList.rear)
		return 1;
	else
		return 0;
}
void display()
{
	int i;
	printf("\nQueue Data:\n");
	for(i=queueList.front;i<=queueList.rear;i++)
	{
		printf("%d\t",queueList.A[i]);
	}
		printf("\n");
}
int main()
{
	// Menu
	int ch;
	init(5);
	while(1)
	{
		printf("\n1. Insert into Queue\n");
		printf("\n2. Delete from Queue\n");
		printf("\n3. Display from Queue\n");
		printf("\n4. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					if(!queueFull())
					{
						int data;
						printf("\nEnter the Data:\n");
						scanf("%d",&data);
						enqueue(data);
						printf("\n Data is Successfully Inserted\n");
					}
					else
					{
						printf("\nQueue is Full\n");
					}
					
					break;
				}
			case 2:
				{
					if(!queueEmpty())
					{
						int data = dqueue();
						printf("\n%d is Removed from Queue\n",data);
					}
					else
					{
						printf("\n Queue is Empty\n");
					}
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
					printf("\nInvalid Options\n");
				}
		}
	}
	return 0;
}
