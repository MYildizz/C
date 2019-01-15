//Muratcan Yýldýz 16050111036 

//AYBU CENG 104 Computer Programming II Term Assignment Question 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "phone_stack.h"
#include "adress_queue.h"
#include "information_stack.h"



//functions

int menu();
void form_l(list *form, queue_t *adress);
void insert_phone(stack_p *phone);
void combination(stack_p *phone, stack_t *information, queue_t *adress);
void display(stack_t information);
void delete_number(stack_t *information);



int main()
{


	int num;

	//initialize structers
	stack_t information;
	stack_p phone;
	queue_t adress;
	list form;
	
	//Specify start point
	initialize_q(&adress);
	initialize_p(&phone);
	initialize_s(&information);

	//insert phone numbers randomly
	insert_phone(&phone);

   //display menu
	num = menu();


	//choice number
	while (num!=4)
	{
		switch (num)
		{
		case 1:

			display(information);
			break;

		case 2:

			form_l(&form, &adress);
			combination(&phone, &information, &adress);
			display(information);
			break;

		case 3:

			delete_number(&information);
			display(information);
			break;

		default:

			break;
		}
		num = menu();
	}



	return 0;
}


//--------------------------------------------------------------------------------------------------------

//initialize menu for users
int menu()
{

	int num;

	printf("\t\t\t******************     TELEPHONE DIRECTORY      *****************\t\t\t\n\n");
	printf("1. Show Records\n");
	printf("2. Insert Record  \n");
	printf("3. Delete Record \n");
	printf("4. EXIT  \n");
	printf("-->  ");
	scanf("%d",&num);

	while ( num < 1 || num  > 4 )
	{
		printf("\ninvalid Selection!!\n Please Select Again: ");
		scanf("%d", &num);
	}
	return num;

}

//----------------------------------------------------------------------------------------------------------

//input for users to record informations to queue
void form_l(list *form, queue_t *adress)
{
	char temp[200];
	char *line;
	printf("\n\nPLEASE FILL IN THE QUESTIONS :\n\n");

	printf("Enter Name        : ");
	scanf("\n%[^\n]s", form->name);
	printf("\nEnter Surname     : ");
	scanf("\n%[^\n]s",form->surname);
	printf("\nEnter the country : ");
	scanf("\n%[^\n]s", form->country);
	printf("\nEnter the city    : ");
	scanf("\n%[^\n]s", form->city);
	printf("\nEnter the address :");
	scanf("\n%[^\n]s", form->adress);

	insert(adress, *form);

}

//-------------------------------------------------------------------------------------------------------------

//randomly insert phone numbers between 100000000 and 500000000
void insert_phone(stack_p *phone)
{
	int random;

	for (int i = 1; i <100; i++)
	{
		
		random = 100000000 + rand() % 900000000;
		push_p(phone, random);

	}
}

//-------------------------------------------------------------------------------------------------------------

//combining phone numbers in stack and information in queue
void combination(stack_p *phone, stack_t *information, queue_t *adress)
{
	int phone_number;
	info bilgi;

	phone_number = pop_p(phone);
	bilgi.phone = phone_number;
	bilgi.person = remove(adress);
	push_s(information, bilgi);

}

//---------------------------------------------------------------------------------------------------------------

//display informations 
void display(stack_t information)
{
	info liste;

	printf("\n\n\t\t\t********************       INFORMATIONS        ******************\t\t\t\n\n");

	do {


		if (is_empty_s(&information)==1)
		printf("\nThere is no record !\n\n");
		else
		{

			liste = pop_s(&information);
			printf("\n-----------------------------------------\n");
			printf("PHONE  : \t +90%d \n", liste.phone);
			printf("NAME   : \t %-25s \n", liste.person.name);
			printf("SURNAME: \t %-25s \n", liste.person.surname);
			printf("COUNTRY: \t %-25s \n", liste.person.country);
			printf("CITY   : \t %-25s \n", liste.person.city);
			printf("ADRESS : \t %-25s \n", liste.person.adress);

			time_t zaman;
			zaman = time(NULL);
			ctime(&zaman);

			printf("DATE   :         ");
			printf(ctime(&zaman));


			printf("\n-----------------------------------------\n\n\n");

		}

	} while (!is_empty_s(&information));

}

//-----------------------------------------------------------------------------------------------------

//deleete number and informations
void delete_number(stack_t *information)
{
	char name[100];
	stack_t temp;
	initialize_s(&temp);
	info liste;

	printf("\nDELETE OPERATION-------\n\n");

	printf("Enter the name which is deleted: ");
	scanf("%s", name);



	while (is_empty_s(information)!=1)
	{
		liste = pop_s(information);

		if (strcmp(liste.person.name, name) == 0)
			continue;
		else
			push_s(&temp, liste);
	}

	while (!is_empty_s(&temp))
		push_s(information, pop_s(&temp));

	printf("\n\nDELETING OPERATION IS SUCCESFULL.\n");

}

