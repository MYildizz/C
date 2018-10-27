#include <stdio.h>
#include "stack_int.h"

void display(stack_t s)
{
	while(!is_empty_s(&s))
	printf("%d\n",pop(&s));
}

int main()
{
	stack_t s;
	initialize_s(&s);
	int a,b;
	
	int num;
	

		for(int i=0;i<6;i++)
		{
			printf("Enter an intager: ");
		    scanf("%d",&num);
		    push(&s,num);
		}
		printf("stack content\n");
		printf("-------------\n");
		display(s);
		
		a=pop(&s);
		b=pop(&s);
		push(&s,a);
		push(&s,b);
		
		printf("After swap\n");
		printf("----------\n");
		display(s);
		

	
	return 0;
}
