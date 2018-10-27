#include <stdio.h>
#include <string.h>

void swap(char *a,char *b)
{
	char temp[50];
	
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}

void bubble_sort(char arr[][100],int size)
{
	int i,pass,sorted;
	pass=1;
	
	do{
		sorted=1;
		
		for(i=0;i<size-pass;i++)
		{
			if(strcmp(arr[i],arr[i+1])==1)
			{
				swap(arr[i],arr[i+1]);
				sorted=0;
			}
		}
		pass++;
	}while(!sorted);
}

int main()
{
	int i=0;
	char arr[20][100],temp[50];
	
	do
	{
		
		
		printf("Enter a song name (end to stop):");
	    scanf("\n%[^\n]",temp);
	    
	    if(strcmp(temp,"end")==0)
	    break;
	    else
	  	  	strcpy(arr[i],temp);
		
	i++;
	}while(1);
	
	bubble_sort(arr,i);
	
	printf("Disco Songs\n");
	printf("------------\n");
	
	for(int k=0;k<i;k++)
	{
		printf("%d) %s\n",k+1,arr[k]);
	}
	
	
	return 0;
}
