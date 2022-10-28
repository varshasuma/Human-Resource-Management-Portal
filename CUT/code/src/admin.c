#include<macros.h>
#include<string.h>
#include<stdlib.h>
#include<functions.h>
#include<stdio.h>
int admin( )
{
	FILE *info;
	info = fopen("../data/admin_password.txt","r");

	if (info == NULL)
	{
		printf("\nFile does not exists ");
		return 0;
	}
	else
	{
		clear( );
		char adminuser[MAX] , adminpass[MAX] , adminusername[MAX] , adminpassword[MAX];
		fscanf(info,"%s %s",adminuser,adminpass);
		fclose(info);
		
		printf("\nEnter the username ");
		scanf("%s",adminusername);	
		printf("\nEnter the Password ");
		scanf("%s",adminpassword);
		

		if( strcmp(adminuser,adminusername)==0 && strcmp(adminpass,adminpassword)==0)
		{
			printf("**************************************************");
			printf("\nAdminLogin sucessfully\n");
			printf("**************************************************");
			delay(2);
			menu_options();
		}
		else 
	        {
			printf("\nthe username and password does not match");
			printf("enter the login details again\n");
			admin();
		}

	}
}
