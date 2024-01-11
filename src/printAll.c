#include "../include/header.h"

void printAll (struct employee * headLL){

    int i = 1; // Tells the number of the employee it is, like 1 or 2 or 3, etc

    while (headLL != NULL)
    {
        printf("Employee #%d: \n", i); 
        printf("Employee id: %d \n", headLL->empId); // prints employee ID
        printf("First Name:  %s \n", headLL->fname); // prints first name
        printf("Last Name: %s \n", headLL->lname); // prints last name
        printf("Dependents [%d]: ", headLL->numDependents); // prints the number of dependents
        for (int i = 0; i < headLL->numDependents; i++){
            printf("%s ", headLL->dependents[i]); // prints out the dependents
        }
        printf("\n");
        i++; 
        headLL = headLL -> nextEmployee; // goes to the next employee

        printf("\n");
    }

    printf("Currently, there are %d employees\n", i-1); // prints out all the current employees

}