#include <stdio.h>
#include <string.h>

int readBikeList(FILE *ptr,char bike[][50])
{
	int i=0;
	
	while(!feof(ptr))
	{
		fscanf(ptr,"%s",bike[i]);
		i++;
	}
	return i;
}

void shiftdown(char arr[][50],int size,int min)
{
	for(int k=size-1;k>=min;k--)
	strcpy(arr[k+1],arr[k]);
}

void merge(char bike1[][50],int size1,char bike2[][50],int size2)
{
	int k1=0,k2=0;
	
	while(k1<size1 && k2 <size2)
	{
		if(strcmp(bike1[k1],bike2[k2])>=0)
		{
			shiftdown(bike1,size1,k1);
			strcpy(bike1[k1],bike2[k2++]);
			size1++;
		}
		k1++;
	}
	if(k1==size1)
		while(k2<size2)
		{
			strcpy(bike1[k1++],bike2[k2++]);
			size1++;
		}
	
}

int main()
{
	
	char bike1[10][50];
	char bike2[10][50];
	int size1,size2;
	
	FILE *ptr1=fopen("bike1.txt","r");
	FILE *ptr2=fopen("bike2.txt","r");
	
	if(ptr1== NULL || ptr2==NULL)
	printf("there is a problem!\n");
	
	else
	{
		size1=readBikeList(ptr1,bike1);
		size2=readBikeList(ptr2,bike2);
		
		merge(bike1,size1,bike2,size2);
		
		FILE *ptr=fopen("bike_list.txt","w");
		
		for(int k=0;k<size1+size2;k++)
		{
			fprintf(ptr,"%s \n",bike1[k]);
		}
		
		printf("process is succesful\n");
	}
	
	return 0;
}
