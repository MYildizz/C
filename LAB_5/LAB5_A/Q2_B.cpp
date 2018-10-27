#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num,i,k,j;
	
	FILE *ptr=fopen("data.bin","wb");
	
	if(ptr==NULL)
	printf("file is not opened!\n");
	else
	{
		printf("How many numbers do you want yo read: ");
		scanf("%d",&num);
		
		while(num<1 || num>500)
		{
			printf("Enter a number between 1 and 500!\n");
			scanf("%d",&num);
		}
		
		for(j=1;j<=num;j++)
		{
			i=j*5;
			fwrite(&i,sizeof(int),1,ptr);
		}
		fclose(ptr);
		
		fopen("data.bin","rb");
		
		int *arr;
		arr=(int *)malloc(num*sizeof(int));
		fread(arr,sizeof(int),num,ptr);
		
		for(k=0;k<num;k++)
		printf("%d ",arr[k]);
		
	}
	
	return 0;
}
