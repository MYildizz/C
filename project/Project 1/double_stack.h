// Muratcan Yýldýz 16050111036

// AYBU CENG 104 Computer Programming II Term Assignment Question 1
//DOUBLESTACK

#include<stdio.h>
#define MAX 100

typedef struct
{
	int top1;
	int top2;
	int data[MAX];
}stack_t;


//Functions in the file

void initialize_s1(stack_t *s);
void initialize_s2(stack_t *s);

int is_empty_s1(stack_t *s);
int is_empty_s2(stack_t *s);

int is_full_s1(stack_t *s);
int is_full_s2(stack_t *s);

void push1(stack_t *s, int item);
void push2(stack_t *s, int item);

int pop1(stack_t *s);
int pop2(stack_t *s);


//---------------------------------------------------



void initialize_s1(stack_t *s)
{
	s->top1 = -1;

}

//---------------------------------------------------

void initialize_s2(stack_t *s)
{
	s->top2 = MAX ;
}


//----------------------------------------------------


int is_empty_s1(stack_t *s)
{
	if (s->top1 == -1)
		return 1;
	return 0;
}


//----------------------------------------------------


int is_empty_s2(stack_t *s)
{
	if (s->top2 == MAX )
		return 1;
	return 0;
}


//-----------------------------------------------------



int is_full_s1(stack_t *s)
{
	if (s->top1 == MAX - 1)
		return 1;
	return 0;
}


//-----------------------------------------------------



int is_full_s2(stack_t *s)
{
	if (s->top2 == -1)
		return 1;
	return 0;
}


//-----------------------------------------------------



void push1(stack_t *s, int item)
{
	if (is_full_s1(s))
		printf("stack 1 is full !! \n");
	else
	{
		s->top1++;
		s->data[s->top1] = item;

	}
}


//------------------------------------------------------



void push2(stack_t *s, int item)
{
	if (is_full_s2(s))
		printf("stack 2 is full !! \n");
	else
	{
		s->top2--;
		s->data[s->top2] = item;
	}
}


//-------------------------------------------------------



int pop1(stack_t *s)
{
	int item;

	if (is_empty_s1(s))
	{
		printf("Stack 1 is empty !! \n");
		item = '*';
	}
	else
	{
		item = s->data[s->top1];
		(s->top1)--;
	}
	return item;
}


//-------------------------------------------------------


int pop2(stack_t *s)
{
	int item;

	if (is_empty_s2(s))
	{
		printf("Stack 2 is empty !! \n");
		item = '*';
	}
	else
	{
		item = s->data[s->top2];
		(s->top2)++;
	}
	return item;
}

