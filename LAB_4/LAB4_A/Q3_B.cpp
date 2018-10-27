#include <stdio.h>

void swap(int *a,int *b)
{
	int temp;
	
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubble_sort(int arr[],int size)
{
	int i,sorted,pass;
	
	pass=1;
	
	do
	{
		sorted=1;
		
		for(i=0;i<size-pass;i++)
		{
			if(arr[i]<arr[i+1])
			{
				swap(&arr[i],&arr[i+1]);
				sorted=0;
			}
		}
		pass++;
		
	}while(!sorted);
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
		bubble_sort(arr,i);
		
		for(int k=0;k<i;k++)
		{
			printf("%d \n",arr[k]);
		}
	}
	
	return 0;
}
