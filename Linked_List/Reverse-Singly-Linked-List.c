#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
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
		head = newNode;
		tail = newNode;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = info;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}

void display()
{
	struct Node *t = head;
	while(t)
	{
		printf("%d ",t->data);
		t=t->next;
	}
		printf("\n");
}

void reverseDisplay(struct Node *rootNode)
{
	if(rootNode!=NULL)
	{
		reverseDisplay(rootNode->next);
		printf("%d ",rootNode->data);
	}	
}

void reverseLinkedList()
{
	struct Node *current, *prev, *next_;
	current = head;
	prev = NULL;
	next_ = NULL;
	while(current!=NULL)
	{
		next_ = current->next;
		current->next = prev;
		prev = current;
		current = next_;
	}
		head = prev;
}

int main()
{
	int size,x,i;
	printf("Enter the Total Element to Inserted in Linked List\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element\n",i);
		scanf("%d",&x);
		create(x);
	}
	printf("\nLinked List Contents Forward Traversal\n");
	display();
	printf("\nLinked List Contents Backward Traversal\n");
	struct Node *beg = head;
	reverseDisplay(beg);
	printf("\n");
	reverseLinkedList();
	printf("\nLinked List Reversed Front to Back \n");
	display();
	reverseLinkedList();
	printf("\nLinked List Reversed Back to Front \n");
	display();
	return 0;
}
