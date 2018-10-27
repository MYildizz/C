#include <stdio.h>

typedef struct
{
	char name[50];
	int date;
	int price;
	
	
}cars_t;

int menu(cars_t cars[])
{
	int num;
	printf("According to:\n");
	printf("1.Type\n");
	printf("2. Model\n");
	printf("3. Price Range\n");
	printf("4. EXIT\n");
	
	printf("enter your choice: ");
	scanf("%d",&num);
	
	while(num<1 || num >4)
	{
		printf("enter your choice: ");
	scanf("%d",&num);
	}
	return num;
}

int main()
{
	cars_t cars[10];
	
	FILE *ptr=fopen("cars.txt","r");
	
	int i=0;
	
	if(ptr==NULL)
	printf("file is not opened.\n");
	else
	{
		while(!feof(ptr))
		{
			fscanf(ptr,"%s %d %d",cars[i].name,&cars[i].date,&cars[i].price);
			i++;
		}
		
		int num=menu(cars);
		
		switch(num)
		{
			case 1:
				char ch;
				printf("Enter a type (P:Peugeout,M:Mercedes,H:Honda):");
				scanf("%c",&ch);
				
				while(ch!='P' && ch!='M' && ch!='H')
				{
					printf("Enter a type (P:Peugeout,M:Mercedes,H:Honda):");
				     scanf("%c",&ch);
				}
				printf("\n\n");
				
				for(int j=0;j<i;j++)
				{
					if(cars[j].name[0]==ch)
					printf("%s %d %d\n",cars[j].name,cars[j].date,cars[j].price);
					
				}
				break;
				case 2:
					int mod;
					printf("Enter a model year: ");
					scanf("%d",&mod);
					
					for(int j=0;j<i;j++)
					{
						if(cars[j].date==mod)
						printf("%s %d %d\n",cars[j].name,cars[j].date,cars[j].price);
					}
					break;
					case 3:
						int num1,num2;
						printf("Enter a price range: ");
						scanf("%d %d",&num1,&num2);
						
						for(int j=0;j<i;j++)
						{
							if(cars[j].price<=num2 && cars[j].price>=num1)
							printf("%s %d %d\n",cars[j].name,cars[j].date,cars[j].price);
						}
		}
		
	}
	
	
	return 0;
}
