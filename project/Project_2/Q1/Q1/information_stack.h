//Muratcan Yıldız 16050111036 

//this header combines information queue and phone stack

#define SIZE 200

typedef struct
{
	int phone;
	list person;
}info;

typedef struct
{
	int top;
	info data[SIZE];
}stack_t;



//functions

void initialize_s(stack_t *s);
int is_empty_s(stack_t *s);
int is_full_s(stack_t *s);
void push_s(stack_t *s, info item);
info pop_s(stack_t *s);



//-----------------------------------

void initialize_s(stack_t *s)
{
	s->top = -1;
}

//------------------------------------

int is_empty_s(stack_t *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//------------------------------------

int is_full_s(stack_t *s)
{
	if (s->top == SIZE - 1)
		return 1;
	return 0;
}

//-------------------------------------

void push_s(stack_t *s, info item)
{
	if (is_full_s(s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

//--------------------------------------

info pop_s(stack_t *s)
{
	info item;
	if (is_empty_s(s))
	{
		printf("Error: Stack is empty!\n");
		item = { 0000,"EMPTY","EMPTY","EMPTY","EMPTY","EMPTY" };
	}
	else
	{
		item = s->data[s->top];
		(s->top)--;
	}
	return (item);
}

