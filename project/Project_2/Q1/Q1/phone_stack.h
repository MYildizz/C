//Muratcan Yıldız 16050111036

//This header gets phone numbers

#define SIZE  200

typedef struct
{

	int	top;
	int data[SIZE];

} stack_p;



//functions
void initialize_p(stack_p *s);
int is_empty_p(stack_p *s);
int is_full_p(stack_p *s);
void push_p(stack_p *s, int item);
int pop_p(stack_p *s);



//---------------------------------------

void initialize_p(stack_p *s)
{
	s->top = -1;
}

//---------------------------------------

int is_empty_p(stack_p *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

//---------------------------------------

int is_full_p(stack_p *s)
{
	if (s->top == SIZE - 1)
		return 1;
	return 0;
}

//---------------------------------------

void push_p(stack_p *s, int item)
{
	if (is_full_p(s))
		printf("Error: Stack is full!\n");
	else
	{
		(s->top)++;
		s->data[s->top] = item;
	}
}

//---------------------------------------

int pop_p(stack_p *s)
{
	int item;
	if (is_empty_p(s))
	{
		printf("Error: Stack is empty!\n");
		item = 0000;
	}
	else
	{
		item = s->data[s->top];
		(s->top)--;
	}
	return (item);
}
