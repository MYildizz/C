#include <stdio.h>
#include <string.h>
#include "stack_char.h"

int main()
{
	
	FILE *ptr=fopen("seminars.txt","r");
	
	if(ptr==NULL)
	printf("file is not opened!\n");
	else
	{
		stack_t s[20];
		initialize_s(s);
		
		int id;
		char name[100];
		char info[100];
		
		while(!feof(ptr))
		{
			fscanf(ptr,"%d %s %[^\n]s",&id,name,info);
			push(s,id,name,info);
		}
		
		printf("The list od Oracle Seminars in reverse order\n");
		
		printf("ID \t COMPANY \t SUBJECT \n");
		printf("***\t******** \t ******* \n");
		
		while(!is_empty_s(s))
		{
			pop(s);
		}
	}
	
	return 0;
	
}
