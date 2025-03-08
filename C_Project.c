/********************************************************************
      C_Project.c
      Created on : Aug 13, 2024
      Author     : Hayam
      Description: Student Management System
********************************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>



/* A structure to represent the data needed to be stored of each student */
struct student
{
	int id;           /* Student ID   */
	char name[50];    /* Student Name */
	int age;          /* Student Age  */
	float gpa;        /* Student GPA  */
};

/* A structure to represent a node in a linked list */
struct node
{
	struct student data;
	struct node *next;
};
struct node *head=NULL;
/**********************************************************/
  char x = 0;
  int y=0;
  int op = 0;
  struct student s;
  /********************************************************/
void Add_Student(const struct student *const ptr_st);
void Display_Students(void);
void Search_Student_By_ID(int id);
void Update_Student(int id);
float Calculate_Average_GPA(void);
void Delete_Student(int id);
void Search_Student_By_GPA(float gpa);
void Search_Highest_GPA(void);
void Select_Choice(int op);
/**************************************************************/

int main(void)
{
	setvbuf(stdout,NULL,_IONBF,0);
    setvbuf(stderr,NULL,_IONBF,0);
    /*************************************************************************************/
	while(x != 1)
	{
	printf("Please, select the number of wanted operation:\n1-Add a student\n2-Display all students\n");
	printf("3-Search for a student by ID\n4-Update student information by ID\n5-Delete student by ID\n");
	printf("6-Calculate average GPA\n7-Search for highest GPA\n8-Exit\n");
	scanf(" %d",&op);
	Select_Choice( op);
	}
   return 0;
}
void Select_Choice(int op)
{
	switch (op)
		{
		case 1:
			Add_Student(&s);
			break;
		case 2:
			Display_Students();
			break;
		case 3:
			printf("Enter the ID:\n");
			scanf("%d",&y);
			Search_Student_By_ID(y);
			break;
		case 4:
			printf("Enter the ID:\n");
			scanf("%d",&y);
			Update_Student(y);
			break;
		case 5:
			printf("Enter the ID:\n");
			scanf("%d",&y);
			Delete_Student(y);
			break;
		case 6:
			printf("The average GPA: %f\n",Calculate_Average_GPA());
			break;
		case 7:
			Search_Highest_GPA();
			break;
		case 8:
			printf("Exiting.. ");
			x=1;
		}
}
/**********************************************************************/
 void Add_Student(const struct student *const ptr_st)
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

    int y=0;
    int id;
	char name[50];
	int age;
	float gpa;
	printf("Enter student ID: ");
	scanf("%d",&id);
	printf("Enter name: ");
	scanf("%s",name);
	printf("Enter age: ");
	scanf(" %d",&age);
	printf("Enter GPA: ");
	scanf(" %f",&gpa);

	struct node *current = NULL;
	current = head;
		while(current != NULL)
		{
			if(current->data.id == id)
			{
				printf("This ID is already reserved\n");
				y=1;
				return;
			}
			current = current->next;


		}
		if (y!=1)
		{

				   	struct node *current = NULL;

				   	struct node *link = (struct node*) malloc(sizeof(struct node));

				   	link->data.id = id;
			        strcpy(link->data.name , name);
				    link->data.age = age;
				   	link->data.gpa = gpa;
				   	link->next = NULL;

				   	if(head==NULL)
				   	{
				   		head = link;
				   		return;
				   	}

				   	current = head;
				   	while(current->next != NULL)
				   	{
				   		current = current->next;
				   	}


				   	current->next = link;
				   }

		}
/**********************************************************************/
void Display_Students(void)
{
	struct node *dis = head;



		while(dis != NULL)
		{
			printf("ID:%d, Name: %s, Age: %d, GPA: %f \n",dis->data.id,dis->data.name,dis->data.age,dis->data.gpa);
			dis = dis->next;
		}


}
/**********************************************************************/
void Search_Student_By_ID(int id)
{
	struct node *current = NULL;
		current = head;
			while(current != NULL)
			{
				if(current->data.id == id)
				{
					printf("ID:%d, Name: %s, Age: %d, GPA: %f \n",current->data.id,current->data.name,current->data.age,current->data.gpa);
					return;
				}
				current = current->next;


			}
			printf("This student ID not found\n ");
}
/**********************************************************************/
void Update_Student(int id)
{
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
		char name[50];
		int age;
		float gpa;

	struct node *current = NULL;
			current = head;
				while(current != NULL)
				{
					if(current->data.id == id)
					{
						printf("Enter name: ");
						scanf("%s",name);
						printf("Enter age: ");
						scanf(" %d",&age);
						printf("Enter GPA: ");
						scanf(" %f",&gpa);
						/********************/
						 strcpy(current->data.name , name);
						 current->data.age = age;
						 current->data.gpa = gpa;
						return;
					}
					current = current->next;


				}
				printf("This student ID not found\n ");
}
/**********************************************************************/
float Calculate_Average_GPA(void)
{
	int pos=0;
	float sum=0;
	float avg=0;
	struct node *current = NULL;
				current = head;
					while(current != NULL)
					{
						sum+=current->data.gpa;
						pos++;
						current = current->next;
					}
					avg=sum/pos;
					return avg;

}
/**********************************************************************/
void Delete_Student(int id)

{
	struct node *current = NULL;
	struct node *prev = NULL;
	struct node * delete_node = NULL;
	if(head==NULL)
	{
		printf("There are no students\n");
		return;
	}

	if(head->data.id == id)
	{
		delete_node = head;
		head = head->next;
		free(delete_node);
		return;
	}
	current = head->next;
	prev = head;
	while(current != NULL)
	{
		if(current->data.id == id)
		{

			delete_node = current;
			prev->next = current->next;
			free(delete_node);
			return;
		}
		prev = current;
		current = current->next;
	}

	if(delete_node == NULL)
	{
		printf("This ID is not found");
	}
}
/**********************************************************************/
void Search_Highest_GPA(void)
{
	struct node *current=NULL;
	float max;
	if(head==NULL)
	{
		printf("There are no students");
	}
	max=head->data.gpa;
	current=head->next;
	while(current != NULL)
	{
		if(current->data.gpa > max )
		{
			max=current->data.gpa;

		}current=current->next;
	}
	Search_Student_By_GPA(max);

}
/**********************************************************************/
void Search_Student_By_GPA(float gpa)
{
	struct node *current = NULL;
		current = head;
			while(current != NULL)
			{
				if(current->data.gpa == gpa)
				{
					printf("ID:%d, Name: %s, Age: %d, GPA: %f \n",current->data.id,current->data.name,current->data.age,current->data.gpa);
					return;
				}
				current = current->next;


			}
			printf("This student ID not found\n ");
}
