#include<functions.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<struct.h>
void reports()
{
    display_Emp_Pro();
}
void display_Emp_Pro()
{
	
	FILE *fr = fopen("../data/Emp_Pro.txt","r");
	if(fr == NULL)
	{
		printf("File does not exists ");
	}
	else
	{
		
		char FIRST_NAME[MAX],LAST_NAME[MAX],PID[MAX],DESC[MAX];
		int EMPID;
		printf("\n*******************************************************\n");
		printf("*                   DETAILS OF EMPLOYESS ASSIGNED TO PROJECTS  IS               *");
		printf("\n*******************************************************\n");
		emp_pro *start=NULL;
		printf("%-10d%-10s%-10s%-10s%-10s","EMPID","FIRSTName","LASTNAME","PID","DESC");
		fscanf(fr,"%d%s%s%s%s",&EMPID,FIRST_NAME,LAST_NAME,PID,DESC);
		while(!feof(fr))
		{
			emp_pro *temp = (emp_pro *) calloc(1,sizeof(emp_pro));
			temp->EMPID = EMPID;
			strcpy(temp->FIRST_NAME,FIRST_NAME);
			strcpy(temp->LAST_NAME,LAST_NAME);
                        strcpy(temp->PID,PID);
			strcpy(temp->DESC,DESC);
			temp->link = NULL;
			if(start == NULL)
			{
				start = temp;
			}
			else
			{
				emp_pro *q = start;
				while(q->link != NULL)
					q = q->link;
				q->link = temp;
			}
			fscanf(fr,"%d%s%s%s%s",&EMPID,FIRST_NAME,LAST_NAME,PID,DESC);
		}
		fclose(fr);
		
		emp_pro *q = start;
		while(q!=NULL)
		{
			printf("\n%-10d%-10s%-10s%-10s%-10s",q->EMPID,q->FIRST_NAME,q->LAST_NAME,q->PID,q->DESC);
			q=q->link;
		}

	}

}
