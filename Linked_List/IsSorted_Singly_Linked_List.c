#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
void create (int data)
{
	if(head==NULL && tail==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = data;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}
int isSorted()
{
	int diffValue, newValue,x=-1;
	struct Node *first,*second;
	first=head;
	second=head->next;
	diffValue = second->data - first->data;
	for(;second!=NULL;first=first->next,second=second->next)
	{
		newValue = second->data - first->data;
		if(newValue!=diffValue)
			return -1;
	}
			return 1;
}
void display()
{
	struct Node *traverser = head;
	while(traverser)
	{
		printf("%d ",traverser->data);
		traverser = traverser->next;
	}
		printf("\n");
}
int main()
{
	int size,x,i;
	printf("Enter the Total Elements to Store\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the Element No %d\n",i);
		scanf("%d",&x);
		create(x);
	}
	printf("Linked List Contents\n");
	display(x);
	if(isSorted()==-1)
		printf("Linked List is Unsorted\n");
	else
		printf("Linked List is Sorted\n");
	return 0;
}
