#include "../include/header.h"

void fireAll (a3Emp ** headLL)
{
    struct employee *current = (struct employee * ) (*headLL);
    struct employee *next;

    // traverses through the linked list
   while (current != NULL)
   {
        // updates pointer to node
        next = current->nextEmployee;
        current = next;
        free(current); // frees the memory
   }

   *headLL = NULL; // idicating linked list is empty
}