#include<stdio.h>
#include<stdlib.h>
int count = 0;
struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
};
struct Node *head = NULL;
struct Node *tail = NULL;
void create (int d)
{
	count = count + 1;
	if(head==NULL && tail==NULL)
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = d;
		newNode->next = NULL;
		newNode->prev = NULL;
		head = tail = newNode;
	}
	else
	{
		struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = d;
		newNode->prev = tail;
		tail->next = newNode;
		newNode->next = NULL;
		tail = newNode;
	}
}
int deleteBeg()
{
	struct Node *newdata = head;
	int data = newdata->data;
	head = head->next;
	head->prev = NULL;
	free(newdata);
	count = count - 1;
	return data;
}
int deleteMiddle(int pos)
{
	if(pos==1)
	{
		deleteBeg();
	}
	else if(pos==count)
	{
		deleteEnd();
	}
	else if(pos > count)
	{
		return -1;
	}
	else
	{
		count = count - 1;
		int i,j;
		struct Node *exact = head;
		struct Node *back = head;
		for(i=1;i<=pos-1;i++,exact=exact->next);
		for(j=1;j<=pos-2;j++,back=back->next);
			// Grab the Node
			struct Node *newNode = exact;
			int data = newNode->data;
			exact = exact->next;
			// Linking
			back->next = exact;
			exact->prev = back;
			free(newNode);
			return data;
	}
}
int deleteEnd()
{
	struct Node *temp = head;
	while(temp->next!=tail)
	{
		temp = temp->next;
	}
	int data = tail->data;
	temp = temp->next;
	tail = tail->prev;
	tail->next = NULL;
	free(temp);
	return data;
}
void display()
{
	struct Node *trav = head;
	while(trav)
	{
		printf("%d ",trav->data);
		trav = trav->next;
	}
		printf("\n");
}
int main()
{
	int size,i,x;
	printf("Enter the Number of Elements to Insert in Linked List\n");
	scanf("%d",&size);
	for(i=1;i<=size;i++)
	{
		printf("Enter the %d element\n",i);
		scanf("%d",&x);
		create(x);
	}
	while(1)
	{
		printf("1. Delete First Element\n");
		printf("2. Delete Positioned Element\n");
		printf("3. Delete Last Element\n");
		printf("4. Display Linked List\n");
		printf("5. Exit\n");
		printf("Enter the Choice\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				{
					printf("Element Deleted %d\n",deleteBeg());
					break;
				}
			case 2:
				{
					int pos;
					printf("Enter the Position\n");
					scanf("%d",&pos);
					int data = deleteMiddle(pos);
					if(data == -1)
						printf("Invalid Position\n");
					else
						printf("Element Deleted %d\n",data);
					break;
				}
			case 3:
				{
					printf("Element Deleted %d\n",deleteEnd());
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
					printf("Invalid Options\n");
				}
		}
		
	}
	return 0;
}
