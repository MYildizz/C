#include <stdio.h>
#include <string.h>



typedef struct
{
	char name[50],
	surname[50],
	adress[50];
}plates_t;

int search(plates_t plates[100],char *adres,int size,int *comp)
{
	
		for(int k=0;k<size;k++)
	{
		(*comp)++;
		if(strcmp(plates[k].adress,adres)==0)
		return k;
		
	}
	return 0;
}

int main()
{
	char adres[50];
	
	plates_t plates[100];
	
	FILE *ptr=fopen("plates.txt","r");
	if(ptr==NULL)
	printf("File is not opened!\n");
	else
	{
		int i=0;
		
		while(!feof(ptr))
		{
			fscanf(ptr,"%s %s %s",plates[i].name,plates[i].surname,plates[i].adress);
			i++;
		}
		
		do
		{
			
		printf("Enter plate of car(END for exit): ");
		scanf("%s",adres);
		
		int comp=0;
		
		if(strcmp(adres,"END")==0)
		break;
		
		else
		{
			if(search(plates,adres,i,&comp)!=0)
			{
				int num=search(plates,adres,i,&comp);
				
				printf("\n%s %s %s \n",plates[num].name,plates[num].surname,plates[num].adress);
				printf("Comparisons %d \n",comp);
			}
		}
		
		}while(1);
		
		
	}
	
	
	return 0;
}
