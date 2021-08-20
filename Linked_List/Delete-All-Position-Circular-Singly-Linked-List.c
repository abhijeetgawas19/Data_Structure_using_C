#include<stdio.h>
#include<stdlib.h>
static int count = 0;
struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void create(int x)
{
	count = count + 1;
	if(head==NULL && tail==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		head = newNode;
		tail = newNode;
		newNode->next=head;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		tail->next = newNode;
		tail = newNode;
		newNode->next = head;
	}
}
int deleteBeg()
{
	count = count - 1;
	struct Node *element = head;
	head = head->next;
	tail->next = head;
	int data = element->data;
	free(element);
	return data;
}
int deleteEnd()
{
	count = count - 1;
	struct Node *prev = head;
	struct Node *ex;
	while(prev->next!=tail)
	{
		prev = prev->next;
	}
		ex = prev->next;
		tail = prev;
		tail->next = head;
		int data = ex->data;
		free(ex);
		return data;
}
int deletePosition(int pos)
{
	if(pos>count)
	{
		return -1;
	}
	else if(pos==1)
	{
		deleteBeg();
	}
	else if(pos==count)
	{
		deleteEnd();
	}
	else
	{
		int i;
		struct Node *temp_1=head;
		struct Node *temp_2=head;
		for(i=1;i<=pos-2;temp_1=temp_1->next,i++);
		for(i=1;i<=pos-1;temp_2=temp_2->next,i++);
		temp_1->next = temp_2->next;
		int data = temp_2->data;
		free(temp_2);
		count = count - 1;
		return data;
	}
}
void display()
{
	struct Node *temp = head;
	printf("%d ",temp->data);
	temp = temp->next;
	while(temp!=head)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
		printf("\n");
}
int main()
{
	int x,size,i,ch;
	printf("Enter the Number of Elements to be Inserted\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element\n",i);
		scanf("%d",&x);
		create(x);
	}
	while(1)
	{
		printf("1.Delete the First Element of Linked List\n");
		printf("2.Delete the Last Element of Linked List\n");
		printf("3.Delete the Positioned Element of Linked List\n");
		printf("4.Display the Linked List\n");
		printf("5.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int element = deleteBeg();
					printf("Deleted Element:%d\n",element);
					break;
				}
			case 2:
				{
					int element = deleteEnd();
					printf("Deleted Element:%d\n",element);
					break;
				}
			case 3:
				{
					int pos;
					printf("Enter the Position of element\n");
					scanf("%d",&pos);
					int element = deletePosition(pos);
					if(element==-1)
						printf("Element didn't exist\n");
					else
						printf("Delete Element:%d\n",element);
					break;
				}
			case 4:
				{
					printf("Count of Nodes %d\n",count);
					printf("Linked List contents:\n");
					display();
					break;
				}
			case 5:
				{
					exit(0);
					break;
				}
			default:
				{
					printf("Invalid Option is selected\n");
				}
		}
	}
}
