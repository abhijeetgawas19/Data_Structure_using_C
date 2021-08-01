#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *rear = NULL;
void create (int x)
{
	if(head==NULL || rear==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next =NULL;
		head = newNode;
		rear = newNode;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next =NULL;
		rear->next = newNode;
		rear = newNode;
	}
}
void display()
{
	struct Node *temp = head;
	printf("\nLinked List Elements\n");
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
		printf("\n");
}
void deleteElements(struct Node *position)
{
	struct Node *back;
	struct Node *exact=position;
	for(back=head;back->next!=position;back=back->next);
	back->next = exact->next;
	printf("\n%d Data Deleted\n",position->data);
}
void duplicate()
{
	struct Node *element,*subelement;
	for(element=head;element!=NULL;element=element->next)
	{
		for(subelement=element->next;subelement!=NULL;subelement=subelement->next)
		{
			if(element->data == subelement->data)
			{
				deleteElements(subelement);
			}			
		}
	}
}
int main()
{
	int i,size,x;
	printf("Enter the Total Elements to Insert into Linked List\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element\n",i);
		scanf("%d",&x);
		create(x);
	}
	printf("\nLinked List Before Duplicates\n");
	display();
	duplicate();
	printf("\nLinked List After Removing Duplicates\n");
	display();
}
