#include "../include/header.h"

void printOne (struct employee * headLL, int whichOne)
{
    int i = 1;
    a3Emp * temp = headLL;
    
    while (temp != NULL)
    {
        if (i == whichOne)
        {
            printf("Employee #%d: \n", i);
            printf("Employee id: %d \n", temp->empId); // prints employee ID
            printf("First Name:  %s \n", temp->fname); // prints first name
            printf("Last Name: %s \n", temp->lname); // prints last name
            printf("Dependents [%d]: ", temp->numDependents); // prints the number of dependents
            for (int i = 0; i < temp->numDependents; i++){
                printf("%s ", temp->dependents[i]); // prints out the dependents
            }
            printf("\n");

        }
        temp = temp-> nextEmployee; // goes to the next employee
        i++;
    }
}