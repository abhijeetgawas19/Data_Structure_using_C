#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL;
void create(int data)
{
	if(head==NULL)
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		node->data = data;
		node->next=NULL;
		head = node;
	}
	else
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		node->data = data;
		node->next=NULL;
		struct Node *temp;
		for(temp=head;temp->next!=NULL;temp=temp->next);
			temp->next = node;
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
int MaximumElement()
{
	int max = 0;
	struct Node *temp = head;
	for(;temp!=NULL;temp=temp->next)
	{
		if(temp->data>max)
			max = temp->data;
	}
			return max;
}
int MinimumElement()
{
	int min = 32767;
	struct Node *temp = head;
	for(;temp!=NULL;temp=temp->next)
	{
		if(temp->data<min)
			min = temp->data;
	}
			return min;
}
int main()
{
	int size,x,i;
	printf("Enter the Size of Linked List\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element\n",i);
		scanf("%d",&x);
		create(x);
	}
		display();
		printf("Minimum Element: %d\n",MinimumElement());
		printf("Maximum Element: %d\n",MaximumElement());
	return 0;
}
