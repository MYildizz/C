#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 findFirst(char *arr,char *key)
{
	int size1=strlen(arr);
	int size2=strlen(key);
	
	int k=0;
	
	for(int i=0;i<size1-size2;i++)
	if(strncmp(&arr[i],key,size2)==0)
	{
		strcpy(arr,&arr[i+size2]);
		break;
	}
	
	
}

int main()
{
	char arr[200];
	char key[50];
	
	printf("Enter a sentence: ");
	scanf("%[^\n]s",arr);
	
	printf("\nEnter a key: ");
	scanf("%s",key);
	
findFirst(arr,key);

printf("The noew form of the sentence after deletion: %s \n",arr);
	

	return 0;
}
