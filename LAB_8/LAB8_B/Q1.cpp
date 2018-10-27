#include <stdio.h>
#include <string.h>
#include "stack_char.h"
#include "queue_char.h"

int search(char *key,char *item)
{
	    int size1=strlen(item);
		int size2=strlen(key);
		
		for(int k=0;k<=size1-size2;k++)
		{
			if(strncmp(&item[k],key,size2)==0)
			return 1;
			
		}
		return 0;
}

int main()
{
	
	stack_t s;
	initialize_s(&s);
	
	queue_t q;
	initialize_q(&q);
	
	char item[100];
	int i=0;
	
	printf("Enter strings(end to stop): \n");
	scanf("%s",item);
	
	while(strcmp(item,"end")!=0)
	{
		while(strcmp(item,"return")!=0 && strcmp(item,"end")!=0)
		{
			push(&s,item);
			scanf("%s",item);
		}
		i++;
		printf("Stack %d has been pushed.\n",i);
		
		if(strcmp(item,"end")==0)
		break;

        insert(&q,s);
        initialize_s(&s);

		scanf("%s",item);
		
		if(strcmp(item,"end")==0)
		break;
	}
	
	char key[100];
	int num;
	
	printf("\Enter the string to be searched: ");
	scanf("%s",key);
	printf("\nEnter the number of stack :");
	scanf("%d",&num);
	
	for(int k=1;k<=num;k++)
	s=remove(&q);
	
	while(!is_empty_s(&s))
	{
		pop(&s,item);
				
		if(search(key,item)!=0)
		printf("%s\n",item);
		
		}
	
	return 0;
}
