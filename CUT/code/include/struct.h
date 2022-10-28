#pragma once
#include<macros.h>
typedef struct Employee
{
	int EmpId;
	char first_name[MAX],last_name[MAX],Edu_qua[MAX],Area_Expertise[MAX],mobile_number1[MAX],mobile_number2[MAX];
	struct Employee *link;
}employee;
typedef struct Project
{
	int No_Emp;
	char desc[MAX],client_name[MAX],start_date[MAX],end_date[MAX],pid[MAX];
	struct Project *link;
}project;
typedef struct Emp_Pro
{
	int EMPID;
	char FIRST_NAME[MAX],LAST_NAME[MAX],PID[MAX],DESC[MAX];
	struct Emp_Pro *link;
}emp_pro;
