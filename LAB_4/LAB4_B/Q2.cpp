#include <stdio.h>
#include <string.h>

void last(char *arr,char *key)
{
char	size1=strlen(arr);
char	size2=strlen(key);

for(int i=size1-size2;i>0;i--)
{
	if(strncmp(&arr[i],key,size2)==0)
	{
		strcpy(&arr[i],&arr[i+size2]);
	}
}
}

int main()
{
	char arr[200];
	char key[50];
	
	printf("Enter a sentence: ");
	scanf("%[^\n]s",arr);
	printf("enter a key: ");
	scanf("%s",key);
	
	last(arr,key);
	
	printf("\nResult: %s",arr);
	
	return 0;
}
