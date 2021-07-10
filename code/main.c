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
  void
info (struct stud *m)		// to Enter the information of student
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



















































void driver_code()
{ int c;
int l=1;
 int b=1;
 struct stud *f = (struct stud *)malloc(cap * sizeof(struct stud));
 
    printf("\n Enter the number of students you want to add\n");
    scanf("%d", &S);
     printf("1 to working by dynamic arry\n2 to working bylinked list ");
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
   { printf("\n do you want any thing?\n Enter\n 0 if no\n 1 if arry_insert\n 2 if calculate timearray_insert\n 3 if display_all_arry \n ");
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
     printf(" Enter\n 0 if no\n1 if yes \n ");
    scanf("%d", &b);}
     break;
        
    case 2:
    createList();
    
    while(l==1)
    { 
    printf("\n do you want any thing?\n Enter\n 0 if no\n1 if linked_insert\n 2  if calculate timearray_insert\n3 if display_all_linked \n ");
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
     printf(" Enter\n 0 if no\n1 if yes \n ");
    scanf("%d", &l);}
    
    
    }
        
    }
    while(0);
    
}
    

int main () 
{

driver_code ();
return 0;

}
