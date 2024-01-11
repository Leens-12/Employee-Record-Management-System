#include "../include/header.h"

// Why is it not letting me add more dependents when I say Y or y

void recruitEmployee (struct employee ** headLL){
    
    char fname [MAX_LENGTH];
    char lname [MAX_LENGTH];
    char choice = 'y';
    int numDependents = 0;
    int empId = 0; 
    int lenFName;
    int lenLName;
    int sum = 0;

    srand(time(0));

    /* 1. allocate node */
    struct employee *newEmployee = malloc(sizeof(struct employee));
    struct employee *temp = *headLL;  /* used in step 5*/
    struct employee *temp1 = *headLL; 
   
    /* 2. put in the data  */
    printf("Enter the first name of the employee: "); // adds first name
    scanf("%s", fname);

    // calulates the sum of the ASCII values of charaters in the firstName
    lenFName = strlen(fname);
    for (int i = 0; i < lenFName; i++)
    {
        sum = sum + fname[i];
    }
    

    printf("Enter the last name of the employee: "); // adds last name
    scanf("%s", lname);
    lenLName = strlen(lname); // calculates the lenght of the lastName

    // Adds the dependents in an array
    while (choice == 'Y' || choice == 'y')
    {
      
        if (numDependents == 0) {
            newEmployee->dependents =  malloc (sizeof(char *));

        }
        else {
            newEmployee->dependents  = realloc( newEmployee->dependents , sizeof(char *) * (numDependents+1));
        }
        
        newEmployee->dependents [numDependents] = calloc (MAX_LENGTH, sizeof(char));

        printf("Enter name of dependent #%d: ", numDependents + 1);
        scanf("%s", newEmployee->dependents [numDependents]);

        printf("Do you have any more dependents (y/n)?  ");
        scanf("%c ", &choice);

        getchar();
        numDependents++;
    }


    if (numDependents == 1)
    {
        printf("\nYou have %d dependent", numDependents); // returns the total number of dependents
    }
    else {
        printf("\nYou have %d dependents", numDependents); // returns the total number of dependents
    }

    empId = sum + lenLName; // calulates the empId
    while (temp1 != NULL)
    {
        if (empId == temp1->empId)
        {
            empId = empId + (rand() % (999 - 1 + 1) + 1);
        }
        temp1 = temp1->nextEmployee;
    }

    printf("\nYour computer-generated empId is %.2d", empId); // generates the computer generated empId
    
    strcpy(newEmployee->fname, fname);
    strcpy(newEmployee->lname, lname);
    newEmployee->empId = empId;
    newEmployee->numDependents = numDependents;
  
    /* 3. This new node is going to be the last node, so make next 
          of it as NULL*/
    newEmployee->nextEmployee = NULL;
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*headLL == NULL)
    {
       *headLL = newEmployee;
       return;
    }  
   
    /* 5. Else traverse till the last node */
    while (temp->nextEmployee != NULL)
        temp = temp->nextEmployee;
   
    /* 6. Change the next of last node */
    temp->nextEmployee = newEmployee;
    return;   
}