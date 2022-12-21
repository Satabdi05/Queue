#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    //if it is the first node
    if(front == NULL && rear == NULL)
        //make both front and rear points to the new node
        front = rear = newNode;
    else
    {
        //add newnode in rear->next
        rear->next = newNode;

        //make the new node as the rear node
        rear = newNode;
    }
}

void dequeue()
{
    //used to free the first node after dequeue
    struct node *temp;

    if(front == NULL)
         printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {
        //take backup
        temp = front;

        //make the front node points to the next node
        //logically removing the front element
        front = front->next;

        //if front == NULL, set rear = NULL
        if(front == NULL)
            rear = NULL;

       //free the first node
       free(temp);
    }

}

void Display()
{
    struct node* temp;
	temp = front;
	if((front==NULL)&&(rear==NULL))
		printf("\nQueue is Empty");
    else
    {

        while(temp!=0)
        {

            printf("%d  ", temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    enqueue(5);
    enqueue(9);
    enqueue(3);
    printf("Queue :");
    Display();
    dequeue();
    printf("\nAfter dequeue the new Queue :");
    Display();
    dequeue();
    printf("\nAfter dequeue the new Queue :");
    Display();

    return 0;
}
