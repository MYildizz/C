#include <stdio.h>

int myStrlen(char *kelime)
{
	int j=0;
	while(kelime[j]!='\0')
	j++;
	
	return j;
}

int main()
{
	char arr[10][100];
	int i=0;
	int number;
	
	FILE *ptr=fopen("words.txt","r");
	FILE *ptr1=fopen("Result.txt","w");
	
	if(ptr==NULL)
	printf("File is not opened!\n");
	else
	{
		while(!feof(ptr))
		{
			fscanf(ptr,"%s",arr[i]);
			i++;
		}
		
		for(int j=0;j<i;j++)
		{
			number=myStrlen(arr[j]);
			fprintf(ptr1,"%s - %d \n",arr[j],number);
			number=0;
		}
	
	fclose(ptr);
	fclose(ptr1);
		
	}
	
	return 0;
}
