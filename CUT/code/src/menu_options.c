#include<stdio.h>
#include<stdlib.h>
#include<functions.h>
void menu_options( )
{
	while(1)
	{
		clear( );
		printf("\nPress 1 for Employee\n\n");
		printf("Press 2 for project\n\n");
		printf("Press 3 for reports\n\n");
		printf("press 4 for Employee_Project\n\n");
		printf("press 5 for Exit\n\n");
		printf("Please Enter your choice\n\n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:Employee();
		       break;
		case 2:Project(); 
		       break;  
		case 3:reports();
		       break;
		case 4:Emp_Pro();
		       break;
		case 5:exit(0);
		default:
		       printf("\nInvalid choice");
		}

	}
}
