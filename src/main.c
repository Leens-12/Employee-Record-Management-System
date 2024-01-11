#include "../include/header.h"

int main (int argc, char * argv[]){

    int choice; // saves the value for the menu

    struct employee * head;
    struct employee * temp;

    int whichOne; // saves index value a user is searching for
    int whichEmpId; // saves empID a user is searching for 
    int lookOnIdPosition; // saves the return value (position) of where the ID was found
    int lookOnFullNamePosition; // saves the return value (position) of where the full name was found
    int result; // saves the count of employees 
    char whichName [100]; // saves the full name the user is looking for 
    char choice2; // saves the y/n value a user is inputing for function 9

    char file [MAX_LENGTH] = "proFile.txt";  // saves the file name

    loadEmpData (&head, file);

    
    do {
        printf ("\nHere is the menu \n\n");

        printf ("1. Add a new employee\n"); //adds a new employee to the list
        printf ("2. Print data of all employees\n"); // prints out all the employees in a given linked list
        printf ("3. Print data of the nth employee\n");  // prints out an employee from the given index
        printf ("4. Search for employee based on empId\n"); // prints out the employee from given id 
        printf ("5. Search for employee based on full name\n"); // prints out the employee from given full name as user input
        printf ("6. Count the total number of employees\n"); // returns the total count of employees and prints it out
        printf ("7. Sort the employees based on their empId\n"); // sorts employees and prints it out
        printf ("8. Remove the nth employee in the current LL\n"); // fires one employee in a said position
        printf ("9. Remove all employees in the current LL\n"); // fires all the employees
        printf ("10.Exit\n"); // exit
        
        printf ("\nEnter your choice: ");
        scanf ("%d", &choice);
        printf("\n");

        switch(choice)
        {
            case 1: 
                recruitEmployee(&head);
                break;
                
            case 2: 
                temp = head;

                if (temp == NULL) // Checks if the linked lists is empty 
                {
                    printf("Error, Linked list is empty");
                }

                printf("\n");
                printAll(temp);
                break;

            case 3: 
                temp = head;

                if (temp == NULL) // Checks if the linked lists is empty 
                {
                    printf("Error, Linked list is empty");
                }

                printf("Enter a Position: ");
                scanf("%d", &whichOne);
                printOne(temp, whichOne);
                break;

            case 4: 
                temp = head;
                printf("Enter an employee ID: "); // takes in the id through user input 
                scanf ("%d", &whichEmpId);
                lookOnIdPosition = lookOnId(temp, whichEmpId); // gets its postion 

                if (lookOnIdPosition == -1) // checks if the return value is -1
                {
                    printf("Error! employee was not found");
                }

                // else prints out the employee
                struct employee *currentHead = temp;
                int i = 1;

                while (currentHead != NULL)
                {
                    if (i == lookOnIdPosition)
                    {
                        printf("Employee id: %d \n", currentHead->empId); // prints employee ID
                        printf("First Name:  %s \n", currentHead->fname); // prints first name
                        printf("Last Name: %s \n", currentHead ->lname); // prints last name
                        printf("Dependents [%d]: ", currentHead->numDependents); // prints the number of dependents
                        for (int j = 0; j < currentHead ->numDependents; j++){
                            printf("%s ", currentHead->dependents[j]); // prints out the dependents
                        }
                        printf("\n");
                    }

                    currentHead = currentHead  -> nextEmployee; // goes to the next employee
                    i++;
                }
                    
                break;

            case 5: 
                temp = head;
                printf("Enter the full name of the employee: "); // takes in the full name through user input 
                getchar();
                fgets(whichName, 100, stdin); // and saves it in whichName

                whichName[strlen(whichName) - 1] = '\0'; // gets rid of the null character

                lookOnFullNamePosition = lookOnFullName(temp, whichName); // saves pos in lookOnFullNamePosition variable

                if (lookOnFullNamePosition == -1) // checks if the return value is a -1 
                {
                    printf("Error! employee was not found");
                }

                // or else prints out the employee
                struct employee *current = temp;
                int k = 1;

                while (current != NULL)
                {
                    if (k == lookOnFullNamePosition)
                    {
                        printf("Employee id: %d \n", current->empId); // prints employee ID
                        printf("First Name:  %s \n", current->fname); // prints first name
                        printf("Last Name: %s \n", current->lname); // prints last name
                        printf("Dependents [%d]: ", current->numDependents); // prints the number of dependents
                        for (int j = 0; j < current->numDependents; j++){
                            printf("%s ", current->dependents[j]); // prints out the dependents
                        }
                        printf("\n");
                    }

                    current = current -> nextEmployee; // goes to the next employee
                    k++;
                }
                
                break;

            case 6:
                temp = head;
                result = countEmployees(temp); // saves the count
                printf("Total number of employees = %d\n", result); 
                break;

            case 7: 
                temp = head;

                if (temp == NULL) // Checks if the linked lists is empty 
                {
                    printf("Error, Linked list is empty");
                }

                sortEmployeesId(temp); 
                break; 

            case 8: 
                temp = head;

                if (temp == NULL) // Checks if the linked lists is empty 
                {
                    printf("Error, Linked list is empty");
                }

                result = countEmployees(temp);
                printf("\nCurrently there are %d employees." , result); // prints the current total

                // asks for user input for index
                printf("\nWhich employee do you wish to fire - enter a value between 1 and %d: ", result);
                scanf("%d", &whichOne);

                fireOne(&temp, whichOne); 

                printf("\nThere are now %d employees", result-1); // prints out the total count of employees after fireOne function
                
                break;
             
            case 9: 
                temp = head;

                if (temp == NULL) // Checks if the linked lists is empty 
                {
                    printf("Error, Linked list is empty");
                }

                // asks whether or not he/she wants to fire people, 
                printf("Are you sure you wante to fire everyone (y/n): ");
                getchar();
                scanf("%c", &choice2);

                // if yes, it deletes and fires all of them
                if (choice2 == 'Y' || choice2 == 'y')
                {
                    fireAll(&temp);
                    printf("All fired. Linked List is now empty.");
                }

                break;

            case 10: 
                printf("Exiting!!\n");
                break;
            
            default: printf ("\nThat is an invalid choice\n");

        }

    }while (choice != 10);

}
