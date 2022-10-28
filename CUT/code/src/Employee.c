#include<functions.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<struct.h>
employee *head = NULL;
int validatename(char *name)
{
	for(int i=0 ; i<strlen(name) ; i++)
	{
		if (isalpha(name[i]))
			continue;
		else
			return 0;
	}
	return 1;
}	
void add_record( )
{
	FILE *fp = fopen("../data/Employeedata.txt","a");
	
		employee *temp = (employee *)calloc(1,sizeof(employee));
		
		while(1)
		{
			
			printf("\nEnter the EmpId ");
			scanf("%d",&temp->EmpId);
			if(temp->EmpId <1000)
			{
				printf("\nPlease enter the employee id greater than 1000");
			clear();
			}
			else
				break;
		}
		

		while(1)
		{
			printf("\nEnter the first name ");
			scanf("%s",temp->first_name);
			if(validatename(temp->first_name))
				break;
			else
				printf("\nName is not valid ");
		}

		while(1)
		{
			printf("\nEnter the last name ");
			scanf("%s",temp->last_name);
			if(validatename(temp->last_name))
				break;
			else
				printf("\nName is not valid ");
		}
		while(1)
		{
		   printf("\nEnter the mobile number1 ");
		   scanf("%s",temp->mobile_number1);
		   if(strlen(temp->mobile_number1)==10)
		   {
			   break;
		   }
		   else
		   {
			   printf("enter the mobile number1 with only 10 digits\n");
		   }
		}

		while(1)
		{
		   printf("\nEnter the mobile number2 ");
		   scanf("%s",temp->mobile_number2);
		   if(strlen(temp->mobile_number2)==10)
		   {
			   break;
		   }
		   else
			   printf("enter the number with only 10 digits\n");
		}
		printf("\nEnter the Area of expertise ");
		scanf("%s",&temp->Area_Expertise);
		
		printf("\nEnter the Edu qua ");
		scanf("%s",&temp->Edu_qua);
		temp->link = NULL;
		
		if(head == NULL)
		{
			head = temp;
			fprintf(fp,"%d %s %s %s %s %s %s\n",temp->EmpId,temp->first_name,temp->last_name,temp->mobile_number1,temp->mobile_number2,temp->Area_Expertise,temp->Edu_qua);
		}

		else
		{
			employee *q = head;
			while(q->link != NULL)
				q=q->link;
			q->link = temp;
			fprintf(fp,"%d %s %s %s %s %s %s\n",temp->EmpId,temp->first_name,temp->last_name,temp->mobile_number1,temp->mobile_number2,temp->Area_Expertise,temp->Edu_qua);
		}
		fclose(fp);
}

void display_record()
{
	
	FILE *fr = fopen("../data/Employeedata.txt","r");
	if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		
		char first_name[MAX],last_name[MAX],Area_Expertise[MAX],Edu_qua[MAX],mobile_number1[MAX],mobile_number2[MAX];
		int EmpId;
		printf("\n*******************************************************\n");
		printf("*                   DETAILS OF EMPLOYEES IS                 *");
		printf("\n*******************************************************\n");
		employee *start=NULL;
		printf("%-10s%-10s%-10s%-10s%-10s%-10s%-20s","EMPID","FIRSTName","LASTNAME","NUMBER1","NUMBER2","AREA_EXPERTISE","EDU_QUA");
		fscanf(fr,"%d%s%s%s%s%s%s",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
		while(!feof(fr))
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
			fscanf(fr,"%d%s%s%s%s%s%s",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
		}
		fclose(fr);
		
		employee *q = start;
		while(q!=NULL)
		{
			printf("\n%-10d%-10s%-10s%-13s%-11s%-10s%-20s",q->EmpId,q->first_name,q->last_name,q->mobile_number1,q->mobile_number2,q->Area_Expertise,q->Edu_qua);
			q=q->link;
		}

	}

}
void search_record( )
{
	FILE *fr=fopen("../data/Employeedata.txt","r");
	if(fr==NULL)
	{
		printf("the file is not exists\n");
	}
	else
	{
		employee *start=NULL;
		int EmpId;
		char first_name[MAX],last_name[MAX],mobile_number1[MAX],mobile_number2[MAX],Area_Expertise[MAX],Edu_qua[MAX];
		fscanf(fr,"%d%s%s%s%s%s%s",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
		while(!feof(fr))
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
			fscanf(fr,"%d%s%s%s%s%s%s",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
		}
		fclose(fr);
		employee *q=start;
		q = start;
		printf("enter the Empidto be search\n");
		int key;
		scanf("%d",&key);
		while(q!=NULL)
		{
			printf("\nthe details of the employee is");
			if(q->EmpId==key)
			{
				printf("\n%-10d%-20s%-20s%-20s%-13s%-12s%-13s",q->EmpId,q->first_name,q->last_name,q->mobile_number1,q->mobile_number2,q->Area_Expertise,q->Edu_qua);
			}
			q=q->link;
		}
	}
}
void delete_record()
{
	  FILE *fp,*del;
	  int count=0;
	  fp=fopen("../data/Employeedata.txt","r");
	  del = fopen("../data/temporarydata.txt","w");
          if(fp==NULL)
	  {
		  printf("file doesnt exits");
	  }
	  else
	  {
		  int EmpId;
		  char first_name[MAX],last_name[MAX],mobile_number1[MAX],mobile_number2[MAX],Area_Expertise[MAX],Edu_qua[MAX];
		  int r_empid;
		  printf("\n enter empid to delete");
		  scanf("%d",&r_empid);

		  while(fscanf(fp,"%d %s %s %s %s %s %s\n",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua)!=EOF)
		  {
			  if(EmpId==r_empid)
			  {
				  count++;
				  printf("\n============================================================================");
				  printf("\n user record deleted successfully :\n");
				  printf("\n ===========================================================================");
			  }

			  else
			  {
				  
		            fprintf(del,"%d %s %s %s %s %s %s\n",EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
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
void update_record()
{
	FILE *fp,*del;
	fp=fopen("../data/Employeedata.txt","r");
	del = fopen("../data/temporarydata.txt","w");
        if(fp==NULL)
	{
		printf("file doesnt exits");
	}
	else
	{   
		int choice,u_empid;
		char u_fname[MAX],u_lname[MAX],u_mob1[MAX],u_mob2[MAX],u_areasofexpert[MAX],u_education[MAX];
                int EmpId;
		char first_name[MAX],last_name[MAX],Area_Expertise[MAX],Edu_qua[MAX],mobile_number1[MAX],mobile_number2[MAX];
		printf("enter the Empid to update");
		scanf("%d",&u_empid);
		fscanf(fp,"%d%s%s%s%s%s%s",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
		while(!feof(fp))
		{
			if(EmpId==u_empid)
			{
			    printf("\n============================================================================");
				printf("\n old record is :\n");
				printf("fname of employee : %s \n",first_name);
				printf("lname: %s\n",last_name);
				printf("mob1 : %s\n",mobile_number1);
				printf("mob2 of employee : %s\n",mobile_number2);
				printf("areasofexpert of employee : %s \n",Area_Expertise);
				printf("education of employee :  %s\n",Edu_qua);
				printf("\n============================================================================");
				printf("\nEdit the record");
				printf("\nwhich information to be updated");
				printf("\n1:firstname\n2:lastname\n3:mobile_number1\n4:mobile_number2\n5:AreaofExpertise\n6:Education_qualification\n7:update all\n");
				printf("\nEnter your choice");
				scanf("%d",&choice);
				if(choice==1)
				{
					 printf("\nEnter the fname to update\n");
					 scanf("%s",u_fname);
					 fprintf(del,"%d %s %s %s %s %s %s\n",EmpId,u_fname,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
					 printf("\nchanges saved");
				}
				else if(choice==2)
				{
					 printf("\nEnter the lname to update\n");
					 scanf("%s",u_lname);
					 fprintf(del,"%d %s %s %s %s %s %s\n",EmpId,first_name,u_lname,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
					 system("cls");
					 printf("\nchanges saved");
				}
				else if(choice==3)
				{
					 printf("\nenter the mob1 to update\n");
					 scanf("%s",u_mob1);
					 fprintf(del ,"%d %s %s %s %s %s %s\n",EmpId,first_name,last_name,u_mob1,mobile_number2,Area_Expertise,Edu_qua);
					 system("cls");
					 printf("\nchanges saved");
				}
				else if(choice==4)
				{
					  printf("\nenter the mob2 to update\n");
					  scanf("%s",u_mob2);
					  fprintf(del ,"%d %s %s %s %s %s %s\n",EmpId,first_name,last_name,mobile_number1,u_mob2,Area_Expertise,Edu_qua);
					  system("cls");
					  printf("\nchanges saved");
				}
				else if(choice==5)
				{
				          printf("\nenter the areaofexpert to update\n");
					  scanf("%s",u_areasofexpert);
					  fprintf(del ,"%d %s %s %s %s %s %s\n",EmpId,first_name,last_name,mobile_number1,mobile_number2,u_areasofexpert,Edu_qua);
					  system("cls");
					  printf("\nchanges saved");
				}
					 
			        else if(choice==6)
				{
				          printf("\nenter the education to update\n");
					  scanf("%s",u_education);
					  fprintf(del ,"%d %s %s %s %s %s %s\n",EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,u_education);
					  system("cls");
					  printf("\nchanges saved");
				}
				else if(choice==7)
				{
				          printf("enter record to update all:\n");
                                          printf("\nenter the fname to update\n");
					  scanf("%s",u_fname);
					  printf("\nenter the lname to update\n");
					  scanf("%s",u_lname);
					  printf("\nenter the mob1 to update\n");
					  scanf("%s",u_mob1);
					  printf("\nenter the mob2 to update\n");
					  scanf("%s",u_mob2);
					  printf("\nenter the areaofexpert to update\n");
					  scanf("%s",u_areasofexpert);
					  printf("\nenter the education to update\n");
					  scanf("%s",u_education);
					  fprintf(del ,"%d %s %s %s %s %s %s\n",EmpId,u_fname,u_lname,u_mob1,u_mob2,u_areasofexpert,u_education);
					  system("cls");
					  printf("\nchanges saved");
				}

				
			}
			else
			{
	          fprintf(del,"%d %s %s %s %s %s %s\n",EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
		}
		fscanf(fp,"%d%s%s%s%s%s%s",&EmpId,first_name,last_name,mobile_number1,mobile_number2,Area_Expertise,Edu_qua);
	}
		remove("../data/Employeedata.txt");
		rename("../data/temporarydata.txt","../data/Employeedata.txt");
		fclose(fp);
	}
}
void Employee()
{
	
	int choice;
	employee *head = NULL;
	while(1)
	{
		printf("\n1:Add the Employee record\n2:Display\n3:search\n4:Delete\n5.update\n6:Back to main menu");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_record();
			       break;
			case 2:display_record();
			       break;
			case 3:search_record( );
			       break;
			case 4:delete_record();
			       break;
			case 5:update_record();
			       break;
			case 6:menu_options( );
			default:
			       printf("\nInvalid Choice");
		}
	}
}
