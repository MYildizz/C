#include <stdio.h>
#include "queue_char.h"

void display(queue_t q)
{
	while(!is_empty_q(&q))
	printf("%c ",remove(&q));
}

int main()
{
	queue_t q;
	initialize_q(&q);
	
	printf("* Erase the first character (remove it from the queue) \n");
	printf("+ Kill the entire line (Empty the queue)");
	printf(": or ! Display the queue content");
	printf("Enter Terminate the string entry and display the queue content \n");
	printf("Enter characters to be inserted to the queue (press enter to stop)");
	
	char ch,kelime;
	ch=getchar();
	
	while(ch!='\n')
	{
		if(ch=='*')
		{
			kelime=remove(&q);
			printf("\nThe Character <%c> is removed from the queue\n ",kelime);
		}
		else if(ch=='+')
		{
			initialize_q(&q);
			printf("\nAll the characters are removed from the queue\n");
		}
		else if(ch==':' || ch=='!')
		{
			printf("\nThe content of the tarantula is: ");
			display(q);
		}
		else
		insert(&q,ch);
		ch=getchar();
	}
	printf("\nThe content of the tarantula is: ");
			display(q);
	
	
	return 0;
}
