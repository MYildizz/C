#include <stdio.h>
#include "queue_char.h"

void display(queue_t q)
{
	printf("The list of all staff\n\n");
	printf("Name \t noOfCustomers\n");
	printf("**********************\n");
	
	while(!is_empty_q(&q))
	{
		remove(&q);
	}
}
int main()
{
	queue_t q;
	initialize_q(&q);
	
	FILE *ptr=fopen("staff.txt","r");
	
	if(ptr==NULL)
	printf("File is not oepend\n");
	else
	{
		int age;
		char name[50];
		
		while(!feof(ptr))
		{
			fscanf(ptr,"%s %d",name,&age);
			insert(&q,name,age);
		}
		display(q);
		int num,max=0;
		printf("The waiter/waitress of the day\n");
		printf("******************************\n");
		
		while(!is_empty_q(&q))
		{
			num=remove(&q);
		    
		    if(num>max)
		    max=num;
			
			
		}
		printf("%")
	}
	
	return 0;
}
