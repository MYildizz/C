#include <stdio.h>
#include "queue_char.h"

int main()
{
	FILE *ptr=fopen("busstop.txt","r");
	
	if(ptr==NULL)
	printf("File is not opened\n");
	else
	{
		queue_t q;
		initialize_q(&q);
		
       char arr[50];
       
       while(!feof(ptr))
       {
       	fscanf(ptr,"%s",arr);
       	insert(&q,arr);
	   }
	   fclose(ptr);
	   printf("no problem");
	   
	   int num;
	   
	   printf("The bus arrived the bus stop!\n");
	   printf("How many passengers getting on the bus?\n");
	   scanf("%d",&num);
	   
	   printf("The list of Passengers getting on the bus:\n");
	   for(int i=0;i<num;i++)
	   {
	   	remove(&q);
	   }
	   
	   printf("\nWaiting passenfers:\n");
	   while(!is_empty_q(&q))
	   {
	   	remove(&q);
	   }
	   
	}
	
	
	return 0;
}
