//header files
#include <stdio.h>
#include <stdlib.h>

//declaring the struct intArr type for array
struct intArr
{
        int size;
        int *arr;
};
//Makign the struct arrNode type to be accessible by the alias intArr
typedef struct intArr intArr;

//declaring the struct node type for list
struct node 
{
       int data;
       struct node *prev;
       struct node *next;
};
//Making the struct node type to be accessible by the alias Node
typedef struct node Node;

//Declaring and defining the head pointer as NULL to show empty
Node *head = NULL;

//create node
Node *createNode(int);

//add element at the end
void append(int);

//add multiple elements
void extend(intArr *);

//add element at certain position
void insert(int, int);

//remove certain element
void removeFromList(int);

//remove element from end
void pop(void);

//reverse the list
void reverse(void);

//Print the list
void display(void);

//Insert a single element into the array
void insertIntoArray(intArr *, int);

//main function
int main(void)
{
        append(1);
        append(2);
        insert(1,3);
        
        intArr newArr;
        newArr.arr = (int *)malloc(sizeof(int));
        newArr.size = 0;
        insertIntoArray(&newArr, 8);
        insertIntoArray(&newArr, 9);
        extend(&newArr);
        display();
        reverse();
        display();
        return 0;
}

//definition for creating a single node of type Node
//---WORKING---
Node *createNode(int elem)
{
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = elem;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
}

//definition for adding an element at the end
//---WORKING---
void append(int elem)
{
        Node *newNode = createNode(elem);
        if(head == NULL) head = newNode;
        else
        {
                Node *temp = head;
                while(temp->next != NULL)
                {
                        temp = temp->next;
                }
                newNode->prev = temp;
                temp->next = newNode;
        }
}      

//definition for adding multiple elements
//---WORKING---
void extend(intArr * data)
{
        for(int i = 0; i < data->size; i++)
        {
                append(data->arr[i]);
        }
}

//definition for inserting an element at certain position
//---WORKING---
void insert(int pos, int elem)
{
        Node *newNode = createNode(elem);
        if(head == NULL || pos == 0)
        {
                newNode->next = head;
                if(head != NULL)
                {
                        head->prev = newNode;
                }
                head = newNode;
        }
        else
        {
                Node *temp = head;
                int index = 0;

                while(temp->next != NULL && index < pos - 1)
                {
                        temp = temp->next;
                        index++;
                }

                newNode->next = temp->next;
                newNode->prev = temp;

                if(temp->next != NULL)
                {
                        temp->next->prev = newNode;
                }

                temp->next = newNode;
        }
}

//Remove certain element from list
//---WORKING---
void removeFromList(int elem)
{
        Node *temp = head;
        while(temp->next != NULL && temp->data != elem)
        {
                temp = temp->next;
        }
        if(temp->data == elem)
        {
                if(temp == head)
                {
                        head = temp->next;
                        if(head != NULL)
                        {
                                head->prev = NULL;
                        }
                }
                else
                {
                        temp->prev->next = temp->next;
                        if(temp->next != NULL)
                        {
                                temp->next->prev = temp->prev;
                        }
                }
                free(temp);
        }
        else printf("Not found!");
}

//popping element from the end
//---WORKING---
void pop(void)
{
        Node *temp = head;
        while(temp->next != NULL)
        {
                temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
}

//reverse list
//---WORKING---
void reverse(void)
{
        Node *temp = NULL;
        Node *current = head;
        
        while(current != NULL)
        {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
        }
        
        if(temp != NULL)
        {
                head = temp->prev;
        }
}

//print list
//---WORKING---
void display(void)
{
        Node *temp = head;
        while(temp != NULL)
        {
                printf("[%d]->", temp->data);
                temp = temp->next;
        }
        printf("\n");
}

//Array insert an element
//---WORKING---
void insertIntoArray(intArr * newArr, int elem)
{
        newArr->arr = (int *)realloc(newArr->arr, sizeof(int)*(newArr->size+1));
        newArr->arr[newArr->size] = elem;
        newArr->size++;
}
