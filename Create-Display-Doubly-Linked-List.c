#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void create(int info)
{
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
		newNode->next = NULL;
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}
void forward_display()
{
	struct Node *temp=head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
		printf("\n");
}
void reverse_display()
{
	struct Node *temp=tail;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->prev;
	}
		printf("\n");
}
int main()
{
	int n,size,i;
	printf("Enter the Number of Elements to Insert\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element\n",i);
		scanf("%d",&n);
		create(n);
	}
		printf("Forward Traversal\n");
		forward_display();
		printf("Reverse Traversal\n");
		reverse_display();
}
