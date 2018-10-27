#include <stdio.h>

int main()
{
	char arr [100],
	arr1[100],
	arr2[100];
	
		printf("enter a sentence: ");
	scanf("%[^\n]s",arr);
	printf("\n the sentence is: %s",arr);
	
	printf("enter a sentence : ");
	scanf("%s",arr1);
	printf("\nthe sentence is %s\n",arr1);
	
	
	
	printf("enter sentence: ");
	scanf("%[^0-9]s",arr2);
	printf("the sentence is %s\n",arr2);
	

	
}
