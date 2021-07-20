#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL;
void create(int x)
{
	if(head==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = NULL;
		head=newNode;
	}
	else
	{
		struct Node *temp, *newNode;
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = NULL;
		for(temp=head;temp->next!=NULL;temp=temp->next);
			temp->next=newNode;
	}
}
void sum()
{
	struct Node *p=head;
	int sum;
	while(p!=NULL)
	{
		sum = sum + p->data;
		p=p->next;
	}
		printf("Sum of Elements = %d",sum);
}
void display()
{
	struct Node *p=head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
		printf("\n");
}
int main()
{
	int i,size,data;
	printf("Enter the Size of LinkedList\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element\n",i);
		scanf("%d",&data);
		create(data);
	}
		display();
		sum();
	return 0;
}
