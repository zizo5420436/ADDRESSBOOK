#include <stdio.h>
#include <unistd.h>
#include "contact.h"


int main() {
    int choice;
    int sortChoice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. Display contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
               searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                printf("Sort by:\n");
                printf("1. Name\n");
                printf("2. Phone\n");
                printf("3. Email\n");
                printf("Enter your choice: ");
                scanf("%d", &sortChoice);          
                listContacts(&addressBook,sortChoice);
                break;
            case 6:
                saveContactsToFile(&addressBook);
                printf("Contacts saved to file\n");
                usleep(800000);
                break;
            case 7:
                printf("Exiting...\n");
                usleep(800000);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
       return 0;
}

