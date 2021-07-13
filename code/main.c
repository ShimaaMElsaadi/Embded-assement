//شيماء محمود الساعدى
// شروق على على عبد المطلب
//شيماء محمد عبده


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
// Create the student structure
// A linked list node
int cap;			//cap is the Capacity of dynamic array
int S;				//S number of filled data elements in the array.
struct stud
{
  char Name[50];
  int ID;
  int y, m, d;		//the birth day of student // y->the year , m->month and d-> the day
  int rnum;			// the roll number of student
  int sco;			//the last score of student
} data;

struct node
{

struct stud data;

struct stud *next;

};

struct node *head = NULL;

struct node *tail = NULL;

//input: a pointer to the structre of the data in the heap.
  void info (struct stud *m)		// to Enter the information of student
{

printf ("Enter the roll number:");

scanf ("%d", &(m->rnum));

getchar ();

printf ("Enter the student Name:");

scanf ("%s",m->Name);		//store a string till a new line charcter entered.
printf ("Enter the student ID :");

scanf ("%d", &(m->ID));

printf ("Enter the last score of student:");

scanf ("%d", &(m->sco));

printf ("Enter date of birth (DD MM YYYY) :");

scanf ("%d %d %d", &(m->d), &(m->m), &(m->y));

}



void createList()
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    // Input data of node from the user
   info(&head->data); // Link data field with data
   head->next = NULL; // Link address field to NULL
    // Create n - 1 nodes and add to list
    temp = head;
    for(i=2; i<=S; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        info(&newNode->data); // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL
        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
}


//display the information of a student.
//takes a pointer to the allocated space in the free store.
  void display (struct stud *ptr)	// to display the information of a student
{

printf ("the roll number is : %d  ", (ptr->rnum));

printf ("the name is : %s\t", &(ptr->Name));

printf ("the ID is : %d  ", (ptr->ID));

printf ("the last score is : %d  ", (ptr->sco));

printf ("the date of birth (DD MM YYYY) is : %d  %d  %d  \n\n", (ptr->d),
	   (ptr->m), (ptr->y));

}

//display the information of students in a linked list.
  void display_all ()			//to display information of all students
{

struct node *temp = head;

while (temp != NULL)

    {

display (temp);

temp = temp->next;

    }

}
//insert a new node in a linked list
//takes a pointer to the structure data in the free store.
  void insert_linked (struct node *newNode)
{

int choice;
int position;

  newNode = (struct node *) malloc (sizeof (struct node));

  info (&newNode->data);		// Link the data part
  printf
    ("1 to insert beginning student details\n2 to insert middle for student details\n3 to insert end  student details");


printf ("\nEnter Choice: ");

scanf ("%d", &choice);

switch (choice)

	{

case 1:

newNode->next = NULL;

if (head == NULL)

	    {

		// if head is NULL
		// set student as the new head
		head = newNode;

}

	  else

	    {

		// if list is not empty
		// insert student in beginning of head
		newNode->next = head;

head = newNode;

printf ("DATA INSERTED SUCCESSFULLY\n");

}break;


case 2:

 	//Create a new node

printf ("\nEnter position= ");

scanf ("%d", &position);


struct node *temp;


newNode->next = NULL;

if (newNode == NULL)

	      {

printf ("Unable to allocate memory.");

}


	    else

	      {

if (head == NULL)	//Checks if the list is empty
		  {

head = newNode;

tail = newNode;	//If list is empty, both head and tail would point to new node
		  }

		else

		  {

		      //Node temp will point to head
		      temp = head;


		      //Traverse through the list till the n-1 position

for (int i = 2; i <= position - 1; i++)

		      {

temp = temp->next;


if (temp == NULL)

break;

}


if (temp != NULL)

		      {

			  // Link address part of new node
			  newNode->next = temp->next;


			  // Link address part of n-1 node
			  temp->next = newNode;


printf ("DATA INSERTED SUCCESSFULLY\n");

}

		    else

		      {

printf
			  ("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");

}

}

}

break;

case 3:

	  {
if (newNode == NULL)

	      {

printf ("Unable to allocate memory.");

}

	    else

	      {

newNode->next = NULL;


temp = head;


		  // Traverse to the last node
		  while (temp != NULL && temp->next != NULL)

temp = temp->next;


temp->next = newNode;	// Link address part

printf ("DATA INSERTED SUCCESSFULLY\n");

}

}

}



}
void timelinked_insert(struct node *y) {
    clock_t str = clock();
    insert_linked(y);
     clock_t stp = clock();
    double T = (double)(stp -  str) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time taken in ms: %f", T);}

//takes a pointer to the array in the heap
//fills each element in the array with the specified number of elements
//with data variable(S).
  void Dynamic_arrayofstudents (struct stud *A)
{

int i;

for (i = 0; i < S; i++)

info ((A + i));		//Filling the data of a student from the input stream.
  return;

}


//Inserts a new student in the array
//Takes pointer the allocated space in the heap for the array
//and a structure for the new_student data in the stack.
  void arry_insert (struct stud *Temp, struct stud newNode)
{
  info(&newNode);

  int cho;			//Varible to store the choice of the user.
  printf
    ("1 to insert beginning student details\n2 to insert middle for student details\n3 to insert end  student details");

if (S == cap)

    {				// if size is not enough make size double
      cap++;

Temp = (struct stud *) realloc (Temp, cap * sizeof (struct stud));

}

printf ("\nEnter Choice: ");

scanf ("%d", &cho);

switch (cho)

    {

case 1:

for (int i = S; i > 0; i--)

	{			// shift all element right
	  *(Temp + i) = *(Temp + i - 1);

}			// insert data at the beginning
      *Temp = newNode;

S++;

break;

case 2:

      {

int po;

printf ("\nEnter position");

scanf ("%d", &po);

for (int i = S; i > po; i--)

	  {		// shift all element right
	    // from given given position
	    *(Temp + i) = *(Temp + i - 1);

}

	  // insert data at given index
	  *(Temp + po) = newNode;

S++;

break;

}

case 3:

*(Temp + S) = *(Temp + S - 1);

*(Temp + S) = newNode;

S++;

}

}


//working
  void display_all_arry (struct stud *ptr)	//to display information of all students
{

struct student *iterator;

for (int i = 0; i < S; i++)

    {

printf ("the roll number is : %d  ", ((ptr + i)->rnum));

printf ("the name is : %s\t", &((ptr + i)->Name));

printf ("the ID is : %d  ", ((ptr + i)->ID));

printf ("the last score is : %d  ", ((ptr + i)->sco));

printf ("the date of birth (DD MM YYYY) is : %d  %d  %d  \n\n",
	       ((ptr + i)->d), ((ptr + i)->m), ((ptr + i)->y));

}
}
void timearray_insert(struct stud *tm, struct stud nN) {
    clock_t str = clock();
    arry_insert(tm, nN);
    clock_t stp = clock();
    double T = (double)(stp -  str) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time taken in ms: %f", T);}

void driver_code()
{ int c;
  int l=1;
  int b=1;
  struct stud *f = (struct stud *)malloc(cap * sizeof(struct stud));

    printf("\n Enter the number of students you want to add\n");
    scanf("%d", &S);
    printf("1 to working by dynamic array\n 2 to working by linked list ");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:

        printf("\n Enter the Capacity of array\n");
        scanf("%d", &cap);
        Dynamic_arrayofstudents(f);


    while(b==1)
   { printf("\n what do you want to do ?\n Enter\n 0 if no\n 1 if you want to insert in array\n 2 if you want to calculate time and insert\n 3 if display_all_arry \n ");
    int m;

    scanf("%d", &m);
    if  (m==0)
    exit(0);
    else if (m==1)
    { struct stud st;

        arry_insert(f, st);}
    else if (m==2)
    { struct stud s;
      timearray_insert(f,s);}

    else if(m==3)
      display_all_arry(f);
     printf("\n do you want other thing?\n");
     printf(" Enter\n 0 if no\n 1 if yes \n ");
    scanf("%d", &b);}
     break;

    case 2:
    createList();

    while(l==1)
    {
    printf("\n what do you want to do?\n Enter\n 0 if no\n 1 if you want to insert in list\n 2  if you want to calculate time and insert\n 3 if display_all_linked \n ");
    int o;
    scanf("%d", &o);
    if  (o==0)
    exit(0);
    else if (o==1)
    { struct node *st;

        insert_linked(st);}
    else if (o==2)
    { struct node *t;
        timelinked_insert(t);}

    else if(o==3)
       display_all();
     printf("\n do you want other thing?\n");
     printf(" Enter\n 0 if no\n 1 if yes \n ");
    scanf("%d", &l);}


    }

    }
    while(0);

}


int main ()
{
    printf(" Welcome in our c program\n");
    printf(" The project done by students:\n");
    printf(" Shimaa Mahmoud Elsaidy\n");
    printf(" Sherouk ALi Ali Abd Elmotalb\n");
    printf(" Shimaa Mohamad Abdo\n");
    printf(" Lets start\n");

driver_code ();
struct stud data;

struct stud *next;
printf("the size of the structure:\n");
printf("%d\n",sizeof(data));
printf("the size of one node:\n");
printf("%d\n",sizeof(next)+sizeof(data));
return 0;

}


