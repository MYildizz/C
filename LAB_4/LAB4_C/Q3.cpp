#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[50],
	surname[50],
	id[100];
}phone_t;

int read(FILE *ptr,phone_t *phone)
{
	int i=0;
	
	while(!feof(ptr))
	{
		fscanf(ptr," %s %s %s",phone[i].id,phone[i].name,phone[i].surname);
		i++;
	}
	return i;
}

void swap(char *x,char *y){
	
	char temp[30];
	strcpy(temp,x);
	strcpy(x,y);
	strcpy(y,temp);
	
}

void bubble_sort(phone_t *arr,int size)
{
	int k,sorted,pass;
	
	
	pass=1;
	
	do
	{
		sorted=1;
		
		for(k=0;k<size-pass;k++)
		{
		if(strcmp(arr[k].id,arr[k+1].id)>0)
		{
			
			swap(arr[k].id,arr[k+1].id);
			swap(arr[k].name,arr[k+1].name);
			swap(arr[k].surname,arr[k+1].surname);
			
			sorted=0;
			
		}
		
		}
	
		pass++;
	}while(!sorted);
}

void shiftdown(phone_t arr[],int size,int min)
{
	
	for(int i=size-1;i>=min;i--)
	{
		strcpy(arr[i+1].id,arr[i].id);
		strcpy(arr[i+1].name,arr[i].name);
		strcpy(arr[i+1].surname,arr[i].surname);
	}
	
}

void merge(phone_t arr1[],int size1,phone_t arr2[],int size2)
{
	int kA=0,kB=0;
	
	while(kA<size1 && kB <size2)
	{
		if(strcmp(arr1[kA].id,arr2[kB].id)>=0)
		{
			shiftdown(arr1,size1,kA);
			strcpy(arr1[kA].id,arr2[kB].id);
			strcpy(arr1[kA].name,arr2[kB].name);
			strcpy(arr1[kA].surname,arr2[kB].surname);
			kB++;
			size1++;
		}
		kA++;
	}
	
	if(kA==size1)
	{
		while(kB<=size2)
		{
			strcpy(arr1[kA].id,arr2[kB].id);
			strcpy(arr1[kA].name,arr2[kB].name);
			strcpy(arr1[kA].surname,arr2[kB].surname);
			kA++;
			kB++;
			size1++;
		}
	}
}

int main()
{
	
	phone_t phone1[30],phone2[30];
	int size1,size2;
	
	FILE *ptr1=fopen("PhoneCorp.txt","r");
	FILE *ptr2=fopen("PhoneTech.txt","r");
	
	if(ptr1==NULL || ptr2==NULL)
	printf("file is not opened!\n");
	
	else
	{
		size1=read(ptr1,phone1);
		size2=read(ptr2,phone2);
		
		bubble_sort(phone1,size1);
		bubble_sort(phone2,size2);
		
		merge(phone1,size1,phone2,size2);
		
		FILE *ptr=fopen("clients.txt","w");
		
		for(int i=0;i<size1+size2;i++)
		{
			fprintf(ptr,"%s %s %s \n",phone1[i].id,phone1[i].name,phone1[i].surname);
			printf("%s %s %s \n",phone1[i].id,phone1[i].name,phone1[i].surname);
		}
		
		
		
	}
	
	
	return 0;
}
