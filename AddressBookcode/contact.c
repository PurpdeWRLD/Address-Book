#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"

//all in function prototypes
int validate_number(char number[11], AddressBook *addressBook);
int validate_email(char mail[50], AddressBook *addressBook);
int search_name(char name[50], AddressBook *addressBook);
int search_number(char number[11], AddressBook *addressBook);
int search_email(char email[50], AddressBook *addressBook);
int edit_search_name(char name[50], AddressBook *addressBook);
int edit_search_number(char number[11], AddressBook *addressBook);
int edit_search_email(char email[50], AddressBook *addressBook);
int delete_search_name(char name[50], AddressBook *addressBook);
int delete_search_number(char number[11], AddressBook *addressBook);
int delete_search_email(char email[50], AddressBook *addressBook);

void listContacts(AddressBook *addressBook) 
{
    int i, j;
    for(i = 0; i < addressBook -> contactCount - 1; i++)
    {
        for(j = 0; j < addressBook -> contactCount - i - 1; j++)
        {
            if(strcmp(addressBook -> contacts[j].name, addressBook -> contacts[j + 1].name) > 0)
            {
                Contact temp;
                temp = addressBook -> contacts[j];
                addressBook -> contacts[j] = addressBook -> contacts[j + 1];
                addressBook -> contacts[j + 1] = temp;
            }
        }
    }
    /* Define the logic for print the contacts */
    printf("-----------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\nContact List:\n");
    for (int i = 0; i < addressBook -> contactCount; i++)
    {
        printf("%d. Name: %-20s | Phone Number: %-20s | Email: %-20s|\n", i + 1, addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email); 
    }
    printf("-----------------------------------------------------------------------------------------------------------------------------------");
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */

    // Read the name from the user
    printf("Enter the name of the contact: ");
    scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name); //No validations for name, so saving in struture

    char number[20];
    // Read the contact
    do
    {
        printf("Enter the contact number: ");
        scanf(" %s", number);
    } while (validate_number(number, addressBook));//Function call
    strcpy(addressBook -> contacts[addressBook -> contactCount].phone, number);//Saving in structure
    // - Check whether the count is 10 or not
    // - Check all 10 characters are digits or not.
    // - Check the given number is already exist or not
    char mail[50];
    do
    {
        printf("Enter the contact email: ");//Read Email
        scanf(" %[^\n]", mail);
    } while (validate_email(mail, addressBook));//Function Call
    //Saving in structure
    strcpy(addressBook -> contacts[addressBook -> contactCount++].email, mail);
    
    // Read the email ID
    // - Check whether the character array contains lowercase, digits and special characters or not
    // - Check whether char - @ and .com is present or not
    // Increment the contact count.
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice;
    do
    {
        printf("Do you need to search by: \n");//Searching by Name, Number, Email, Phone number
        printf("1. Name \n");
        printf("2. Number \n");
        printf("3. Email \n");
        printf("4. Back \n");
        char name[50], email[50], number[11];
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
            do
            {
                printf("Enter the name of the contact: ");//Read Name
                scanf(" %[^\n]", name);
            } while (search_name(name, addressBook));//Function Call
            
            break;
            case 2:
            do
            {
                printf("Enter the contact number: ");//Read Number
                scanf(" %10s", number);
            }while(search_number(number, addressBook)); //Function Call
            break;
            case 3:
            do
            {
                printf("Enter the contact email: ");//Read Email
                scanf(" %[^\n]", email);
            } while (search_email(email, addressBook));//Function Call
            break;
            case 4:
            printf("Exit!");//Exiting to main menu
            break;
            default:
            printf("Invalid choice");
        }
    }while(choice != 4);
}

void editContact(AddressBook *addressBook)
{
    /* Define the logic for Editcontact */
    int choice;
    do
    {
        printf("Do you need to search by: \n");//Choose whether to search by name , Number , email id for editing.
        printf("1. Name \n");
        printf("2. Number \n");
        printf("3. Email \n");
        printf("4. Back \n");
        scanf("%d", &choice);
        char name[50], number[11], email[50];
        switch (choice)
        {
            case 1:
            do
            {
                printf("Enter the name of the contact: ");
                scanf(" %[^\n]", name);//Read name from user
            }while(edit_search_name(name, addressBook));
            break;
            case 2:
            do
            {
                printf("Enter the number of the contact: ");
                scanf(" %[^\n]", number);//Read Number from the user
            }while(edit_search_number(number, addressBook));
            break;
            case 3:
            do
            {
                printf("Enter the email of the contact: ");
                scanf(" %[^\n]", email);//Read email from the user
            }while(edit_search_email(email, addressBook));
            break;
            case 4:
            printf("Back");//Return to previous menu
            break;
            default:
            printf("Invalid choice");
        }
    }while(choice != 4);
}

void deleteContact(AddressBook *addressBook)
{
    /* Define the logic for deletecontact */
    int choice;
    do
    {
        printf("Do you need to Delete by: \n");//Need to search by name , number, email to delete the contact
        printf("1. Name \n");
        printf("2. Number \n");
        printf("3. Email \n");
        printf("4. Back \n");
        scanf("%d", &choice);
        char name[50], number[11], email[50];
        switch (choice)
        {
            case 1:
            do
            {
                printf("Enter the name of the contact: ");//Read name from user
                scanf(" %[^\n]", name);
            }while(delete_search_name(name, addressBook));//Function Call
            break;
            case 2:
            do
            {
                printf("Enter the number of the contact: ");
                scanf(" %[^\n]", number);//Read number from the user
            }while(delete_search_number(number, addressBook));//Function call
            break;
            case 3:
            do
            {
                printf("Enter the email of the contact: ");//Read email from user
                scanf(" %[^\n]", email);
            }while(delete_search_email(email, addressBook));//Funtion call
            break;
            case 4:
            printf("Back");//Returning to previous menu
            break;
            default:
            printf("Invalid choice");
        }
    }while(choice != 4);
}

//validation function definition
int validate_number(char number[], AddressBook *addressBook)
{
    int i;
    //Checking the length
    if(strlen(number) == 10)
    {
        //Checking all characters are digits by iterating every digit
        for(i = 0; number[i] != '\0'; i++)
        {
            if(number[i] >= '0' && number[i] <= '9')
            {
                continue;
            }
            else
            {
                printf("Invalid number. Please enter a 10 digit number.\n");
                return 1;
            }    
        }
        //check for duplicate contact
        for(i = 0; i < addressBook -> contactCount; i++)
        {
            if(strcmp(addressBook -> contacts[i].phone, number) == 0)
            {
                printf("Number already exists in the contact list.\n");
                return 1;
            }
        }     
        return 0;
    }
    else
    {
        printf("Enter 10 digits\n");
        return 1;
    }
} 

int validate_email(char mail[50], AddressBook *addressBook)
{
    int i, flag = 0, at_count = 0;
    //Checking whether alphabets are in lower case and no space are present and 1 @ is present and atleast 1 alphabet is present
    for(i = 0; mail[i] != '\0'; i++)
    {
        if(islower(mail[i]))
        {
            flag = 1;
        }
        else if((mail[i] >= 48 && mail[i] <= 57) || (mail[i] == '.')) 
        {
            continue;
        }
        else if(mail[i] == '@')
        {
            at_count++;
            if (at_count > 1)
            {
                printf("Invalid email address.\n");
                return 1;
            }
            if(!isalnum(mail[i + 1]))
            {
                printf("Invalid email address.\n");
                return 1;
            }
        }
        else
        {
            printf("Invalid email address.\n");
            return 1;
        }
    }
    if(!flag || at_count != 1 ||strstr(mail, ".com") == NULL)//Checking if every validation is present
    {
        printf("Invalid email address.\n");
        return 1;
    }
    if(strcmp(".com", strstr(mail, ".com")) != 0)
    {
        printf("Invalid email address.\n");
        return 1;
    }
    //Checking for duplicates
    for(i = 0; i < addressBook -> contactCount; i++)
        {
            if(strcmp(addressBook -> contacts[i].email, mail) == 0)
            {
                printf("Email already exists in the contact list.\n");
                return 1;
            }
        }
    return 0;    
}

int search_name(char name[50], AddressBook *addressBook)
{
    int i, flag = 0;
    for(i = 0; i < addressBook -> contactCount ; i++)//Iterate the structure
    {
        if(strcmp(addressBook -> contacts[i].name, name) == 0)//If matches display the contact details
        {
            printf("Contact Found");
            printf("Name: %s, Phone no: %s, Email: %s \n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
            flag = 1;
        }
    }
    if(flag)
    {
        return 0;
    }
    else
    {
        printf("Contact not found.\n");
        return 1;
    }
    //If not matched
}

int search_number(char number[11], AddressBook *addressBook)
{
    int i;
    for(i = 0; i < addressBook -> contactCount ; i++)//Iterate the structure
    {
        if(strcmp(addressBook -> contacts[i].phone, number) == 0)//If present display the contact details
        {
            printf("Contact Found");
            printf("Name: %s, Phone no: %s, Email: %s \n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
            return 0;
        }
    }
    //If not present
    printf("Contact Not found\n");
    return 1;
}

int search_email(char email[50],  AddressBook *addressBook)
{
    int i;
    for(i = 0; i < addressBook -> contactCount ; i++)//Iterate through structure
    {
        if(strcmp(addressBook -> contacts[i].email, email) == 0)//If present display the contact details
        {
            printf("Contact Found");
            printf("Name: %s, Phone no: %s, Email: %s \n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
            return 0;
        }
    }
    //If not present
    printf("Contact not found\n");
    return 1;
}
 
int edit_search_name(char name[50], AddressBook *addressBook) {
    int i, count = 0;
    int index_arr[50];
    int index_select;

    for (i = 0; i < addressBook->contactCount; i++) //Iterate through structure
    {
        if (strcmp(addressBook->contacts[i].name, name) == 0) //If matches display the contact details even the duplicates
        {
            index_arr[count] = i;
            count++;
            printf("S.no %d.  Name: %s , Phone: %s, Email: %s\n", count, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
    }

    if (count == 0)//If no matches 
    {
        printf("No contacts found with the name: %s\n", name);
        return 1;
    }
    //To select the particular contact by choosing the index
    printf("Select the contact number to edit (1 to %d): ", count);
    scanf("%d", &index_select);

    if (index_select < 1 || index_select > count) //If user input is out of bounds
    {
        printf("Invalid selection.\n");
        return 1;
    }

    int index = index_arr[index_select - 1];//To access the correct index in the array
    int choice;
    char new_number[11], new_email[50];

    do 
    {
        printf("1. Edit name\n");// To edit the name, phone no, email;
        printf("2. Edit phone number\n");
        printf("3. Edit email\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new name: ");
                scanf(" %s", addressBook -> contacts[index].name);//Rewriting the name
                break;
                
            case 2:
                do {
                    printf("Enter new phone number: ");
                    scanf(" %s", new_number);
                } while (validate_number(new_number, addressBook));//Validating the new number
                strcpy(addressBook -> contacts[index].phone, new_number);//Rewriting the new number
                break;

            case 3:
                do {
                    printf("Enter new email: ");
                    scanf(" %s", new_email);
                } while (validate_email(new_email, addressBook));//validating the new email
                strcpy(addressBook -> contacts[index].email, new_email);//Rewriting the new email
                break;

            case 4:
                printf("Exiting .\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

int edit_search_number(char number[11], AddressBook *addressBook)
{
    int i;
    for(i = 0; i < addressBook -> contactCount ; i++)//Iterating 
    {
        if(strcmp(addressBook -> contacts[i].phone, number) == 0)
        {
            printf("Contact Found");
            printf("Name: %s, Phone no: %s, Email: %s \n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
            int choice;
            char new_number[11], new_email[50];
            do
            {
                printf("1. Need the edit name? :\n");
                printf("2. Need the edit phone number? :\n");
                printf("3. Need the edit email? :\n");
                printf("4. Exit\n");
                scanf("%d", &choice);
                switch(choice)
                {
                    case 1:
                    printf("Enter new name: ");
                    scanf(" %s", addressBook -> contacts[i].name);
                    break;
                    case 2:
                    do
                    {
                        printf("Enter new phone number: ");
                        scanf(" %s", new_number);
                    } while (validate_number(new_number, addressBook));
                    strcpy(addressBook -> contacts[i].phone, new_number);
                    break;
                    case 3:
                    do
                    {
                        printf("Enter new email: ");
                        scanf(" %s", new_email);
                    } while(validate_email(new_email, addressBook));
                    strcpy(addressBook -> contacts[i].email, new_email);
                    break;
                    case 4:
                    printf("Exiting\n");
                    return 0;
                    break;
                    default:
                    printf("Invalid choice\n");
                }
            } while (choice != 4);
        }
    }
    printf("No contact Found\n");
    return 1;
}

int edit_search_email(char email[50], AddressBook *addressBook)
{
    int i;
    for(i = 0; i < addressBook -> contactCount ; i++)
    {
        if(strcmp(addressBook -> contacts[i].email, email) == 0)
        {
            printf("Contact Found");
            printf("Name: %s, Phone no: %s, Email: %s \n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
            int choice;
            char new_number[11], new_email[50];
            do
            {
                printf("1. Need the edit name? :\n");
                printf("2. Need the edit phone number? :\n");
                printf("3. Need the edit email? :\n");
                printf("4. Exit\n");
                scanf("%d", &choice);
                switch(choice)
                {
                    case 1:
                    printf("Enter new name: ");
                    scanf(" %s", addressBook -> contacts[i].name);
                    break;
                    case 2:
                    do
                    {
                        printf("Enter new phone number: ");
                        scanf(" %s", new_number);
                    }while(validate_number(new_number, addressBook));
                    strcpy(addressBook -> contacts[i].phone, new_number);
                    break;
                    case 3:
                    do
                    {
                        printf("Enter new email: ");
                        scanf("%s", new_email);
                    }while(validate_email(new_email, addressBook));
                    strcpy(addressBook -> contacts[i].email, new_email);
                    break;
                    case 4:
                    printf("Exiting\n");
                    return 0;
                    break;
                    default:
                    printf("Invalid choice\n");
                }
            } while (choice != 4);
        }
    }
    printf("No Contact Founf\n");
    return 1;
}

int delete_search_name(char name[50], AddressBook *addressBook)
{
    int i, j, count = 0;
    int index_arr[50];
    int index_select;

    for (i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, name) == 0) {
            index_arr[count] = i;
            count++;
            printf("S.no %d.  Name: %s , Phone: %s, Email: %s\n", count, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
    }

    if (count == 0) {
        printf("No contacts found with the name: %s\n", name);
        return 1;
    }

    printf("Select the contact number to edit (1 to %d): ", count);
    scanf("%d", &index_select);
    if (index_select < 1 || index_select > count) {
        printf("Invalid selection.\n");
        return 1;
    }

    int index = index_arr[index_select - 1];
    char response;
    printf("Do you want to delete the contact? (y/n): ");
    scanf(" %c", &response);
    if(response == 'y'|| response == 'Y')
    {
        for(j = index; j < addressBook -> contactCount - 1; j++)
        {
            addressBook-> contacts[j] = addressBook -> contacts[j + 1];
        }
        addressBook -> contactCount--;
        printf("Contact Deleted Successfully\n");
        return 0;
    }
    else
    {
        printf("Contact not deleted\n");
        return 1;
    }
}

int delete_search_number(char number[11], AddressBook *addressBook)
{
    int i, j;
    for(i = 0; i < addressBook -> contactCount; i++)
    {
        if(strcmp(addressBook -> contacts[i].phone, number) == 0)
        {
            printf("Contact Found");
            printf("Name: %s, Phone no: %s, Email: %s \n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
            printf("Do you want to delete this contact? (y/n)\n");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y')
            {
                for(j = i; j < addressBook -> contactCount - 1; j++)
                {
                    addressBook -> contacts[j] = addressBook -> contacts[j + 1];
                }
                addressBook -> contactCount--;
                printf("Contact deleted successfully.\n");
                return 0;
            }
            else
            {
                printf("Contact not deleted.\n");
                return 1;
            }
        }
    }
    printf("Contact not Found\n");
    return 1;
}

int delete_search_email(char email[50], AddressBook *addressBook)
{
    int i, j;
    for(i = 0; i < addressBook -> contactCount ; i++)
    {
        if(strcmp(addressBook -> contacts[i].email, email) == 0)
        {
            printf("Contact Found");
            printf("Name: %s, Phone no: %s, Email: %s \n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
            printf("Do you want to delete this email? (y/n)\n");
            char choice;
            scanf(" %c", &choice);
            if(choice == 'y' || choice == 'Y')
            {
                for(j = i; j < addressBook -> contactCount - 1; j++)
                {
                    addressBook -> contacts[j] = addressBook -> contacts[j + 1];
                }
                addressBook -> contactCount--;
                printf("Contact deleted successfully.\n");
                return 0;
            }
            else{
                printf("Conatct Not deleted.\n");
                return 1;
            }
        }
    }
    printf("Contact Not Found\n");
    return 1;
}
