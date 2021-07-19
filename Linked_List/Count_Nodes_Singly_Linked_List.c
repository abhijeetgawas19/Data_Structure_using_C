#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void create(int x)
{
	if(head==NULL && tail==NULL)
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		node->data = x;
		node->next=NULL;
		head=node;
		tail=node;
	}
	else
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		node->data = x;
		node->next=NULL;
		tail->next=node;
		tail=node;
	}
}
void display()
{
	struct Node *temp;
	printf("Linked List Contains\n");
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%d ",temp->data);
	}
		printf("\n");
}
int countNodes()
{
	struct Node *temp;
	int count=0;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		count++;
	}
		return count;
}
int main()
{
	int i,x,size;
	//struct Node *List;
	printf("Enter the Total numbers to insert in Linked List\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element\n",i);
		scanf("%d",&x);
		create(x);	
	}
	display();
		printf("Number of Nodes in Linked List %d",countNodes());
}
