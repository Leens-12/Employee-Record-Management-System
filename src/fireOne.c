#include "../include/header.h"

void fireOne (a3Emp ** headLL, int whichOne)
{
    int i = 1;
    //temp is used to freeing the memory
    struct employee *temp;
     

    //key found on the head node.
    //move to head node to the next and free the head.
    if(i == whichOne)
    {
        temp = *headLL;    //backup the head to free its memory
        *headLL = (*headLL)->nextEmployee;
        free(temp);
    }
    else
    {
        struct employee *current  = *headLL;
        while(current->nextEmployee != NULL)
        {
            i++;
            //if yes, we need to delete the current->next node
            if(i == whichOne)
            {
                temp = current->nextEmployee;
                //node will be disconnected from the linked list.
                current->nextEmployee = current->nextEmployee->nextEmployee;
                free(temp);
                break;
            }
            //Otherwise, move the current node and proceed
            else
            {
                current = current->nextEmployee;
            }
          }
    }

    while (temp != NULL)
    {
        if (i == whichOne)
        {
            printf("Employee [ID: %d] fired", temp->empId);
        }
                    
        temp = temp -> nextEmployee; // goes to the next employee
        i++;
    }
}