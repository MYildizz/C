#include <stdio.h>

typedef struct{
int englishProficiency, jury, graduateExam;
} grades_t;

typedef struct{
int id;
grades_t gr;
double overall;
}applicantsOfCENG_t;

int readfile(FILE *ptr,applicantsOfCENG_t *app)
{
	int i=0;
		
	while(!feof(ptr))
{
	
	
fscanf(ptr,"%d %d %d %d",&(app+i)->id,&(app+i)->gr.englishProficiency,&(app+i)->gr.jury,&(app+i)->gr.graduateExam);
(app+i)->overall=0.0;
i++;	

}
return i;
}

void calculate(applicantsOfCENG_t *app,int i)
{
	double ort=0;
	
	for(int j=0;j<i;j++)
	{
		ort=((app+j)->gr.englishProficiency)*30/100.0 + ((app+j)->gr.jury)*50/100.0 + ((app+j)->gr.graduateExam)*20/100.0;
		(app+j)->overall=ort;
		ort=0;
	}
	
}

void findPassFail(applicantsOfCENG_t *app,int i)
{
	int pass=0;
	int fail=0;
	
	double average=0;
	
	for(int j=0;j<i;j++)
	{
		average+=(app+j)->overall;
	}
	
	average=average/(double)i;
	
	for(int j=0;j<i;j++)
	{
		if((app+j)->overall>average)
		pass++;
		else
		fail++;
	}
	
	printf("\n\nAverage is %.1lf\n",average);
	printf("Number of applicants who pass is %d\n",pass);
	printf("Number of the applicants who fails is %d\n",fail);
}

void display(applicantsOfCENG_t app[],int i,int *pass,int *fail)
{
	int j=0;
	
	for(j=0;j<i;j++)
	{
		printf("Applicant ID: %d\n",(app+j)->id);
		printf("Scores:\n");
		printf("Applicant English Proficiency: %d\n",(app+j)->gr.englishProficiency);
		printf("Applicant Jury %d\n",(app+j)->gr.jury);
		printf("Applicant Graduate Examination: %d\n",(app+j)->gr.graduateExam);
		printf("Applicant Overall: %.1lf \n",(app+j)->overall);
		printf("\n\n");
	}
}

int main()
{
	
	
FILE *ptr;
ptr=fopen("applicant.txt","r");

if(ptr==NULL)
printf("error\n");
else
{
	applicantsOfCENG_t app[4];
int pass=0;
int fail=0;
	
	int i=readfile(ptr,app);
	calculate(app,i);
		display(app,i,&pass,&fail);
	findPassFail(app,i);
}


	
	
	return 0;
}
