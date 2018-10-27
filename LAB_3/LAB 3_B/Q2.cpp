#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct
{
	char word[50];
	int length;
}kelime_t;


void cripto (kelime_t *kelime,int num)
{
	int j=0,k=0;;
	int size;
	
	for(j=0;j<num;j++)
	{
		size=kelime[j].length;
		
		while(kelime[j].word[k]!='\0')
		{
			kelime[j].word[k]=kelime[j].word[k]+size;
			k++;
		}
		k=0;
	}
}


int main()
{
	kelime_t *kelime;
	
	int num;
	
	printf("enter the number of words :");
	scanf("%d",&num);
	
	kelime=(kelime_t *)malloc(num*sizeof(kelime_t));
	
	for(int j=0;j<num;j++)
	{
		printf("\nenter the %d. word :",j+1);
		scanf("%s",kelime[j].word);
		kelime[j].length=strlen(kelime[j].word);
	}
	
	cripto(kelime,num);
	
	for(int k=0;k<num;k++)
	{
		printf("The encrypted form of the %d. word is --> %s \n",k+1,kelime[k].word);
	}
	
	
	return 0;
}
