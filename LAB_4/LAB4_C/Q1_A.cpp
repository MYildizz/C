#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findFirst(char *arr,char *key)
{
	int size1=strlen(arr);
	int size2=strlen(key);
	int k=0;
	for(int i=0;i<size1-size2;i++)
	if(strncmp(&arr[i],key,size2)==0)
	k++;
	
	return k;
}

int main()
{
	char arr[200];
	char key[50];
	
	printf("Enter a sentence: ");
	scanf("%[^\n]s",arr);
	
	printf("\nEnter a key: ");
	scanf("%s",key);
	
int num=	findFirst(arr,key);
	
	if(num==0)
	printf("the sentence does not contain the string <%s> \n",key);
	else
	{
		printf("The first occurence of the string <%s> is %d \n",key,num);
	}
	
	return 0;
}
