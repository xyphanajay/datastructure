#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct node* create()
{
	struct node* ptr;
	ptr=malloc(sizeof(struct node*));
	ptr->data=0;
	ptr->next=NULL;
};
void insert(int data, struct node* ptr)
{
	struct node* nptr;
	nptr=(struct node*)malloc(sizeof(struct node*));
	nptr->data=data;
	ptr->data++;
	nptr->next=ptr->next;
	ptr->next=nptr;
}
void display(struct node* ptr)
{
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		printf("%d->",ptr->data);
	}printf("\n");
}
void delete(struct node* ptr)
{
	struct node* tptr;
	tptr=ptr->next;
	ptr->data-=1;
	if(ptr->next!=NULL)
	ptr->next=ptr->next->next;
	free(tptr);
}

void main()
{
	int index,data,ndata,c;
	struct node *ptr, *head;
	head=create();
	do{
		printf("1. Push 2. Pop 3. Disp 0. Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:scanf("%d",&data);
					insert(data,head);break;
			case 2:delete(head);break;
			case 3:display(head);break;
			default: break;
		};
	}while(c!=0);
}