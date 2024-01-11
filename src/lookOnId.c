#include "../include/header.h"

int lookOnId (struct employee * headLL, int whichEmpId)
{
    int i = 1, pos = 0;

    if (headLL == NULL) // if linked list is empty returns -1
    {
        return -1;
    }

    while (headLL != NULL) 
    {
        if (whichEmpId == headLL->empId) // looks to see if the empId user entered equals the one in the linked list node
        {
            pos = i; // saves the value of i in pos and returns it 
        }

        headLL = headLL-> nextEmployee; // goes to the next employee
        i++; // incremnets i if not found 
    }

    return pos;
}