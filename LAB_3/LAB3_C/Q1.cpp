#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char article[5][10]={"the","a ","one","some","any "},
	noun[5][10]={"biycle","bird","dog","bus","car"},
	verb[5][10]={"drove","jumped","ran","walked","flew"},
	preposition[5][10]={"to ","from","over","under","on "};
	
	int num,num1,num2,num3,num4;
	
	srand(time(0));
	
	for(int i=0;i<5;i++)
	{
		printf("Sentence : ");
		
		num1=rand()%4;
		printf("%s ",article[num1]);
		
		num2=rand()%4;
		printf("%s ",noun[num2]);
		
		num3=rand()%4;
		printf("%s ",verb[num3]);
		
		num4=rand()%4;
		printf("%s  \n",preposition[num4]);
		
	}
	
	return 0;
}
