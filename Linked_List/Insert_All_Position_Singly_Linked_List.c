#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void create(int x) // at the end
{
	if(head==NULL && tail==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}
void display()
{
	struct Node *temp=head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
		printf("\n");
}
void insertBeg(int info)
{
	if(head==NULL && tail==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = info;
		newNode->next = NULL;
		newNode->next = head;
		head = newNode;	
		tail = newNode;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = info;
		newNode->next = NULL;
		newNode->next = head;
		head = newNode;	
	}
	
}
int countNode()
{
	struct Node *temp=head;
	int count = 0;
	while(temp)
	{
		count += 1;
		temp = temp->next;
	}
		return count; 
		
}
void insertMiddle(int info, int pos)
{
	int i;
	if(pos>countNode())
	{
		printf("Position is out of context\n");
	}
	else
	{
		if(pos==1)
		{
			insertBeg(info);
		}
		else
		{
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = info;
			newNode->next = NULL;
			struct Node *back = head;
			struct Node *exact = head;
			for(i=1;i<=pos-2;i++)
				back = back->next;
			for(i=1;i<=pos-1;i++)
				exact = exact->next;
			// Actual Logic
			back->next = newNode;
			newNode->next=exact;	
		}
		
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("1. Insert Element at Beginning\n");
		printf("2. Insert Element in Middle\n");
		printf("3. Insert Element at End\n");
		printf("4. Display Elements\n");
		printf("5. Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int info;
					printf("Enter the Element to be inserted\n");
					scanf("%d",&info);
					insertBeg(info);
					break;
				}
			case 2:
				{
					int info,pos;
					printf("Enter the Element to be inserted\n");
					scanf("%d",&info);
					printf("Enter the Position to insert the element\n");
					scanf("%d",&pos);
					insertMiddle(info,pos);
					break;
				}
			case 3:
				{
					int info;
					printf("Enter the Element to be inserted\n");
					scanf("%d",&info);
					create(info);
					break;
				}
			case 4:
				{
					printf("Linked List Elements:\n");
					display();
					break;
				}
			case 5:
				{
					exit(0);
					break;
				}
			default:
				{
					printf("Invalid Option Encountered\n");
				}
		}
		
	}
}
