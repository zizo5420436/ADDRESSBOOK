#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "contact.h"
#include "populate.h"

int selectedContactIndex = -1;
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    loadContactsFromFile(addressBook);
    //populateAddressBook(addressBook);
}
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    // 1 - Sort by name
    if (sortCriteria!=1 && sortCriteria!=2 && sortCriteria!=3 )
    {
        printf("Invalid choice\n");
        return;
    }
    printf("\n-------------Contacts in the Address Book-------------\n");
    if(sortCriteria == 1)
    {
        for(int i=0;i<addressBook->contactCount;i++)
        {
            for(int j=i+1;j<addressBook->contactCount;j++)
            {
                if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0)
                {
                    char temp[100];
                    strcpy(temp,addressBook->contacts[i].name);
                    strcpy(addressBook->contacts[i].name,addressBook->contacts[j].name);
                    strcpy(addressBook->contacts[j].name,temp);

                }
            }
        }
    }
    //sort by phone
    else if(sortCriteria==2)
    {
        for(int i=0;i<addressBook->contactCount;i++)
        {
            for(int j=i+1;j<addressBook->contactCount;j++)
            {
                if(strcmp(addressBook->contacts[i].phone,addressBook->contacts[j].phone)>0)
                {
                    char temp[100];
                    strcpy(temp,addressBook->contacts[i].phone);
                    strcpy(addressBook->contacts[i].phone,addressBook->contacts[j].phone);
                    strcpy(addressBook->contacts[j].phone,temp);    
                }
            }
        }
    }
    //sort by email
    else if(sortCriteria==3)
    {
        for(int i=0;i<addressBook->contactCount;i++)
        {
            for(int j=i+1;j<addressBook->contactCount;j++)
            {
                if(strcmp(addressBook->contacts[i].email,addressBook->contacts[j].email)>0)
                {
                    char temp[100];
                    strcpy(temp,addressBook->contacts[i].email);
                    strcpy(addressBook->contacts[i].email,addressBook->contacts[j].email);
                    strcpy(addressBook->contacts[j].email,temp);
                }
            }
        }
    }
    /*system("clear"); 
    printf("Loading");
    fflush(stdout); 
    for (int i = 0; i < 3; i++) {
        usleep(800000); 
        printf(".");
        fflush(stdout); 
    }
    usleep(800000); 
    system("clear"); 
    usleep(500000); */
    printf("%-20s %-15s %-15s\n", "Name", "Phone", "Email");
    printf("%-20s %-15s %-15s\n", "----------------", "------------", "-----------------");
    
    for(int i=0;i<addressBook->contactCount;i++)
        {
            printf("%-20s %-15s %-15s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            
            //printf("Email: %s\n",addressBook->contacts[i].email);
        }

    printf("\nPress 1 for main menu\n");
    {
        int choice;
        scanf("%d",&choice);
        if(choice == 1)
        {
        system("clear"); 
       /* printf("Loading");
        fflush(stdout); 
        for (int i = 0; i < 3; i++) {
            usleep(800000); 
            printf(".");
            fflush(stdout); 
        }
        usleep(800000); 
        system("clear"); 
        usleep(500000); */
            return;
        }

    }return;   
}
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    int flag=0;
    int count=0;
    printf("--------Enter the contacts details----------\n");
    printf("Enter the name of the contact: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
    while(1){   
        printf("Enter the phone number of the contact: ");
        scanf(" %s", addressBook->contacts[addressBook->contactCount].phone);
        // Validate phone number length and digits in one loop 
        if(strlen(addressBook->contacts[addressBook->contactCount].phone) != 10)
        {
            printf("Invalid!.The phone number should be of 10 digits\n");
            count++;
            if(count>=5)
            {
                return;
            }
            continue;
        }
        // Validate phone number digits
        for (int i = 0; i <10; i++)
        {
            flag=0;
            if(addressBook->contacts[addressBook->contactCount].phone[i] < '0' || addressBook->contacts[addressBook->contactCount].phone[i] > '9')
            {
                
                printf("Invalid!.The phone number should be in digit\n");
                flag=1;
                count++;
                if(count>=5)
                {
                    return;
                }
                break;
            }
        }
        if(flag==1)
        {
            continue;
        }
        // Validate phone number uniqueness
        if(addressBook->contactCount > 0)
        {
            flag=0;
            for(int i = 0; i < addressBook->contactCount; i++)
            {
                if(strcmp(addressBook->contacts[addressBook->contactCount].phone, addressBook->contacts[i].phone) == 0)
                {
                    
                    printf("Phone number already exists\n");
                    flag=1;
                    count++;
                    if(count>=5)
                    {
                        return;
                    }
                    break;   
                }
            }if(flag==1)
            {
                continue;
            }
        }break;
    }
   
    //Take email as input
    count=0;
    while(1)
    {
        printf("Enter the email of the contact: "); 
        scanf(" %s", addressBook->contacts[addressBook->contactCount].email);
        // Validate email
        for (int  i = 0; i < addressBook->contactCount; i++)
        {   flag=0;
            if(strcmp(addressBook->contacts[addressBook->contactCount].email, addressBook->contacts[i].email) == 0)
            {
                
                printf("Email already exists\n");
                flag=1;
                count++;
                if(count>=5)
                {
                    return;
                }
                break;
            }
        }
        if(flag==1)
        {
            continue;
        }
        if((strstr(addressBook->contacts[addressBook->contactCount].email, "@") == NULL)||(strstr(addressBook->contacts[addressBook->contactCount].email, ".com") == NULL))
        {
            printf("Invalid email\n");
            flag=1;
            count++;
            if(count>=5)
            {
                return;
            }
        }
        if(flag==1)
        {
            continue;
        }
        char *ptr = strstr(addressBook->contacts[addressBook->contactCount].email, "@");
        char *ptr1 = strstr(addressBook->contacts[addressBook->contactCount].email, ".com");
        if(ptr>ptr1)
        {
            printf("Invalid email\n");
            flag=1;
            count++;
            if(count>=5)
            {
                return;
            }
        }
        if(addressBook->contacts[addressBook->contactCount].email[0] == '@' || addressBook->contacts[addressBook->contactCount].email[0] == '.'||strstr(addressBook->contacts[addressBook->contactCount].email,"@.com")!=NULL)
        {
            printf("Invalid email\n");
            flag=1;
            count++;
            if(count>=5)
            {
                return;
            }
        }
        if(flag==1)
        {
            continue;
        }
        int atcount=0;
        int dotcomcount=0;
        for(int i=0;i<strlen(addressBook->contacts[addressBook->contactCount].email);i++)
        {
            if(addressBook->contacts[addressBook->contactCount].email[i]=='@')
            {
                atcount++;
            }
            if(addressBook->contacts[addressBook->contactCount].email[i]=='.')
            {
                dotcomcount++;
            }
        }
        if(atcount>1 || dotcomcount>1)
        {
            printf("Invalid email\n");
            flag=1;
            count++;
            if(count>=5)
            {
                return;
            }
        }
        if(flag==1)
        {
            continue;
        }
        break;
    }
    addressBook->contactCount++;
    /*system("clear"); 
    printf("Loading");
    fflush(stdout); 
    for (int i = 0; i < 3; i++) {
        usleep(800000); 
        printf(".");
        fflush(stdout); 
    }
    usleep(800000); 
    system("clear"); 
    usleep(500000); */
    printf("Contact created successfully\n");
    sleep(1);
}
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    char str[50];
    int indices[100];
    printf("Enter the name or Phone Number:");
    scanf("%s",str);
    int found = 0;
    int k=1;
    for(int i=0;i<addressBook->contactCount;i++)
    {
        
        if(strstr(addressBook->contacts[i].phone,str)||strstr(addressBook->contacts[i].name,str)||strstr(addressBook->contacts[i].email,str))
        {
            //printf("Contact found\n");
            
            printf("%d %s \n",k,addressBook->contacts[i].name);
            indices[k-1]=i;
            k++;
            //printf("Phone: %s\n",addressBook->contacts[i].phone);
            //printf("Email: %s\n",addressBook->contacts[i].email);
            found = 1;
        }  
    }
    if(found==1)
    {
        printf("\nSelect the contact: ");
            int serial;
            while(1)
            {
                scanf("%d", &serial);
                if (serial > 0 && serial <= k) {
                    int idx = indices[serial - 1];
                    selectedContactIndex = idx;
                    /*system("clear"); 
                    printf("Loading");
                    fflush(stdout); 
                    for (int i = 0; i < 3; i++) {
                        usleep(800000); 
                        printf(".");
                        fflush(stdout); 
                    }
                    usleep(800000); 
                    system("clear"); 
                    usleep(500000); */
                    printf("\n-----------------------------------------\n");
                    printf("Details of Selected Contact:\n");
                    printf("-----------------------------------------\n");
                    printf("Name : %s\n", addressBook->contacts[idx].name);
                    printf("Phone: %s\n", addressBook->contacts[idx].phone);
                    printf("Email: %s\n", addressBook->contacts[idx].email);
                    break;
                    }
                    else{
                        printf("\nInvalid Serial Number.Please Enter correctly : ");

                    }
            }
    }
    else
    {
        printf("No contact found\n");
        usleep(800000);
        /*usleep(800000);
        system("clear"); 
        printf("Loading");
        fflush(stdout); 
        for (int i = 0; i < 3; i++) {
            usleep(800000); 
            printf(".");
            fflush(stdout); 
        }
        usleep(800000); 
        system("clear"); 
        usleep(500000); */
    }
    

    printf("\nPress 1  to continue\n");
    {
        int choice;
        scanf("%d",&choice);
        if(choice == 1)
        { 
            return;
        }
    }return;
}
void editContact(AddressBook *addressBook)
{
    selectedContactIndex = -1;
    int flag=0;
    int count=0;
    searchContact(addressBook);
	if (selectedContactIndex == -1) {
        printf("No contact selected for editing.\n");
        return;
    }else
    {
       /* system("clear");
        printf("Loading...\n");
        sleep(1);
        system("clear");*/
        printf("---------------------------\n");
        printf("Edit the contact details\n");
        printf("---------------------------\n");
        printf("1.Name\n2.Phone\n3.Email\n");
        printf("\nEnter the Choice Number : ");
        int edit;
        count=0;
        while(1)
        {
            scanf("%d",&edit);
            if(edit!=1 && edit!=2 && edit!=3)
            {
                printf("Invalid choice.please Re-enter the choice\n");
                count++;
                if(count>=5)
                {
                    printf("Too many invalid attempts. Exiting...\n");
                    return;

                }continue;

            }
            break;
        }
        
        if(edit==1)
        {
            char Newname[20];
            printf("\nEnter the new name : ");
            scanf(" %[^\n]",Newname);
            strcpy(addressBook->contacts[selectedContactIndex].name,Newname);
            printf("Name is updated successfully\n");
            usleep(800000);
        }else if(edit==2)
        {
            char Newphone[20];
            while(1)
            {
                printf("\nEnter the new Phone : ");
                scanf(" %[^\n]",Newphone);
                if(strlen(Newphone) != 10)
                {
                    /*system("clear"); // Clear the screen at the start
                    printf("Loading");
                    fflush(stdout); // Ensure "Loading" is displayed immediatel
                    for (int i = 0; i < 3; i++) {
                        usleep(800000); // 500 milliseconds delay
                        printf(".");
                        fflush(stdout); // Ensure each dot is displayed immediately
                    }
                    usleep(800000); 
                    system("clear"); // Clear the screen after the dots
                    usleep(500000); // 500 milliseconds delay */
                    printf("Invalid!.The phone number should be of 10 digits\n");
                    count++;
                    if(count>=5)
                    {
                        return;
                    }
                    continue;
                }
                // Validate phone number digits
                for (int i = 0; i <10; i++)
                {
                    flag=0;
                    if(Newphone[i] < '0' || Newphone[i] > '9')
                    {
                        /*system("clear"); // Clear the screen at the start
                        printf("Loading");
                        fflush(stdout); // Ensure "Loading" is displayed immediatel
                        for (int i = 0; i < 3; i++) {
                            usleep(800000); // 500 milliseconds delay
                            printf(".");
                            fflush(stdout); // Ensure each dot is displayed immediately
                        }
                        usleep(800000); 
                        system("clear"); // Clear the screen after the dots
                        usleep(500000); */
                        printf("Invalid!.The phone number should be in digit\n");
                        flag=1;
                        count++;
                        if(count>=5)
                        {
                            return;
                        }
                        break;
                    }
                }
                if(flag==1)
                {
                    continue;
                }
                //uniqueness of phone
                if(addressBook->contactCount > 0)
                {
                    flag=0;
                    for(int i = 0; i < addressBook->contactCount; i++)
                    {
                        if(strcmp(Newphone, addressBook->contacts[i].phone) == 0)
                        {
                            printf("Phone number already exists\n");
                            flag=1;
                            count++;
                            if(count>=5)
                            {
                                return;
                            }
                            break;   
                        }
                    }if(flag==1)
                    {
                        continue;
                    }
                }
                strcpy(addressBook->contacts[selectedContactIndex].phone,Newphone);
                /*system("clear"); 
                printf("Loading");
                fflush(stdout); 
                for (int i = 0; i < 3; i++) {
                    usleep(800000); 
                    printf(".");
                    fflush(stdout); 
                }
                usleep(800000); 
                system("clear"); 
                usleep(500000); */
                printf("Phone number updated successfully\n");
                usleep(800000);
                break;
            }
            
        }   
        else if(edit==3)
        {
            char Newemail[20];
            while(1)
            {
                printf("\nEnter the new email : ");
                scanf(" %[^\n]",Newemail);
                for (int  i = 0; i < addressBook->contactCount; i++)
                { 
                    flag=0;
                    if(strcmp(Newemail, addressBook->contacts[i].email) == 0)
                    {
                        printf("Email already exists\n");
                        flag=1;
                        count++;
                        if(count>=5)
                        {
                            return;
                        }
                        break;
                    }
                }
                if(flag==1)
                {
                    continue;
                }
                if ((strstr(Newemail, "@") == NULL)&&(strstr(Newemail, ".com") == NULL))
                {
                    printf("Invalid email\n");
                    flag=1;
                    count++;
                    if(count>=5)
                    {
                        return;
                    }
                }
                if(flag==1)
                {
                    continue;
                }
                char *ptr = strstr(Newemail, "@");
                char *ptr1 = strstr(Newemail, ".com");
                if(ptr>ptr1)
                {
                    printf("Invalid email\n");
                    flag=1;
                    count++;
                    if(count>=5)
                    {
                        return;
                    }
                }
                if(flag==1)
                {
                    continue;
                }
                if(Newemail[0] == '@' || Newemail[0] == '.')
                {
                    printf("Invalid email\n");
                    flag=1;
                    count++;
                    if(count>=5)
                    {
                        return;
                    }
                }
                if(flag==1)
                {
                    continue;
                }
                int atcount=0;
                int dotcomcount=0;
                for(int i=0;i<strlen(Newemail);i++)
                {
                    if(Newemail[i]=='@')
                    {
                        atcount++;
                    }
                    if(Newemail[i]=='.')
                    {
                        dotcomcount++;
                    }
                }
                if(atcount>1 || dotcomcount>1)
                {
                    printf("Invalid email\n");
                    flag=1;
                    count++;
                    if(count>=5)
                    {
                        return;
                    }
                }
                if(flag==1)
                {
                    continue;
                }
                strcpy(addressBook->contacts[selectedContactIndex].email,Newemail);
                printf("Email updated successfully\n");
                usleep(800000);
                break;
        }
    }
   /*sleep(1);
    system("clear");
    printf("Loading...\n");
    sleep(1);
    system("clear");*/
    printf("\n-----------------------------------------\n");
    printf("Updated Contact details:\n");
    printf("-------------------------------------------\n");
    printf("Name : %s\n", addressBook->contacts[selectedContactIndex].name);
    printf("Phone: %s\n", addressBook->contacts[selectedContactIndex].phone);
    printf("Email: %s\n", addressBook->contacts[selectedContactIndex].email);

    printf("\nPress 1 to continue ");
    int num;
    scanf("%d",&num);
    if(num==1)
    {
        /*system("clear"); 
        printf("Loading");
        fflush(stdout); 
        for (int i = 0; i < 3; i++) {
            usleep(800000); 
            printf(".");
            fflush(stdout); 
        }
        usleep(800000); 
        system("clear"); 
        usleep(500000); */
        return;
    }return;
  }
}
void deleteContact(AddressBook *addressBook)
{
    selectedContactIndex = -1;
    searchContact(addressBook);
    if (selectedContactIndex == -1) {
        printf("No contact selected for deletion.\n");
        return;
    }
    for(int i=selectedContactIndex;i<addressBook->contactCount-1;i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    addressBook->contactCount--;
    printf("Deleting");
        fflush(stdout); 
        for (int i = 0; i < 3; i++) {
            usleep(600000); 
            printf(".");
            fflush(stdout); 
        }
        usleep(800000);
    printf("\n");

    printf("Contact deleted successfully\n");
    usleep(800000);
    return;
}
void saveContactsToFile(AddressBook *addressBook)
{
    /* Define the logic to save the contacts to a file */
    FILE*fptr;
    fptr=fopen("contacts.csv","w");
    fprintf(fptr,"%d\n",addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fptr, "%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

    }
    fclose(fptr);
    printf("Saving");
        fflush(stdout); 
        for (int i = 0; i < 3; i++) {
            usleep(600000); 
            printf(".");
            fflush(stdout); 
        }
        usleep(800000);
    printf("\n"); 
    
    
}
void loadContactsFromFile(AddressBook *addressBook)
{
    /* Define the logic to load the contacts from a file */
    FILE*fptr;
    fptr=fopen("contacts.csv","r");
    fscanf(fptr,"%d\n",&addressBook->contactCount);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fscanf(fptr, "%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fptr);
    return;
}

