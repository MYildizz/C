#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char name[50],
	country[50];
    int pop;
}city_t;

int readAndWrite(FILE *ptr1,FILE *ptr2,city_t arr[])
{
	city_t sehir;
	int i=0;
	while(!feof(ptr1))
		{
			fscanf(ptr1,"%s %s %d",sehir.name,sehir.country,&sehir.pop);
			fwrite(&sehir,sizeof(city_t),1,ptr2);
			i++;
		}
		fclose(ptr1);
		fclose(ptr2);
		
		ptr2=fopen("binary.bin","rb");
		fread(arr,sizeof(city_t),i,ptr2);
		
		return i;
}

int recursive(char *item,city_t arr[],int top,int bottom)
{
	int middle;
	
	if(bottom<top)
	return -1;
	else
	{
		middle=(bottom+top)/2;
		if(strcmp(arr[middle].name,item)==0)
		return middle;
		else if(strcmp(arr[middle].name,item)==1)
		recursive(item,arr,top,middle-1);
		else if(strcmp(arr[middle].name,item)==-1)
		recursive(item,arr,middle+1,bottom);
	}
}

int main()
{
	city_t arr[50];
	int size;
	char name[50];
	int result;
	
	
	FILE *ptr1=fopen("cities.txt","r");
	FILE *ptr2=fopen("binary.bin","wb");
	
	if(ptr1==NULL && ptr2==NULL)
	printf("file is not opened !\n");
	else
	{
		size=readAndWrite(ptr1,ptr2,arr);
		
		printf("Enter a city name: ");
		scanf("%s",name);
		
		result=recursive(name,arr,0,size);
		
		if(result==-1)
		printf("%s could not found \n",name);
		else
		{
			printf("%s %s %d \n",arr[result].name,arr[result].country,arr[result].country);
			
		}
		
	}
	
	return 0;
}
