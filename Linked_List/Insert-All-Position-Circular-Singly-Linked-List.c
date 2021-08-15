#include<stdio.h>
#include<stdlib.h>
static int countNodes = 0;
struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void insertBeg(int ele)
{
	countNodes = countNodes + 1;
	if(head==NULL && tail==NULL)
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = ele;
		head = newNode;
		tail = newNode;
		newNode->next = head;
	}
	else
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = ele;
		newNode->next = head;
		head = newNode;
		tail->next=head;
	}
}
void insertEnd(int ele)
{
	countNodes = countNodes + 1;
	if(head==NULL && tail==NULL)
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = ele;
		head = newNode;
		tail = newNode;
		newNode->next = head;
	}
	else
	{
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = ele;
		tail->next = newNode;
		tail = newNode;
		newNode->next=head;
	}
}
void insertPosition(int ele, int pos)
{
	if(pos==1)
	{
		insertBeg(ele);
	}
	else if(pos==countNodes)
	{
		insertEnd(ele);
	}
	else if(pos>countNodes)
	{
		printf("Position is out of Range\n");
	}
	else
	{
		// Any position apart from above mentioned postions
		struct Node *exact = head;
		struct Node *back = head;
		int i;
		for(i=1;i<=pos-1;i++)
			exact = exact->next;
		for(i=1;i<=pos-2;i++)
			back = back->next;
		// Node Creation
		struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = ele;
		back->next = newNode;
		newNode->next = exact;
		countNodes = countNodes + 1;		
	}
}
void display()
{
	struct Node *t = head;
	printf("%d ",t->data);
	t = t->next;
	while(t!=head)
	{
		printf("%d ",t->data);
		t = t->next;
	}
		printf("\n");
}
int main()
{
	int ch;
	while(1)
	{
		printf("1. Insert at the beginning of the Linked List\n");
		printf("2. Insert at the specific location of the Linked List\n");
		printf("3. Insert at the end of the Linked List\n");
		printf("4. Display the Linked List\n");
		printf("5. Exit\n");
		printf("Enter the Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int x;
					printf("Enter the Element\n");
					scanf("%d",&x);
					insertBeg(x);
					break;
				}
			case 2:
				{
					int pos,x;
					printf("Enter the Position\n");
					scanf("%d",&pos);
					printf("Enter the Element\n");
					scanf("%d",&x);
					insertPosition(x,pos);
					break;
				}
			case 3:
				{
					int x;
					printf("Enter the Element\n");
					scanf("%d",&x);
					insertEnd(x);
					break;
				}
			case 4:
				{
					printf("Linked List Content are:\n");
					display();
					break;
				}
			case 5:
				{
					exit(0);
					break;
				}
		}
	}
	return 0;
}
