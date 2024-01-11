#include "../include/header.h"

int countEmployees (a3Emp * headLL)
{
    int count = 0;

    if (headLL == NULL)
    {
        printf("Error, Linked list is empty");
        return 0;
    }
    
    while (headLL != NULL) // goes in the while loop when linked list is not empty 
    {
        count++; // counter increments 
        headLL = headLL->nextEmployee; // goes to the next employee
    }

    return count; // returns count
}