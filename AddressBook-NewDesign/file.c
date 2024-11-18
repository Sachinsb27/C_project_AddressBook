#include <stdio.h>
#include <string.h>
#include "contact.h"
#include"file.h"

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fptr = fopen("contact.csv", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    int i = 0;
    char str[100];
    fscanf(fptr, "#%d#\n", &addressBook->contactCount);

    
    printf("count       -> %d\n",addressBook->contactCount);
    for (int  i = 0 ; i < addressBook->contactCount ; i++)
    {
        fscanf(fptr,"%[^\n]\n",str);
        printf("str -> %s\n",str);
        char *ptr;  
        ptr = strtok(str,",");
        strcpy(addressBook->contacts[i].name,ptr);

        ptr = strtok(NULL,",");
        strcpy(addressBook->contacts[i].phone,ptr);

        ptr = strtok(NULL,",");
        strcpy(addressBook->contacts[i].email,ptr);

    }
    
    printf("%d contacts loaded successfully.\n", addressBook->contactCount);
    fclose(fptr);
}


void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contact.csv", "w");
    if (fptr == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fprintf(fptr,"#%d#\n",addressBook->contactCount);
    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(fptr, "%s,%s,%s\n", addressBook->contacts[i].name, 
                addressBook->contacts[i].phone, 
                addressBook->contacts[i].email);
    }
    
    fclose(fptr);
    printf("Contacts saved successfully.\n");
}  