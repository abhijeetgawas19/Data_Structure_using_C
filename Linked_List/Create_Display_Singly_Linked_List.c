#include<stdio.h>
#include<stdlib.h>
// Structure
struct Node{
	int data;
	struct Node *next;
};
struct Node *head=NULL;
struct Node *tail=NULL;
struct Node *LL;
void insert(int data)
{
	if(head==NULL)
	{
		struct Node *p = (struct Node *)malloc(sizeof(struct Node));
		p->data = data;
		p->next=NULL;
		head=p;
		tail=p;
	}
	else
	{
		struct Node *x = (struct Node *)malloc(sizeof(struct Node));
		x->data=data;
		x->next=NULL;
		tail->next=x;
		tail=x;
	}
}
void display()
{
	struct Node *temp=head;
	printf("Linked List Data:\t");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	struct Node *List = NULL;
	int n;
	while(1)
	{
		printf("\n1. Insert into Linked List\n");
		printf("\n2. Display the Linked List\n");
		printf("\n3. Exit\n");
		printf("\nEnter your choice\n");
		scanf("%d",&n);
		switch(n)	
		{
			case 1:
				{
					int data;
					printf("Enter the Data\n");
					scanf("%d",&data);
					insert(data);
					break;
				}
			case 2:
				{
					display();
					break;
				}
			case 3:
				{
					exit(0);
					break;
				}
			default:
				{
					printf("Invalid Option Selected Do Try Again!!!!!\n");
				}
		}
	}
}
