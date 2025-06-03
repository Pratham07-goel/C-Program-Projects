#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void addStudent()
{
	FILE *fp=fopen("student.txt","a");
	int roll;
	char name[50];
	float marks;
	
	 printf("Enter Roll No: ");
    scanf("%d", &roll);
    printf("Enter Name: ");
    scanf(" %s", name);
    printf("Enter Marks: ");
    scanf("%f", &marks);
    
    fprintf	(fp,"%d %s %.2f\n",roll,name,marks);
    fclose(fp);
    
    printf("Student Record Added!\n");
}

void displayStudents() 
{
    FILE *fp = fopen("student.txt", "r");
    int roll;
    char name[50];
    float marks;
    
    if(fp==NULL)
    {
    	printf("No Records Found.\n");
    	return;
	}
	
	printf("\n----Student Records----\n");
	while(fscanf(fp,"%d%s%f",&roll,name,&marks)!=EOF)
	{
		printf("Roll No.:%d\n",roll);
		printf("Name:%s\n",name);
		printf("Marks:%f\n",marks);
			}
	fclose(fp);
}

void searchStudent()
{
	FILE *fp=fopen("student.txt","r");
	int roll,r;
	char name[50];
	float marks;
	int found=0;
	
	printf("\nEnter the Roll Number to search:\n");
	scanf("%d",&r);
	
	while(fscanf(fp,"%d %s%f",&roll,name,&marks)!=EOF)
	{
		if (roll==r)
		{
			printf("\nRecord Found:\n");
			printf("Roll No.:%d\nName:%s\nMarks:%.2f\n",roll,name,marks);
			found=1;
			break;
		}
	}
	if(!found)
	{
		printf("Student with Roll No.%d not found\n",r);
		fclose(fp);
	}
}

void deleteStudent()
{
	FILE *fp=fopen("student.txt","r");
	FILE *temp=fopen("temp.txt","w");
	int roll,r;
	char name[50];
	float marks;
	int found=0;
	
	if(fp==NULL)
	{
		printf("\nFile not found!\n");
		return ;
	}
	printf("Enter the Roll No. to delete:");
	scanf("%d",&r);
	
	while(fscanf(fp,"%d%s%f",&roll,name,&marks)!=EOF)
	{
		 if (roll != r) 
		 {
            fprintf(temp, "%d %s %.2f\n", roll, name, marks);
        } 
		else 
		{
            found = 1;
	}
}
	fclose(fp);
	fclose(temp);

	remove("student.txt");
	rename("temp.txt","student.txt");
	
	if(found)
	{
		printf("Student deleted successfully\n");
			}
			else
			{
				printf("Roll Number not found\n");
			}
}

int main ()
{
	int choice;
	do 
	{
		printf("==== Student Record Menu ====\n");
		printf("1.Add Student\n");
		printf("2.Display All Student\n");
		printf("3.Search Student By Roll No.\n");
		printf("4.Delete Student\n");
		printf("5.Exit\n");
		printf("Enter your choice:");
        scanf("%d", &choice);
		switch (choice) 
		{
            case 1: addStudent(); 
			break;
            case 2: displayStudents(); 
			break;
            case 3: searchStudent(); 
			break;
            case 4: deleteStudent(); 
			break;
            case 5: printf("Exiting...\n"); 
			break;
            default: printf("Invalid choice.\n");
        }
	}
	while(choice!=5);
	return 0;
}
