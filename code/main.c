#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Create the student structure
// A linked list node
struct stud {
    char* Name;
    int ID;
    int  y, m, d; //the birth day of student // y->the year , m->month and d-> the day
    int rnum;// the roll number of student
    int sco ;//the last score of student
    struct stud* next;
};
    struct stud* head = NULL;
    struct stud* tail = NULL;
 void info(struct stud* m) // to Enter the information of student
  { printf("Enter the roll number:");
    scanf("%d", &(m->rnum));
    printf("Enter the student Name:");
    scanf("%s", &(m->Name ));
    printf("Enter the student ID :");
    scanf("%d", &(m->ID));
    printf("Enter the last score of student:");
    scanf("%d", &(m->sco));
           printf("Enter date of birth (DD MM YYYY) :");
        scanf("%d %d %d", &(m->d), &(m->m), &(m->y));

}
void display(struct stud* ptr) // to display the information of a student
 {
    printf("the roll number is : %d  ", ptr->rnum);
    printf("the name is : %s\t", ptr->Name);
    printf("the ID is : %d  ", ptr->ID);
    printf("the last score is : %d  ", ptr->sco);
    printf("the date of birth (DD MM YYYY) is : %d  %d  %d  \n\n", ptr->d, ptr->m, ptr->y);
 }
void display_all() //to display information of all students
{
    struct stud* temp=head;
    while(temp!=NULL)
        {
        display(temp);
        temp = temp->next;
        }
}


int main()
{
   head = (struct stud*)malloc(sizeof(struct stud));
    printf("1 to insert end student details\n2 to insert begging student details\n3 to insert middle student details\n4 to display all student details");
    do
    { int choice;
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:

            case 2:

            case 3:


            case 4:
              display_all();
                break;

        }

    } while (choice != 0);

}
