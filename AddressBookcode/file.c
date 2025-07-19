#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *file = fopen("contacts.csv", "w");
    int i;
    if(file == NULL)
    {
        perror("Error: \n");
        return;
    }
    fprintf(file, "#%d\n", addressBook -> contactCount);
    for(i = 0; i < addressBook -> contactCount; i++)
    {
        fprintf(file, "%s,%s,%s\n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email); 
    }
    fclose(file);
}

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *file = fopen("contacts.csv", "r");
    int i;
    if(file == NULL)
    {
        perror("Error: \n");
        return;
    }
    fscanf(file, "#%d\n", &addressBook -> contactCount);
    for(i = 0; i < addressBook -> contactCount; i++)
    {
        fscanf(file, "%[^,],%[^,],%[^\n]\n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email); 
    }
    fclose(file);
}