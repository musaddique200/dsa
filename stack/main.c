#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct stack
{
        int top;
        int array[MAX];
} Stack;

int isempty(Stack *s);
int isfull(Stack *s);
void push(Stack *s, int elem);
void pop(Stack *s);
void display(Stack *s);

int main(void)
{
        Stack s;
        s.top = -1;
      
        int choice = 0;
        while(choice != 4)
        {
                printf("<---STACK OPERATIONS!--->\n1. PUSH\n2. POP\n3. PRINT STACK\nENTER YOUR CHOICE : ");
                scanf("%d", &choice);
                switch(choice)
                {
                        case 1 : 
                                int data = 0;
                                printf("ENTER ELEMENT TO PUSH : ");
                                scanf("%d", &data);
                                push(&s, data);
                                break;
                        case 2:
                                pop(&s);
                                break;
                        case 3: 
                                display(&s);
                                break;
                        case 4:
                                printf("<---ENDED!--->\n");
                                break;

               }
               printf("\n\n\n");
         }
        return 0;
}

int isempty(Stack *s)
{
        return s->top == -1;
}

int isfull(Stack *s)
{
        return s->top == MAX - 1;
}

void push(Stack *s, int elem)
{
        if(isfull(s)) 
        {
                printf("PUSH FAILURE! STACK OVERFLOW!\n");
                return; 
        }
        
        s->top++;
        s->array[s->top] = elem;
        printf("PUSHED : [%d]\n", s->array[s->top]);
}

void pop(Stack *s)
{
        if(isempty(s))
        {
                printf("POP FAILURE! STACK UNDERFLOW!\n");
                return;
        }

        printf("POPPED : [%d]\n", s->array[s->top]);
        s->array[s->top] = 0;
        s->top--;
}

void display(Stack *s)
{
        if(isempty(s))
        {
                printf("CAN'T PRINT! STACK UNDERFLOW!\n");
                return;
        }
        
        printf("STACK : ");
        for(int i = s->top; i > -1; i--)
        {
                printf("[%d] ", s->array[i]);
        }
        printf("\n");
}

