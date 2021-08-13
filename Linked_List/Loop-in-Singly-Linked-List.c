#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void create (int data)
{
	if(head==NULL && tail==NULL)
	{
		struct Node *node = (struct Node*)malloc(sizeof(struct Node));
		node->data = data;
		node->next = NULL;
		head = tail = node;
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
	struct Node *p = head;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
		printf("\n");
}
void addLoop()
{
	struct Node *temp,*temz;
	for(temp=head;temp!=tail;temp=temp->next);
	for(temz=head;temz->next!=tail;temz=temz->next);
	temp->next = temz;
}
int checkLoop()
{
	struct Node *p, *q;
	p=q=head;
	do
	{
		printf("%d %d\n",p->data,q->data);
		p=p->next;
		q=q->next;	
		if(q!=NULL)
		{
			q=q->next;
		}
	}while((p && q) && (p!=q));
	if(p==q)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	create(1);
	create(2);
	create(3);
	create(4);
	create(5);
	display();
	if(checkLoop())
		printf("Loop in the Linked List\n");
	else
		printf("No Loop in the Linked List\n");
	addLoop();
	//display();
	if(checkLoop())
		printf("Loop in the Linked List\n");
	else
		printf("No Loop in the Linked List\n");
}
