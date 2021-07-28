#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
	int data;
	struct LinkedList *next;
};
struct LinkedList *head=NULL;
struct LinkedList *tail=NULL;
void create(int data)
{
	if(head == NULL && tail == NULL)
	{
		struct LinkedList *newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		struct LinkedList *newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
		newNode->data = data;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
	}
}
void display()
{
	struct LinkedList *temp = head;
	while(temp)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
		printf("\n");
}
int totalNodes()
{
	struct LinkedList *temp = head;
	int count = 1;
	if(head==NULL)
	{
		return -1;
	}
	else
	{
		while(temp)
		{
			count = count + 1;
			temp = temp->next;
		}
		return count;	
	}
}
int deleteFirst()
{
	int x = -1;
	if(head==NULL)
	{
		return x;
	}
	else
	{
		struct LinkedList *newNode = head;
		head = head->next;
		x = newNode->data;
		free(newNode);
	}
		return x;
}
int deleteMiddle(int pos)
{
	int x = -1;
	if(head==NULL || pos>totalNodes() || pos < 0)
	{
		return x;
	}
	else if(pos==totalNodes())
	{
		deleteEnd();
	}
	else
	{
		struct LinkedList *back=head, *exact=head, *newNode;
		int i;
		for(i=1;i<=pos-2;i++)
		{
			back = back->next;	
		}
		for(i=1;i<=pos-1;i++)
		{
			exact = exact->next;
		}
			newNode = exact;
			back->next = exact->next;
			x = newNode->data;
			free(newNode);
	}
		return x;
}
int deleteEnd()
{
	int x = -1;
	if(head==NULL)
	{
		return x;
	}
	else
	{
		struct LinkedList *trav,*newNode;
		for(trav=head;trav->next!=tail;trav=trav->next);
			newNode = tail;
			tail = trav;
			tail->next = NULL;
			x = newNode->data;
			free(newNode);
	}
		return x;
}
int main()
{
	int i,x,size;
	printf("Enter the Dimension of Array\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the Element\n");
		scanf("%d",&x);
		create(x);
	}
	printf("Linked List Elements:\n");
	display();
	while(1)
	{
		printf("1. Delete First Element\n");
		printf("2. Delete Element from Position\n");
		printf("3. Delete Last Element\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		printf("Enter the Choice\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				{
					int x = deleteFirst();
					if(x==-1)
						printf("Linked List Empty\n");
					else
						printf("First Element Deleted %d\n",x);
					break;
				}
			case 2:
				{
					int pos;
					printf("Enter the Position\n");
					scanf("%d",&pos);
					int x = deleteMiddle(pos);
					if(x==-1)
						printf("Linked List Empty or Position is Invalid\n");
					else
						printf("%d element deleted from %d location\n",x,pos);
					break;
				}
			case 3:
				{
					int x = deleteEnd();
					if(x==-1)
						printf("Linked List is Empty\n");
					else
						printf("Last element %d is deleted\n",x);
					break;
				}
			case 4:
				{
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
					printf("Invalid Option Do try Again\n");
				}
		}
	}
	return 0;
}
