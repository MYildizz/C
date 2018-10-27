#include <stdio.h>
#include <string.h>

typedef struct
{
	int id;
	char name[30],
	surname[30];
	int salary;
}employe_t;

void int_swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void char_swap(char *x,char*y)
{
	char temp[50];
	strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);
}

void bubble(employe_t arr[],int size)
{
	int pass,i;
	if(size>1)
	{
		for(i=0;i<size-1;i++)
	{
		if(arr[i].id>arr[i+1].id)
		{
			int_swap(&arr[i].id,&arr[i+1].id);
			char_swap(arr[i].name,arr[i+1].name);
			char_swap(arr[i].surname,arr[i+1].surname);
			int_swap(&arr[i].salary,&arr[i+1].salary);
		}
	}
	
	bubble(arr,size-1);
	}
	return ;
	
}
int binary(employe_t arr[],int top,int bottom,int item)
{
	int middle;
	
	if(top>bottom)
	return -1;
	else
	{
		middle=(top+bottom)/2;
		if(item==arr[middle].id)
		return middle;
		else if(item<arr[middle].id)
		binary(arr,top,middle-1,item);
		else if(item>arr[middle].id,item)
		binary(arr,middle+1,bottom,item);
		
	}
	
}

int main()
{
	employe_t employe,arr[50];
	int i=0;
	
	
	FILE *ptr1=fopen("Employee.txt","r");
	FILE *ptr=fopen("binary.bin","wb");
	
	if(ptr1==NULL || ptr==NULL )
	printf("file ist not opened\n");
	else
	{
			while(!feof(ptr1))
		{
			fscanf(ptr1,"%d %s %s %d",&employe.id,employe.name,employe.surname,&employe.salary);
			fwrite(&employe,sizeof(employe_t),1,ptr);
			i++;
		}
		
		fclose(ptr1);
		fclose(ptr);
		
		char name[100];
		
		printf("Enter a file name:");
		scanf("%s",name);
		
		FILE *ptr2=fopen(name,"rb");
		
		while(ptr2==NULL)
		{
			printf("\nfile is not found Enter again: ");
			scanf("%s",name);
			ptr2=fopen(name,"rb");
		}
		
		int id,index,size,a=0;
		
		fread(&arr,sizeof(employe_t),i,ptr2);
		
		for(int k=0;k<i;k++)
		{
		printf("%d %s %s %d \n",arr[k].id,arr[k].name,arr[k].surname,arr[k].salary);	
		}
		
	
		
		
		
		bubble(arr,i);
		
		printf("enter an employee id(-1 to stop): ");
		scanf("%d",&id);
		
		while(id!=-1)
		{
			index=binary(arr,0,i,id);
			if(index==-1)
			printf("id not found!!\n");
			else
			{
				printf("%d %s %s %d\n",arr[index].id,arr[index].name,arr[index].surname,arr[index].salary);
			}
			printf("enter an employee id(-1 to stop): ");
		    scanf("%d",&id);
		}
		
	}
	
	
	return 0;
}

