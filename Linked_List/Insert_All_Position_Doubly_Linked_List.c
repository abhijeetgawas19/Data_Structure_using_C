#include<stdio.h>
#include<stdlib.h>
int count=0;
struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void insertBeg(int info)
{
	count = count + 1;
	if(head==NULL && tail==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = info;
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = info;
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}
void insertEnd(int info)
{
		count = count + 1;
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = info;
		newNode->next = NULL;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
}
void insertMiddle(int info,int pos)
{
	if(pos==1)
	{
		insertBeg(info);
	}
	else if(pos==count)
	{
		insertEnd(info);
	}
	else if(pos>count)
	{
		printf("Invalid Position");
	}
	else
	{
		count = count + 1;
		struct Node *exact = head;
		struct Node *back = head;
		int i,j;
		for(i=1;i<=pos-2;i++,back=back->next);
		for(j=1;j<=pos-1;j++,exact=exact->next);
			// Node Creation
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = info;
			back->next = newNode;
			newNode->prev = back;
			newNode->next = exact;
			exact->prev = newNode;
	}
}
void display()
{
	printf("Linked List Content\n");
	struct Node *temp = head;
	while(temp)
	{
		printf("%d\t",temp->data);
		temp = temp->next;
	}
		printf("\n");
}
int main()
{
	int ch;
	while(1)
	{
		printf("1. Insert at the Beginning of Linked List\n");
		printf("2. Insert at the End of Linked List\n");
		printf("3. Insert at particular Position of Linked List\n");
		printf("4. Display Linked List\n");
		printf("5. Exit\n");
		printf("Enter the Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int ele;
					printf("Enter the Element\n");
					scanf("%d",&ele);
					insertBeg(ele);
					break;
				}
			case 2:
				{
					int ele;
					printf("Enter the Element\n");
					scanf("%d",&ele);
					insertEnd(ele);
					break;
					
				}
			case 3:
				{
					int ele,pos;
					printf("Enter the Element\n");
					scanf("%d",&ele);
					printf("Enter the Position\n");
					scanf("%d",&pos);
					insertMiddle(ele,pos);
					break;
				}
			case 4:
				{
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
					printf("Irrevalant Choice Try again\n");
				}
		}
		
	}
	return 0;
}
