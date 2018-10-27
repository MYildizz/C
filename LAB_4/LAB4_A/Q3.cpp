#include <stdio.h>

int find_min(int arr[],int size,int mins)
{
	int min=arr[mins];
	int min_t=mins;
	
	for(int j=mins+1;j<=size;j++)
	if(arr[j]<min)
	{
		min=arr[j];
		min_t=j;
	}
return min_t;
}
void selection_sort(int arr[],int size)
{
	int k;
	int min;
	
	for(k=0;k<=size-1;k++)
	{
		min=find_min(arr,size-1,k);
		
		if(k!=min)
		{
			int temp=arr[min];
			arr[min]=arr[k];
			arr[k]=temp;
		}
	}
}


int main()
{
	
	FILE *ptr=fopen("points.txt","r");
	if(ptr==NULL)
	printf("file is not opened!\n");
	else
	{
		int arr[50];int i=0;
		
		while(!feof(ptr))
		{
			fscanf(ptr,"%d",&arr[i]);
			i++;
		}
		selection_sort(arr,i);
		
		for(int k=0;k<i;k++)
		{
			printf("%d \n",arr[k]);
		}
	}
	
	return 0;
}
