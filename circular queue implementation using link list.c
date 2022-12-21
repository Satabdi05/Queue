#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d) //Insert elements in Queue
{
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = d;
	newNode->next = NULL;
	if((rear==NULL)&&(front==NULL))
	{
		front = rear = newNode;
		rear->next = front;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
		newNode->next = front;
	}
}
void dequeue() // Delete an element from Queue
{
	struct node* temp;
	temp = front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
	else if(front == rear){
		front = rear = NULL;
		free(temp);
	}
	else{
		front = front->next;
		rear->next = front;
		free(temp);
	}
}
// Print the elements of Queue
void print()
{
	struct node* temp;
	temp = front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
	else{
		do{
			printf("%d  ",temp->data);
			temp = temp->next;
		}while(temp != front);
	}
}


int main()
{
    enqueue(5);
    enqueue(9);
    enqueue(3);
    printf("Queue :");
    print();
    dequeue();
    printf("\nAfter dequeue the new Queue :");
    print();
    dequeue();
    printf("\nAfter dequeue the new Queue :");
    print();

    return 0;
}
