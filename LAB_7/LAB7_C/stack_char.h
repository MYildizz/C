//
// Stack Implementation, CENG104
// Author: Evren
#include <stdio.h>
#include <string.h>
#define STACK_SIZE  100

typedef  char  SType;

SType  STACK_EMPTY = '!';

typedef struct
{	int	top;
    int id;
    char name[STACK_SIZE];    
	char data[STACK_SIZE];
} stack_t;

//Functions in this file...
void initialize_s (stack_t *s);
int is_empty_s (stack_t *s);
int is_full_s (stack_t *s);
void push (stack_t *s, SType item);
void pop (stack_t *s);

//------------------------------------------------------------------------------

void initialize_s (stack_t *s)
{
	s->top = -1;
}

//------------------------------------------------------------------------------

int is_empty_s (stack_t *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int is_full_s (stack_t *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void push (stack_t *s, int id,char name[],char info[])
{
	if (is_full_s (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		(s+s->top)->id= id;
		strcpy((s+s->top)->name,name);
		strcpy((s+s->top)->data,info);
	}
}

//------------------------------------------------------------------------------

void pop (stack_t *s)
{
	SType item;
	if (is_empty_s(s))
	{	printf("Error: Stack is empty!\n");
			
	}
	else
	{
	       if(strcmp((s+s->top)->name,"Oracle")==0)	
	       {
	       	printf("%d %s %s \n",(s+s->top)->id,(s+s->top)->name,(s+s->top)->data);
		   }
	       
		(s->top)--;
	}		    	
	
}
