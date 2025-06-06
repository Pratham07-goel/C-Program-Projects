#include <stdio.h>
#include <string.h>
#define MAX 100
struct student
{
	int roll;
	char name[50];
	float marks;
};
int addstudent (struct student s[],int n)
{
	if(n>=MAX)
	{
		printf("Maximum limit reached\n");
		return n;
	}
	 printf("Enter Roll No:");
    scanf("%d",&s[n].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s[n].name);
    printf("Enter Marks: ");
    scanf("%f", &s[n].marks);
 	printf("students added successfully!\n");
 	return n+1;
}
void displayAll(struct student s[],int n)
{
	 printf("\nAll Student Records:\n");
    printf("Roll\tName\tMarks\n");
    int i;
    	for(i=0;i<n;i++)
    	{
    	 printf("%d\t%-15s\t%.2f\n",s[i].roll,s[i].name,s[i].marks);
    	 // -15 da mtlb ki 15 character da tab hove ('-' mtlb left se)
		}
}
void searchByRoll(struct student s[],int n) 
{
    int roll;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);
     int found = 0;
     int i;
    for (i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            printf("\nRecord Found:\n");
            printf("Roll: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No student found with roll number %d\n", roll);
    }
}
int main() {
    struct student students[MAX];
    int count = 0;
    int choice;
    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            count = addstudent(students, count);
        } else if (choice == 2) {
            displayAll(students, count);
        } else if (choice == 3) {
            searchByRoll(students, count);
        } else if (choice == 4) {
            printf("Exiting... Thank you!\n");
        } else {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);
    return 0;
}
