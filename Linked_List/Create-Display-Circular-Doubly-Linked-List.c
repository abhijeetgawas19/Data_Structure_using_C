#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *first = NULL;
struct Node *last = NULL;
void create(int info)
{
	if(first==NULL && last==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = info;
		first = newNode;
		last = newNode;
		newNode->next = first;
		newNode->prev = last;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = info;
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
		// Linking of Doubly Linked List
		last->next=first;
		first->prev = last;	
	}
}
void display()
{
	struct Node *temp = first;
	printf("%d ",temp->data);
	temp = temp->next;
	while(temp!=first)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
		printf("\n");
}
void rdisplay()
{
	struct Node *temp = last;
	printf("%d ",temp->data);
	temp = temp->prev;
	while(temp!=last)
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}
		printf("\n");
}
int main()
{
	int size,x,i;
	printf("Enter the Number of Elements to Insert in Linked List\n");
	scanf("%d",&size);
	printf("Enter the %d Elements\n",size);
	for(i=1;i<=size;i++)
	{
		scanf("%d",&x);
		create(x);
	}
		printf("Linked List Contents(Forward Traversal)\n");
		display();
		printf("Linked List Contents(Backward Traversal)\n");
		rdisplay();
	return 0;
}
