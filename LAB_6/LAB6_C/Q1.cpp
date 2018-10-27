#include <stdio.h>
#include "stack_int.h"

int menu()
{
	int num;
	
	printf("\n1) Count Stack\n");
	printf("2) Remove Maximum Element\n");
	printf("3) Send Nth End\n");
	printf("4) Exit\n");
	scanf("%d",&num);
	
	return num;
}
void display(stack_t s)
{
	printf("STACK CONTENT\n");
	while(!is_empty_s(&s))
	printf("%d\n",pop(&s));
}

void counts(stack_t s)
{
	int i=0,a;
	while(!is_empty_s(&s))
	{
	   a=pop(&s);
		i++;
	}
	printf("Number of elements in the stack: %d\n",i);
	
}
void max(stack_t *s)
{
	stack_t i;
	initialize_s(&i);
	int value;
	int max=pop(s);
	push(&i,max);
	
	while(!is_empty_s(s))
	{
		value=pop(s);
		push(&i,value);
		
		if(value>max)
		max=value;
	}
	
	while(!is_empty_s(&i))
	{
		value=pop(&i);
		if(value!=max)
		push(s,value);
	}
	
	
}
void send(stack_t *s,int ch)
{
	stack_t i;
	initialize_s(&i);
	
	for(int k=1;k<ch;k++)
	push(&i,pop(s));
	
	int b=pop(s);
	
	while(!is_empty_s(s))
	push(&i,pop(s));
	
	push(s,b);
	
	while(!is_empty_s(&i))
push(s,pop(&i));	
	
	
}
int main()
{
	stack_t s;
	initialize_s(&s);
	
	int i=0,num,count;
	
	printf("Enter a number: ");
	scanf("%d",&i);
	while(i>0)
	{
		push(&s,i);
		printf("Enter a number: ");
	    scanf("%d",&i);
	}
	
	
	display(s);
	
	int ch;
	
	num=menu();
	
	switch(num)
	{
		case 1:
			counts(s);
			num=menu();
			
			case 2:
				max(&s);
				display(s);
				num=menu();
				
				case 3:
					printf("Enter your choice: ");
					scanf("%d",&ch);
					send(&s,ch);
					display(s);
					num=menu();
				
					case 4:
						break;
						default:
							break;
					
	}
	
	return 0;
}
