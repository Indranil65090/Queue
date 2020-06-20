#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct queue
{
	struct node *front;
	struct node *rear;
};
struct queue *q;
void create(struct queue *q);
struct queue *insert(struct queue *q,int val);
struct queue *delete_element(struct queue *q);
struct queue *display(struct queue *q);
int peek(struct queue *q);
int main()
{
	int val,option;
	create(q);
	do
	{
		printf("\n******************MAIN MENU*************************");
		printf("\n1.CREATE");
		printf("\n2.DELETE");
		printf("\n3.PEEK");
		printf("\n5.DISPLAY");
		printf("*******************************************************");
		printf("\n\nEnter your option:");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the number to be inserted in the queue:");
				scanf("%d",&val);
				q=insert(q,val);
				break;
			case 2:
				q=delete_element(q);
				break;
			case 3:
				val=peek(q);
				printf("\nThe value stored at the top of the queue:%d",val);
				break;
			case 4:
				q=display(q);
				break;			
		}
	}while(option!=5);
	return 0;
}
void create(struct queue *q)
{
	q->rear=NULL;
	q->front=NULL;
}
struct queue *insert(struct queue *q,int val)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	if(q->front==NULL)
	{
		q->front=ptr;
		q->rear=ptr;
		q->front->next=q->rear->next=NULL;
	}
	else
	{
		q->rear->next=ptr;
		q->rear=ptr;
		q->rear->next=NULL;
	}
	return q;
}
struct queue *display(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(ptr==NULL)
	{
		printf("\nQUEUE IS EMPTY");
	}
	else
	{
		printf("\n");
		while(ptr!=q->rear)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\t",ptr->data);
	}
	return q;
}
int peek(struct queue *q)
{
	return q->front->data;
}
struct queue *delete_element(struct queue *q)
{
	struct node *ptr;
	ptr=q->front;
	if(q->front==NULL)
	{
		printf("\nUNDERFLOW");
	}
	else
	{
		q->front=q->front->next;
		printf("\nThe value to be deleted:%d",ptr->data);
		free(ptr);
	}
	return q;
}
