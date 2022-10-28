#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<functions.h>
#include<string.h>
#include<struct.h>
void Emp_Pro()
{
	while(1)
	{
	   printf("\n1:allocate\n2:delete employee\n3:back to menu options\n");
	   int choice;
	   printf("enter your choice\n");
	   scanf("%d",&choice);
	   switch(choice)
	   {
		case 1:allocate();
		       break;
		case 2:Delete_Emp();
		       break;
		case 3:menu_options();
		       break;
		default:
		       printf("\nInvalid Choice");
	   }
	}
}
void allocate()
{   
        
	int EmpId;
	char first_name[MAX],last_name[MAX],pid[MAX];
        printf("enter the empid\n");
	scanf("%d",&EmpId);
	printf("enter the first name and last name of the employee\n");
	scanf("%s",first_name);
	scanf("%s",last_name);
	printf("enter the project id\n");
	scanf("%s",pid);
	search_EmpId();
	search_pid();

}
void search_EmpId()
{
	FILE *fe=fopen("../data/Employeedata.txt","r");
	FILE *frw=fopen("../data/Emp_Pro.txt","a");
	if(fe==NULL)
	{
		printf("the file is not exists\n");
	}
	else
	{
		employee *start=NULL;
		int EmpId;
		char first_name[MAX],last_name[MAX],mobile_number1[MAX],mobile_number2[MAX],Area_Expertise[MAX],Edu_qua[MAX];
		fscanf(fe,"%d%s%s%s%s%s%s",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
		while(!feof(fe))
		{
			employee *temp = (employee *) calloc(1,sizeof(employee));
			temp->EmpId = EmpId;
			strcpy(temp->first_name,first_name);
			strcpy(temp->last_name,last_name);
			strcpy(temp->mobile_number1,mobile_number1);
			strcpy(temp->mobile_number2,mobile_number2);
			strcpy(temp->Area_Expertise,Area_Expertise);
			strcpy(temp->Edu_qua,Edu_qua);
			temp->link = NULL;
			if(start == NULL)
			{
				start = temp;
			}
			else
			{
				employee *q = start;
				while(q->link != NULL)
					q = q->link;
				q->link = temp;
				}
			fscanf(fe,"%d%s%s%s%s%s%s",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
		}
		fclose(fe);
		employee *q=start;
		q = start;
		printf("enter the Empid to be search\n");
		int key;
		scanf("%d",&key);
		while(q!=NULL)
		{
			if(q->EmpId==key)
			{
				printf("the employee id is present\n");
				fprintf(frw,"%-10d%-20s%-20s",q->EmpId,q->first_name,q->last_name);
			}
			q=q->link;
		}
		
	}
	fclose(frw);
}

void search_pid()
{
	FILE *fr=fopen("../data/projectdata.txt","r");

	FILE *frw=fopen("../data/Emp_Pro.txt","a");
	if(fr==NULL)
	{
		printf("the file is not exists\n");
	}
	else
	{
		project *start=NULL;
		int No_Emp;
		char client_name[MAX],pid[MAX],desc[MAX],start_date[MAX],end_date[MAX];
		fscanf(fr,"%s%s%s%s%s%d",pid,desc,client_name,start_date,end_date,&No_Emp);
		while(!feof(fr))
		{
			project *temp = (project *) calloc(1,sizeof(project));
			strcpy(temp->pid,pid);
			strcpy(temp->desc,desc);
			strcpy(temp->client_name,client_name);
			strcpy(temp->start_date,start_date);
			strcpy(temp->end_date,end_date);
			temp->No_Emp = No_Emp;
			temp->link = NULL;
			if(start == NULL)
			{
				start = temp;
			}
			else
			{
				project *q = start;
				while(q->link != NULL)
					q = q->link;
				q->link = temp;
			}
			fscanf(fr,"%s%s%s%s%s%d",pid,desc,client_name,start_date,end_date,&No_Emp);
		}
		fclose(fr);
		project *q=start;
		q = start;
		printf("enter the project id to be search\n");
		char key[MAX];
		scanf("%s",key);
		while(q!=NULL)
                {
			if(strcmp(pid,key)==0)
			{
				printf("the project id is present\n");
				printf("Employee is allocated to project\n");
				fprintf(frw,"%-10s%-10s",q->pid,q->desc);
			}
			q=q->link;
		}
	}
	fclose(frw);
}



void Delete_Emp()
{
    FILE *fr=fopen("../data/Employeedata.txt","r");
    FILE *del = fopen("../data/temporarydata.txt","w");
    FILE *fp=fopen("../data/Emp_Pro.txt","r");

    if(fp==NULL)
    {
        printf("the file is not exists\n");
    }
    else
    {
		emp_pro *start=NULL;
		int EMPID;
		char PID[MAX],DESC[MAX],FIRST_NAME[MAX],LAST_NAME[MAX];
                fscanf(fp,"%d%s%s%s%s",&EMPID,FIRST_NAME,LAST_NAME,PID,DESC);
		int empid;
		int count=0;
		printf("enter the employee id to be deleted\n");
		scanf("%d",&empid);
		while(!feof(fp))
		{
			if(EMPID==empid)
			{
				printf("the details of the employee is not deleted\n");
			}
			else
			{
                       int EmpId;
		      char first_name[MAX],last_name[MAX],mobile_number1[MAX],mobile_number2[MAX],Area_Expertise[MAX],Edu_qua[MAX];

		      while(fscanf(fr,"%d%s%s%s%s%s%s\n",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua)!=EOF)
		      {
			  if(EmpId==EMPID)
			  {
				  count++;
				  printf("\n============================================================================");
				  printf("\n user record deleted successfully :\n");
				  printf("\n ===========================================================================");
			  }

			  
		      }
	              fclose(fp);
	              fclose(del);
                      remove("../data/Employeedata.txt");
	              rename("../data/temporarydata.txt","../data/Employeedata.txt");
	              if(count==0)
		      {
			   printf("record not found\n");
		      }
		}
		}

        }
 
    
}
