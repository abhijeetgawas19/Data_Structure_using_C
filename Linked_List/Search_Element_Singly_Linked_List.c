#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void create(int data)
{
	if(head==NULL && tail==NULL)
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		node->data = data;
		node->next = NULL;
		head = node;
		tail = node;
	}
	else
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		node->data = data;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
}
void display()
{
	struct Node *temp = head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
		printf("\n");
}
int searchElement(int data)
{
	struct Node *temp = head;
	for(;temp!=NULL;temp=temp->next)
	{
		if(temp->data==data)
			return 1;
	}
			return 0;
}
int main()
{
	int size,i,x;
	printf("Enter the Size of Linked List\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d Element \n",i);
		scanf("%d",&x);
		create(x);
	}
		display();
		printf("Enter to be searched\n");
		scanf("%d",&x);
	if(searchElement(x))
		printf("Element Exist\n");
	else
		printf("Element didn\'t Exist\n");
	return 0;
}
