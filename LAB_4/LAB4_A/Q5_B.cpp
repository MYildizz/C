#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[50],
	surname[50],
	adress[50];
}plates_t;


int binary(plates_t plates[],char adres[],int top,int bottom,int *comp)
{
	int middle;
	
	while(top<=bottom)
	{
		
		middle=(top+bottom)/2;
		(*comp)++;
		
		if(strcmp(plates[middle].adress,adres)==0)
		return middle;
		else
		    if(strcmp(plates[middle].adress,adres)==1)
		     bottom=middle-1;
	       	else
		       top=middle+1;
	}
	return -1;
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
		int comp;
		
		while(!feof(ptr))
		{
			fscanf(ptr,"%s %s %s",plates[i].name,plates[i].surname,plates[i].adress);
			i++;
		}
		printf("enter a plate of a car (END for exit): ");
		scanf("%s",adres);
		
		while(strcmp(adres,"END")!=0)
		{
				
		    comp=0;
			int num;
			num=binary(plates,adres,0,i-1,&comp);
			
			if(num==-1)
			printf("not found!\n");
			else
			{
				printf("%s %s %s \n",plates[num].name,plates[num].surname,plates[num].adress);
				
			}
			printf("%d \n",comp);
			
			printf("enter a plate of a car (END for exit): ");
		        scanf("%s",adres);
		}
	
		
		
	}
	
	
	return 0;
}
