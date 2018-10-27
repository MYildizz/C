#include <stdio.h>
#include <string.h>

int longest(char arr[][100],int size)

{
     int i=0,k=0;
	int long_s=strlen(arr[i]);
	
	for(i=1;i<size;i++)
	{
		if(strlen(arr[i])>long_s)
		{
			 k=i;
			long_s=strlen(arr[i]);
		}
		
	}
	return k;
}

int main()
{
	char arr[50][100];
	int i=0;
	printf("Enter a word(0r STOP): ");
	scanf("%s",arr[i]);
	
	while(strcmp(arr[i],"STOP")!=0)
	{
		i++;
		printf("Enter a word(0r STOP): ");
	    scanf(" %s",arr[i]);
	}
	
	int k=longest(arr,i-1);
	
	printf("\nLongest word: %s \n",arr[k]);
	printf("Length: %d\n",strlen(arr[k]));
	return 0;
}
