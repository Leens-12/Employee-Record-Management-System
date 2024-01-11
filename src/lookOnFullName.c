#include "../include/header.h"

int lookOnFullName (struct employee * headLL, char whichName [100])
{
    //struct employee * temp;
    char * fname = strtok (whichName, " "); // splits the first name and saves it where there is a space 
    char * lname = strtok (NULL, " "); // splits and saves the last name
    char fname2[100];
    char lname2[100];

    int i = 1, pos = 0;

    if (headLL == NULL) // if linked list is empty returns -1
    {
        return -1;
    }
    else 
    {
        strcpy(fname2, headLL->fname); // saves the first name
        strcpy(lname2, headLL->lname); // saves the last name

        // compares the first and last names, as well as makes sures the linked list is not empty
        while (strcmp(fname2, fname) && strcmp(lname2, lname) && headLL != NULL) 
        {
            headLL = headLL-> nextEmployee; // goes to the next employee

            if (headLL != NULL) // checks to see if temp is empty or not
            {
                strcpy(fname2, headLL->fname); // saves the first name // employee
                strcpy(lname2, headLL->lname); // saves the last name of the next employee
            }
            i++; // increments i
        }

        pos = i; // i (index) is saved a variable called pso

    }

    return pos; // returns pos

}