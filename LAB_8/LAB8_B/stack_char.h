//
// Stack Implementation, CENG104
// Author: Evren
#define STACK_SIZE  100
#include <string.h>

typedef  char  SType;

SType  STACK_EMPTY = '!';

typedef struct
{	int	top;
	SType data[STACK_SIZE][STACK_SIZE];
} stack_t;

//Functions in this file...
void initialize_s (stack_t *s);
int is_empty_s (stack_t *s);
int is_full_s (stack_t *s);
void push (stack_t *s, SType *item);
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

void push (stack_t *s, SType *item)
{
	if (is_full_s (s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		strcpy(s->data[s->top],item);
	}
}

//------------------------------------------------------------------------------

void pop (stack_t *s,SType *item)
{
	
	if (is_empty_s(s))
	{	printf("Error: Stack is empty!\n");
		strcpy(item,"ERROR");
	}
	else
	{	strcpy(item,s->data[s->top]);
		(s->top)--;
	}		    	
	
}
