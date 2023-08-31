/*
 *      Author:Mahmoud Esam Ali
 *      Description :create a linked list,provide the user to add tasks,remove a task,remove all tasks and veiw tasks or print them in a table format   
 *      Date : 2023-Aug-12
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/****************************************Macro Definition Start****************************************/
#define DPRINTF(...)     {fflush(stdout); \
		fflush(stdin);  \
		printf(__VA_ARGS__);\
		fflush(stdout); \
		fflush(stdin);}
/*****************************************Macro Definition End*****************************************/


/*************************************Functions prototype Start*************************************/
void add_Task ();
int delete_Task();
void delete_all();
void view_all();
void print_tasks_table(struct STASK* head);
/**************************************Functions prototype End**************************************/


/**************************************Global Decleration Start***************************************/
struct Sdata
{
	char description[200];
    char *status[40];
	int id;
	
};
struct STASK
{
	struct Sdata Task;
	struct STASK* PNextTask;
};

struct STASK* gpFirstTask = NULL;
/***************************************Global Decleration End****************************************/

void main()
{
	int index;
	char temp[40];
    DPRINTF("\n\nchoose on of the following options:\n");
	DPRINTF("\t1: Add Task \n");
	DPRINTF("\t2: Delete Task \n");
	DPRINTF("\t3: view Tasks \n");
    DPRINTF("\t4: Show Data in Table Format \n");
	DPRINTF("\t5: Delete all \n");
	DPRINTF("\t6: Exit\n");
	DPRINTF("==============================\n");
	while (1)
	{
		DPRINTF("Select An Option : ");
		gets (temp);

		switch(atoi(temp))
		{
		case 1: add_Task ();
		break;
		case 2: delete_Task();
		break;
		case 3: view_all();
		break;
        case 4: print_tasks_table(gpFirstTask);
        break;
		case 5: delete_all();
		break;
		case 6: exit(6);
		break;
		default : DPRINTF("wrong option !");
		break;
		}
	}
}

/*********************************Functions Definition Start*******************************************/

void add_Task ()
{
	struct STASK* PNewTask ; 
	struct STASK* PLastTask ; 
	char temp[40];
	//check if empty

	if(gpFirstTask==NULL)
	{
		
		PNewTask = (struct STASK*) malloc(sizeof(struct STASK));
		gpFirstTask = PNewTask;

	}
	else
	{
		//check is not empty
		PLastTask = gpFirstTask;
		while(PLastTask->PNextTask)
			PLastTask=PLastTask->PNextTask;

		PNewTask = (struct STASK*) malloc(sizeof(struct STASK));
		PLastTask->PNextTask =PNewTask ;
	}
	//id
	DPRINTF( "Enter Task ID : ");
	gets(temp);
	PNewTask-> Task.id = atoi (temp);
	//Description
	DPRINTF( "Enter Task Description: : ");
	gets(PNewTask-> Task.description);
    //status
    DPRINTF("Is This Task Completed or Incompleted :");
    gets(PNewTask->Task.status);
	DPRINTF("Task added successfully!\n")
	
	//assign NULL to PnewTask
	PNewTask-> PNextTask = NULL;
}

int delete_Task()
{
	if(gpFirstTask==NULL){
		DPRINTF("\nEmpty List");
		DPRINTF("\n==============");
		return 0;
	}
	struct STASK* PrevTask =NULL;
	struct STASK* PselectedTask = gpFirstTask ;
	//get the selected id
	char temp[40];
	int selectedId;
	DPRINTF("\nEnter The selected ID : ");
	gets(temp);
	selectedId = atoi(temp);
	if(gpFirstTask)   //check if empty
	{
		//loop
		while(PselectedTask) //
		{
			if (PselectedTask -> Task.id == selectedId)
			{
				if(PrevTask) //The selected id is not 1st
				{
					PrevTask->PNextTask = PselectedTask->PNextTask;
					free(PselectedTask);
					return 1 ;
				}
				else  //The selected id is 1st
				{
					gpFirstTask = PselectedTask->PNextTask;
					free(PselectedTask);
					DPRINTF("\n\tTask is deleted\n");
					return 1 ;
				}


			}
			PrevTask = PselectedTask;
			PselectedTask= PselectedTask->PNextTask;  //related with while( PselectedTask )
		}
		DPRINTF("Can not find Task ID");
		return 0 ;
	}
}

void delete_all()
{
	struct STASK* PCurrentTask = gpFirstTask ;
	struct STASK* PtempTask;

	if(gpFirstTask==NULL){
		DPRINTF("\nEmpty List");
		DPRINTF("\n==============");
	}
	else
	{
		while (PCurrentTask)
		{
			PtempTask=PCurrentTask;
			free(PtempTask);
			PCurrentTask = PCurrentTask->PNextTask;
		}
	}
	gpFirstTask = NULL;
}


void view_all()
{
	struct STASK* PCurrentTask = gpFirstTask ;
	int count=0;
	if(gpFirstTask==NULL){
		DPRINTF("\nEmpty List");
		DPRINTF("\n==============\n");

	}
	else
	{
		while (PCurrentTask)
		{
			DPRINTF("\n\tTask ID     : %d", PCurrentTask->Task.id);
			DPRINTF("\n\tDescription : %s ", PCurrentTask->Task.description);
            DPRINTF("\n\tStatus : %s \n", PCurrentTask->Task.status);

			PCurrentTask = PCurrentTask->PNextTask;
			count++;
		}
	}
}

void print_tasks_table(struct STASK* head) {
  struct STASK* current_task = head;

  printf("| ID     |      Status     |\n");
  printf("|--------|---------------- |\n");

  while (current_task != NULL) {
    printf("|  %4d  |   %11s   |\n", current_task->Task.id,current_task->Task.status); 
    current_task = current_task->PNextTask;
  }
}
/**********************************Functions Definition End********************************************/