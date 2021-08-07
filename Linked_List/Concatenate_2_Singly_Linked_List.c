#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head_1 = NULL;
struct Node *tail_1 = NULL;
struct Node *head_2 = NULL;
struct Node *tail_2 = NULL;
void create(int pos, int data)
{
	if(pos == 1)
	{
		if(head_1==NULL && tail_1==NULL)
		{
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = data;
			newNode->next = NULL;
			head_1 = newNode;
			tail_1 = newNode;
		}
		else
		{
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = data;
			newNode->next = NULL;
			tail_1->next = newNode;
			tail_1 = newNode;
		}	
	}
	if(pos == 2)
	{
		if(head_2==NULL && tail_2==NULL)
		{
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = data;
			newNode->next = NULL;
			head_2 = newNode;
			tail_2 = newNode;
		}
		else
		{
			struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
			newNode->data = data;
			newNode->next = NULL;
			tail_2->next = newNode;
			tail_2 = newNode;
		}	
	}
	
}
void display(int pos)
{
	if(pos==1)
	{
		struct Node *temp = head_1;
		while(temp)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
			printf("\n");	
	}
	if(pos==2)
	{
		struct Node *temp = head_2;
		while(temp)
		{
			printf("%d ",temp->data);
			temp = temp->next;
		}
			printf("\n");	
	}
	
}
void concate(struct Node *tail_1, struct Node *head_2)
{
	tail_1->next = head_2;
	tail_1 = head_2;
}
int main()
{
	// Linked List 1
	int i,x,size_1,size_2,pos_1,pos_2;
	printf("Enter the Linked List Number\n");
	scanf("%d",&pos_1);
	printf("Enter the Total Elements to Insert in Linked List %d\n",pos_1);
	scanf("%d",&size_1);
	for(i=1;i<=size_1;i++)
	{
		printf("Enter the %d element \n",i);
		scanf("%d",&x);
		create(pos_1,x);
	}	
	// Linked List 2
	printf("Enter the Linked List Number\n");
	scanf("%d",&pos_2);
	printf("Enter the Total Elements to Insert in Linked List %d\n",pos_2);
	scanf("%d",&size_2);
	for(i=1;i<=size_2;i++)
	{
		printf("Enter the %d element \n",i);
		scanf("%d",&x);
		create(pos_2,x);
	}
	printf("Linked List %d Elements\n",pos_1);
	display(pos_1);
	printf("Linked List %d Elements\n",pos_2);
	display(pos_2);
	concate(tail_1,head_2);
	printf("Linked List Concatenated Together\n");
	display(pos_1);
	return 0;
}
