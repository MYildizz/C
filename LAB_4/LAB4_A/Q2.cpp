#include <stdio.h>
#include <string.h>

void change(char *text,char *string)
{
	int size_s=strlen(string),i=0;
    int size_t=strlen(text);
	
	for(i=0;i<size_t-size_s;i++)
	{
		if(strncmp(&text[i],string,size_s)==0)
		{
		text[i]='*';
		strcpy(&text[i+1],&text[i+size_s]);
		}
		
	}
}

int main()
{
	
	char text[200],
	string[100];
	
	printf("Enter a text: ");
	scanf("%[^\n]s",text);
	
	printf("\nEnter a string: ");
	scanf("%s",string);
	
	printf("\nOld text: %s \n",text);
	
	change(text,string);
	
	printf("New text: %s\n",text);
	
	
	return 0;
}
