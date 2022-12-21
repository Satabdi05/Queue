#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int data;
    struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;

// Enqueue() operation on a queue
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

// Dequeue() operation on a queue
void dequeue()
{
    //used to freeing the first node after dequeue
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

// Display all elements of the queue
void display()
{
    struct node * temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty\n");
    } else
        {
        printf("The queue is \n");
        temp = front;               ///stored backup of front in temp
        while (temp)                //after calling dequeue operation front would be moved
            {                       // to print element of 0th position used temp
            printf("%d--->", temp -> data);
            temp = temp -> next;            //temp->next would be stoed at temp
            }
        printf("NULL\n\n");
        }
}

int main() {
   /* int choice, value;
    printf("\nImplementation of Queue using Linked List\n");
    while (choice != 4)
        {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", & choice);
        switch (choice)
        {
           case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", & value);
                enqueue(value);
                break;
            case 2:
               dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }}*/
        {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Queue :");
    display();
    dequeue();
    printf("After dequeue the new Queue :");

    display();
    dequeue();
    printf("After dequeue the new Queue :");
    display();

    return 0;
}
}
