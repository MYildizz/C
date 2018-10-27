#include <stdio.h>
#include "queue_int.h"

void display(queue_t q)
{
	
	while(!is_empty_q(&q))
	printf("%d ",remove(&q));
}

void remove_t(queue_t *q)
{
	int value;
	queue_t r;
	initialize_q(&r);
	
	while(!is_empty_q(q))
	{
		value=remove(q);
		if(value%2==0)
		insert(&r,value);
	}
	printf("\nQueue Content\n");
	printf("-------------\n");
	display(r);
	
}

int main()
{
	queue_t q;
	initialize_q(&q);
	int num;
	
	printf("Enter a number(or negative to STOP):");
	scanf("%d",&num);
	
	while(num>0)
	{
		insert(&q,num);
		printf("Enter a number(or negative to STOP):");
	    scanf("%d",&num);
	}
	printf("Queue Content\n");
	printf("-------------\n");
	display(q);
	
	remove_t(&q);
	
	
	return 0;
}
