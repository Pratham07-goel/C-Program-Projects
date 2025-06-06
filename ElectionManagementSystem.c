#include <stdio.h>
#include <string.h>
#define MAX 100
	int x1=0,x2=0,x3=0,x4=0;
struct voter
{
	int age;
	char name[50];
	char partyName[100];
};
int addvoter (struct voter s[],int n)
{
	if(n>=MAX)
	{
		printf("Maximum limit reached\n");
		return n;
	}
	 printf("\nEnter Age:");
    scanf("%d",&s[n].age);
    if(s[n].age>=18)
    {
    	printf("\nelgible for vote\n\n");
	}
	else
	{
		  	printf("sorry but voting is only for 18 and above!\n");
		return 0;
	}
    printf("\nEnter Name: ");
    scanf(" %s", s[n].name);
 	printf("Voter's details added successfully!\n");
 	return n+1;
}
void VoteParty(struct voter s[],int n)
{
	printf("Choose the party to vote\n");
	int x;
	 printf("Press 1 to vote for BJP\n");
        printf("Press 2 to vote for INC\n");
        printf("Press 3 to vote for AAP\n");
        printf("Press 4 to vote for Akali Dall\n");
        	printf("enter the value for x\n");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
		printf("Voted for BJP\n");
		x1++;
		break;
		case 2:
		printf("Voted for INC\n");
		x2++;
		break;
		case 3:
		printf("Voted for AAP\n");
		x3++;
		break;
		case 4:
		printf("Voted for Akali Dall\n");
		x4++;
		break;
		default:
			printf("no party choosen\n Try again");
		}
	printf("\nVote added successfully\n");		
}

void displayAll(struct voter s[],int n)
{
	 printf("\nAll voter's Records:\n");
    printf("Age\tName\n");
    int i;
    	for(i=0;i<n;i++)
    	{
    	 printf("%d\t%-15s\n",s[i].age,s[i].name);
    	 // -15 da mtlb ki 15 character da tab hove ('-' mtlb left se)
		}
}
void result(struct voter s[],int n) 
{
    printf("\nvotes for BJP: %d\n",x1);
        printf("\nvotes for INC: %d\n",x2);
	    printf("\nvotes for AAP: %d\n",x3);
    printf("\nvotes for Akali Dall: %d\n",x4);
    if (x1 >= x2 && x1 >= x3 && x1 >= x4) {
        printf("BJP will be the ruling party with: %d\n", x1);
    } else if (x2 >= x1 && x2 >= x3 && x2 >= x4) {
        printf("INC will be the ruling party: %d\n", x2);
    } else if (x3 >= x1 && x3 >= x2 && x3 >= x4) {
        printf("AAP will be the ruling party: %d\n", x3);
    } else {
        printf("Akali Dall will be the ruling party: %d\n", x4);
    }
}

int main()
{
	 struct voter voter[MAX];
	int count=0;
	int choice;
	do {
        printf("\n===== voter Management Data =====\n");
        printf("1. Add Voters Data\n");
        printf("2. Choose the party to be Voted\n");
        printf("3. Display All Voters\n");
        printf("4. Result for this Election \n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            count = addvoter(voter, count);
        } else if (choice == 2) {
            VoteParty(voter, count);
        }else if (choice == 3) {
            displayAll(voter, count);
        } else if (choice == 4) {
            result(voter, count);
        } else if (choice == 5) {
            printf("Exiting... Thank you!\n");
        }
    } while (choice != 5);
     
	     return 0;
}
