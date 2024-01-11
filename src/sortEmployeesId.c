#include "../include/header.h"

void sortEmployeesId (struct employee * headLL)
{
    struct employee *current = headLL;
    struct employee *index = NULL;
    struct employee temp;
    
    if (headLL == NULL) 
    {
        return;
    } 

    while (current != NULL) {
            // index points to the node next to current
            index = current->nextEmployee;

            
        while (index != NULL) {
            if (current->empId > index->empId) {

                // sorts the Employee's ID
                temp.empId = current->empId;
                current->empId = index->empId;
                index->empId = temp.empId;

                // Sorts Employee's first and last name
                strcpy(temp.fname,current->fname);
                strcpy(current->fname,index->fname);
                strcpy(index->fname,temp.fname);
                
                strcpy(temp.lname,current->lname);
                strcpy(current->lname,index->lname);
                strcpy(index->lname,temp.lname);

                // Sorts the Employee's Number of Dependents and Dependents
                temp.numDependents = current->numDependents;
                current->numDependents = index->numDependents;
                index->numDependents = temp.numDependents;

                temp.dependents = current->dependents;
                current->dependents = index->dependents;
                index->dependents = temp.dependents;

            }
                index = index->nextEmployee; // moves to the next employee in index
        }
        current = current->nextEmployee; // moves to the next employee in current
    }

    printAll(headLL); // prints all of them after recalling the second function

} 