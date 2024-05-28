#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct node 
{
       int array[MAX_SIZE];
       int front;
       int rear;
} Queue;

int isfull(Queue *);
int isempty(Queue *);
void enqueue(Queue *, int);
void dequeue(Queue *);
void display(Queue *);

int main(void)
{
        Queue Q;
        memset(Q.array, 0, sizeof(Q.array));
        Q.front = -1;
        Q.rear = -1;
        
        int choice = 0;
        while(choice != 4)
        {
                printf("<---ENTER YOUR CHOICE!--->\n1. ENQUEUE\n2. DEQUEUE\n3. PRINT\n4. EXIT\n==>");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1: 
                                int elem = 0;
                                printf("Enter element: ");
                                scanf("%d", &elem);
                                enqueue(&Q, elem);
                                break;

                        case 2:
                                dequeue(&Q);
                                break;

                        case 3:
                                display(&Q);
                                break;

                        case 4:
                                printf("BYE! BYE!");
                                break;
                }
        }
        return 0;
}

int isfull(Queue * data)
{
        return data->rear == MAX_SIZE-1;        
}

int isempty(Queue * data)
{
        return data->front == -1 && data->rear == -1; 
}

void enqueue(Queue * data, int elem)
{
        if(isfull(data)) 
        {
                printf("FULL!\n");
                return;
        }
        data->rear++;
        data->array[data->rear] = elem;
        if(data->front == -1) data->front = 0;
        printf("ENQUEUED : [%d]\n", data->array[data->rear]);
        return;
}

void dequeue(Queue * data)
{
        if(isempty(data))
        {
                printf("EMPTY!\n");
                return;
        }
        printf("DEQUEUED : [%d]\n", data->array[data->front]);
        data->array[data->front] = 0;
        data->front++;
        if(data->front == data->rear == MAX_SIZE)
                data->front = data->rear = -1;
        return;
}

void display(Queue * data)
{
        if(isempty(data))
        {
                printf("EMPTY!\n");
                return;
        }
        printf("QUEUE : ");
        for(int i = data->front; i <= data->rear; i++)
        {
               printf("[%d] ", data->array[i]); 
        }
        printf("\n");
}
