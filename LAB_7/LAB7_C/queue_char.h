//
// Circular Queue Implementation, CENG 104
//
#define QUEUE_SIZE  100
#include <stdio.h>
#include <string.h>

//Author: Evren
typedef  char  QType;

QType  QUEUE_EMPTY = '!';

typedef struct _Queue
{	int front, rear;
	QType data[QUEUE_SIZE][100];
	int age[100];
	int counter;
} queue_t;

//Functions in this file...
void initialize_q (queue_t *q);
int is_empty_q (queue_t *q);
int is_full_q (queue_t *q);
void insert (queue_t *q, QType *item);
void remove (queue_t *q);

//------------------------------------------------------------------------------

void initialize_q (queue_t *q)
{
	q->front = 0;
	q->rear  = -1;
	q->counter = 0;
}

//------------------------------------------------------------------------------

int is_empty_q (queue_t *q)
{
	if (q->counter == 0)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

int is_full_q (queue_t *q)
{
	if (q->counter == QUEUE_SIZE)
		return 1;
	return 0;
}

//------------------------------------------------------------------------------

void insert (queue_t *q, QType *item,int age)
{
	if (is_full_q (q))
		printf("Error: Queue is full!\n");
	else 
	{	q->rear = (q->rear + 1) % QUEUE_SIZE;   // make it circular
		strcpy(q->data[q->rear],item);
		q->age[q->rear]=age;
		(q->counter)++;
	}
}

//------------------------------------------------------------------------------

int remove (queue_t *q)
{
	QType item[50]={""};
	int num;
	if (is_empty_q (q))
	{	printf("Error: Queue is empty!\n");
		num=0;
	}
	else
	{	strcpy(item,q->data[q->front]);	
	    q->age[q->front];
	    printf("%s \t %d\n",q->data[q->front],q->age[q->front]);
	    
	   num=q->age[q->front];
	    
	    
	    
		q->front = (q->front + 1) % QUEUE_SIZE;
		(q->counter)--;
	}
	return num;
}
