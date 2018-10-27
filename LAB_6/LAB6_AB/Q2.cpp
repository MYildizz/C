#include <stdio.h>
#include <string.h>
#include "stack_char.h"

int palindrome(stack_t *s,char *arr)
{
	int size,size1,value;
	int k;
	
	size=strlen(arr);
	
	for(k=0;k<size/2;k++)
	push(s,arr[k]);
	
	if(size%2==1)
	k++;
	
	value=pop(s);
	
	while(k<=size && value==arr[k])
	{
		
		if(!is_empty_s(s))
		value=pop(s);
		k++;
	}
	
	if(k==size)
	return 1;
	else
	return 0;
}

int main()
{
	stack_t s;
	initialize_s(&s);
	char arr[10][100],temp[100];
	int i=0,k;
	
	FILE *ptr=fopen("Palindrome.txt","r");
	
	if(ptr==NULL)
	printf("file is not opened!\n");
	else
	{
		while(!feof(ptr))
		{
			fscanf(ptr," %[^\n]s",arr[i]);
			i++;
		}
		fclose(ptr);
		
		for( k=0;k<i;k++)
		{
			
			if(palindrome(&s,arr[k])==1)
			printf("%s\n",arr[k]);
			else
			printf("-\n");
			
		}
		
	}
	
	return 0;
}
