//Muratcan Yıldız 16050111036

//this header gets informations such as city name surname country

#define SIZE 200

typedef struct
{
	char city[50];
	char country[50];
	char name[200];
	char surname[200];
	char adress[200];

}list;


typedef struct
{
	int rear,
		front,
		counter;
	list data[SIZE];
}queue_t;


//functions
void initialize_q(queue_t *q);
int is_empty_q(queue_t *q);
int is_full_q(queue_t *q);
void insert(queue_t *q, list item);
list remove(queue_t *q);




//-----------------------------------------------

void initialize_q(queue_t *q)
{
	q->front = 0;
	q->rear = -1;
	q->counter = 0;
}

//------------------------------------------------

int is_empty_q(queue_t *q)
{
	if (q->counter == 0)
		return 1;
	return 0;
}

//------------------------------------------------

int is_full_q(queue_t *q)
{
	if (q->counter == SIZE)
		return 1;
	return 0;
}

//------------------------------------------------

void insert(queue_t *q, list item)
{
	if (is_full_q(q))
		printf("Error:Queue is full!\n");
	else
	{
		q->rear = (q->rear + 1) % SIZE;   // make it circular
		q->data[q->rear] = item;
		(q->counter)++;
	}
}

//------------------------------------------------

list remove(queue_t *q)
{
	list item;
	if (is_empty_q(q))
	{
		printf("Error: Queue is empty!\n");
		item = { "NULL","NULL","NULL","NULL","NULL" };
	}
	else
	{
		item = q->data[q->front];
		q->front = (q->front + 1) % SIZE;
		(q->counter)--;
	}
	return item;
}

