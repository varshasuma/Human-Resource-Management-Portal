#include<functions.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<struct.h>
project *Start = NULL;

void add_Project( )
{
	FILE *fp = fopen("../data/projectdata.txt","a");
	
		project *temp = (project *)calloc(1,sizeof(project));
		printf("\nEnter the project id ");
		scanf("%s",temp->pid);
		printf("\nEnter the description");
		scanf("%s",temp->desc);
		printf("enter the client name\n");
		scanf("%s",temp->client_name);	
		printf("enter the start date\n");
		scanf("%s",temp->start_date);
                printf("enter the end date\n");
		scanf("%s",temp->end_date);
		printf("enter the no.of employees required for the project\n");
		scanf("%d",&temp->No_Emp);
		temp->link = NULL;
		if(Start == NULL)
		{
			Start = temp;
			fprintf(fp,"%s %s %s %s %s %d\n",temp->pid,temp->desc,temp->client_name,temp->start_date,temp->end_date,temp->No_Emp);
		}

		else
		{
			project *q = Start;
			while(q->link != NULL)
				q=q->link;
			q->link = temp;
			fprintf(fp,"%s %s %s %s %s %d\n",temp->pid,temp->desc,temp->client_name,temp->start_date,temp->end_date,temp->No_Emp);
		}
		fclose(fp);
}
void display_Project()
{
	FILE *fr = fopen("../data/projectdata.txt","r");
	if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		
		char pid[MAX],client_name[MAX],desc[MAX],start_date[MAX],end_date[MAX];
		int No_Emp;
		printf("\n*******************************************************\n");
		printf("*                   DETAILS OF PROJECT IS                 *");
		printf("\n*******************************************************\n");
		project *start=NULL;
		printf("%-10s%-10s%-10s%-10s%-10s%-10s","PID","DESC","CLIENT_NAME","START_DATE","END_DATE","NO_EMP");
		fscanf(fr,"%s%s%s%s%s%d",pid,desc,client_name,start_date,end_date,&No_Emp);
		while(!feof(fr))
		{
			project *temp = (project *) calloc(1,sizeof(project));
			strcpy(temp->pid,pid);
			strcpy(temp->desc,desc);
            strcpy(temp->client_name,client_name);
			strcpy(temp->start_date,start_date);
			strcpy(temp->end_date,end_date);
			temp->No_Emp= No_Emp;
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
		
		project *q = start;
		while(q!=NULL)
		{
			printf("\n%-10s%-10s%-13s%-11s%-10s%-10d",q->pid,q->desc,q->client_name,q->start_date,q->end_date,q->No_Emp);
			q=q->link;
		}

	}
	
	

}
void search_Project( )
{
	FILE *fr=fopen("../data/projectdata.txt","r");
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
			printf("\nthe details of the project is");
			if(strcmp(pid,key)==0)
			{
				printf("\n%-20s%-20s%-20s%-13s%-12s%-10d",q->pid,q->desc,q->client_name,q->start_date,q->end_date,q->No_Emp);
			}
			q=q->link;
		}
	}
}

void delete_Project()
{
	  FILE *fp,*del;
	  fp=fopen("../data/projectdata.txt","r");
	  del = fopen("../data/temporarydata.txt","w");
          int No_Emp;
          char pid[MAX],desc[MAX],client_name[MAX],start_date[MAX],end_date[MAX];
          if(fp==NULL)
	  {
		  printf("file doesnt exits");
	  }
	  else
	  {
		  char r_pid[MAX];
		  printf("\n enter pid to delete");
		  scanf("%s",r_pid);
		  int count =0;

		  while(fscanf(fp ,"%s %s %s %s %s %d\n",pid,desc,client_name,start_date,end_date,&No_Emp)!=EOF)
		  {
			  if(strcmp(pid,r_pid)==0)
			   {
				  count++;
				  printf("\n============================================================================");
				  printf("\n user record deleted successfully :\n");
				  printf("\n ===========================================================================");
			  }

			  else
			  {
				  
		            fprintf(del,"%s %s %s %s %s %d\n",pid,desc,client_name,start_date,end_date,No_Emp);
			  }
		  }
	  fclose(fp);
	  fclose(del);
          remove("../data/projectdata.txt");
	  rename("../data/temporarydata.txt","../data/projectdata.txt");
	  if(count ==0)
		{
		
			printf("record not found\n");
		}


	}
}

void update_Project()
{
	FILE *fp,*del;
	  fp=fopen("../data/projectdata.txt","r");
	  del = fopen("../data/temporarydata.txt","w");
          if(fp==NULL)
	  {
		  printf("file doesnt exits");
	  }
	  else
	  {       int choice;
		  int u_No_Emp;
		  char u_pid[MAX],u_desc[MAX],u_client_name[MAX],u_start_date[MAX],u_end_date[MAX];
		  int No_Emp;
		  char pid[MAX],client_name[MAX],start_date[MAX],end_date[MAX],desc[MAX];

                  printf("enter the pid to update");
		  scanf("%s",u_pid);
		  while(fscanf(fp,"%s%s%s%s%s%d\n",pid,desc,client_name,start_date,end_date,&No_Emp)!=EOF)
		  {
			  if(strcmp(pid,u_pid)==0)
			  {
				  printf("\n============================================================================");
				  printf("\n old record is :\n");
				  printf("desc of project : %s \n",desc);
				  printf("clientname: %s\n",client_name);
				  printf("start_date: %s\n",start_date);
				  printf("end_date: %s\n",end_date);
				  printf("No_Emp: %d \n",No_Emp);
				  printf("\n============================================================================");
				  printf("\n edit the record");
				  printf("\nwhich information to be updated");
				  printf("enter your choice");
				  scanf("%d",&choice);
				  if(choice == 1)
				  {
					  printf("\nenter the desc to update\n");
					  scanf("%s",u_desc);
					  fprintf(del ,"%s %s %s %s %s %d\n",pid,u_desc,client_name,start_date,end_date,No_Emp);
					  printf("\nchanges saved");
				  }
				  else if(choice == 2)
				  {

					  printf("\nenter the client name to update\n");
					  scanf("%s",u_client_name);
					  fprintf(del ,"%s %s %s %s %s %d\n",pid,desc,u_client_name,start_date,end_date,No_Emp);
					  system("cls");
					  printf("\nchanges saved");
				  }
				 else if(choice ==3)
				  {

					 printf("\nenter the start date to update\n");
					 scanf("%s",u_start_date);
					 fprintf(del ,"%s %s %s %s %s %d\n",pid,desc,client_name,u_start_date,end_date,No_Emp);
					 printf("\nchanges saved");
				 }

				  else if(choice == 4)
				  {

					  printf("\nenter the end date to update\n");
					  scanf("%s",u_end_date);
					  fprintf(del ,"%s %s %s %s %s %d\n",pid,desc,client_name,start_date,u_end_date,No_Emp);
					  printf("\nchanges saved");
				  }

				  else if(choice == 5)
				  {

					  printf("\nenter the No_Emps to update\n");
					  scanf("%d",&u_No_Emp);
					  fprintf(del ,"%s %s %s %s %s %d\n",pid,desc,client_name,start_date,end_date,u_No_Emp);
					  printf("\nchanges saved");
				  }
			  }
				  else
				  {

				 
					  fprintf(del,"%s %s %s %s %s %d\n",pid,desc,client_name,start_date,end_date,No_Emp);
				  }


				  
		                  fscanf(fp,"%s%s%s%s%s%d\n",pid,desc,client_name,start_date,end_date,&No_Emp);
			
	  }
				  
				  remove("../data/projectdata.txt");
				  rename("../data/temporarydata.txt","../data/projectdata.txt");
				  fclose(fp);
				  fclose(del);
}
}

void Project()
{
	
	int choice;
	project *Start= NULL;
	while(1)
	{
		printf("\n1:Add the project record\n2:Display\n3:search\n4:Delete\n5:update\n6:Back to main menu");
		printf("\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_Project();
			       break;
			case 2:display_Project();
			       break;
			case 3:search_Project( );
			       break;
			case 4:delete_Project();
			       break;
			case 5:update_Project();
			       break;
			case 6:menu_options( );
			default:
			       printf("\nInvalid Choice");
		}
	}
}



