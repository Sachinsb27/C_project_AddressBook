#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

void initialize(AddressBook *addressBook)
{
	addressBook->contactCount = 0;
	// populateAddressBook(addressBook);// comment this after loading  files
		loadContactsFromFile(addressBook);
	// Load contacts from file during initialization (After files)
	//
}

int name_validate(char *name)
{

	// STEP1: Fetch one by one character till null character
	int i = 0;
	// printf("name -> %s\n",name);
	while (name[i] != '\0')
	{

		if (name[i] != ' ')
		{
			if (!(isalpha(name[i])))
			{
				return 1;
				// STEP2: Check the character is alpahebet or not
				// Yes-> Move to next character, NO -> Stop the process
			}
		}
		i++;
	}
	return 0;
}
int number_validate(char *number)
{

	int i = 0;
	while (number[i] != '\0')
	{
		if (!(isdigit(number[i])))
		{
			return 1;
		}
		i++;
	}
	return 0;
}
int unique_number(char *number, AddressBook *addressBook)
{
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		if (strcmp(number, addressBook->contacts[i].phone) == 0)
		{
			return 1;
		}
	}
}

// int mail_validate(char *mail)
// {
// 	char str[100] = "@example.com";
// 	if (!(strstr(mail, str)))
// 	{
// 		return 1;
// 	}
// 	else
// 	{
// 		return 0;
// 	}
// }


int mail_validate(char *mail) {
    // Find the position of '@' in the email
    char *at_sign = strchr(mail, '@');

    // Check if '@' exists and is not at the start or end
    if (at_sign == NULL || at_sign == mail || *(at_sign + 1) == '\0') {
        return 1; // Invalid email
    }

    // Check if there is a '.' in the domain after '@'
    char *domain = at_sign + 1; // Domain starts after '@'
    if (strchr(domain, '.') == NULL) {
        return 0; // No '.' in the domain
    }

    return 0; // Valid email
}
int unique_mail(char *mail, AddressBook *addressBook)
{
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		if (strcmp(mail, addressBook->contacts[i].email) == 0)
		{
			return 1;
		}
	}
}

int searchname(char *name_search, AddressBook *addressBook)
{
	int flag_name = 0;
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		if (strcmp(name_search, addressBook->contacts[i].name) == 0 && (name_validate(name_search) == 0))
		{
			flag_name = 1;
			printf("Contact found\n");
			printf("name -> %s ", addressBook->contacts[i].name);
			printf("number -> %s ", addressBook->contacts[i].phone);
			printf("email -> %s ", addressBook->contacts[i].email);
			printf("\n");
			break;
		}
	}
	if (flag_name == 0)
	{
		printf("Contact Not found");
	}
}
int searchnumber(char *number_search, AddressBook *addressBook)
{
	int flag_number = 0;
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		if (strcmp(number_search, addressBook->contacts[i].phone) == 0 && (number_validate(number_search) == 0))
		{
			flag_number = 1;
			printf("Contact found\n");
			printf("name -> %s ", addressBook->contacts[i].name);
			printf("number -> %s ", addressBook->contacts[i].phone);
			printf("email -> %s ", addressBook->contacts[i].email);
			printf("\n");
			break;
		}
	}
	if (flag_number == 0)
	{
		printf("Contact Not found");
	}
}
int searchmail(char *mail_search, AddressBook *addressBook)
{
	int flag_mail;
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		if (strcmp(mail_search, addressBook->contacts[i].email) == 0 && (mail_validate(mail_search)==0))
		{
			flag_mail = 1;
			printf("Contact found\n");
			printf("name -> %s ", addressBook->contacts[i].name);
			printf("number -> %s ", addressBook->contacts[i].phone);
			printf("email -> %s ", addressBook->contacts[i].email);
			printf("\n");
			break;
		}
	}
	if (flag_mail == 0)
	{
		printf("Contact Not found");
	}
}

int Editname(char *name_edit, AddressBook *addressBook)
{
	int flag_edit_name = 0;
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		if (strcmp(name_edit, addressBook->contacts[i].name) == 0 && (name_validate(name_edit) == 0))
		{
			printf("Enter the name that u want:\n");
			scanf(" %[^\n]", name_edit);
			// i = addressBook->contactCount;
			strcpy(addressBook->contacts[i].name, name_edit);
			// addressBook->contactCount++;
			flag_edit_name = 1;
			printf("Contact found\n");
			printf("name -> %s ", addressBook->contacts[i].name);
			printf("number -> %s ", addressBook->contacts[i].phone);
			printf("email -> %s ", addressBook->contacts[i].email);
			printf("\n");
			break;
		}
	}
	if (flag_edit_name == 0)
	{

		printf("Contact Not found");
	}
}
int Editnumber(char *number_edit, AddressBook *addressBook)
{
	int flag_edit_number = 0;
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		if (strcmp(number_edit, addressBook->contacts[i].phone) == 0 && (number_validate(number_edit) == 0))
		{
			printf("Enter the number that u want:\n");
			scanf(" %[^\n]", number_edit);
			// i = addressBook->contactCount;
			strcpy(addressBook->contacts[i].phone, number_edit);
			//	addressBook->contactCount++;
			flag_edit_number = 1;
			printf("Contact found\n");
			printf("name -> %s ", addressBook->contacts[i].name);
			printf("number -> %s ", addressBook->contacts[i].phone);
			printf("email -> %s ", addressBook->contacts[i].email);
			printf("\n");
			break;
		}
	}
	if (flag_edit_number == 0)
	{

		printf("Contact Not found");
	}
}
int Editmail(char *mail_edit, AddressBook *addressBook)
{
	int flag_edit_mail = 1;
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		if (strcmp(mail_edit, addressBook->contacts[i].email) == 0 && (mail_validate(mail_edit) == 0))
		{
			printf("Enter the mail that u want:\n");
			scanf(" %[^\n]", mail_edit);
			// i = addressBook->contactCount;
			strcpy(addressBook->contacts[i].email, mail_edit);
			// addressBook->contactCount++;
			flag_edit_mail = 1;
			printf("Contact found\n");
			printf("name -> %s ", addressBook->contacts[i].name);
			printf("number -> %s ", addressBook->contacts[i].phone);
			printf("email -> %s ", addressBook->contacts[i].email);
			printf("\n");
			break;
		}
	}
	if (flag_edit_mail == 0)
	{

		printf("Contact Not found");
	}
}

int deletename(char *name_delete, AddressBook *addressBook)
{
	int found = 0;

	for (int i = 0; i < addressBook->contactCount; i++)
	{
		// Check if the current contact's name matches the input
		if (strcmp(name_delete, addressBook->contacts[i].name) == 0 && (name_validate(name_delete) == 0))
		{
			found = 1;
		}

		// Shift contacts after the deleted one
		if (found && i < addressBook->contactCount - 1)
		{
			strcpy(addressBook->contacts[i].name, addressBook->contacts[i + 1].name);
			strcpy(addressBook->contacts[i].phone, addressBook->contacts[i + 1].phone);
			strcpy(addressBook->contacts[i].email, addressBook->contacts[i + 1].email);
		}
	}

	if (found)
	{
		addressBook->contactCount--;
		// Optional: Clear the last contact's data after the shift
		strcpy(addressBook->contacts[addressBook->contactCount].name, "");
		strcpy(addressBook->contacts[addressBook->contactCount].phone, "");
		strcpy(addressBook->contacts[addressBook->contactCount].email, "");

		printf("Contact deleted successfully by name.\n");
		return 1;
	}

	printf("Name not found.\n");
	return 0;
}

int deletenumber(char *number_delete, AddressBook *addressBook)
{
	int found = 0;

	for (int i = 0; i < addressBook->contactCount; i++)
	{
		// Check if the current contact's phone matches the input
		if (strcmp(number_delete, addressBook->contacts[i].phone) == 0 && (number_validate(number_delete) == 0))
		{
			found = 1;
		}

		// Shift contacts after the deleted one
		if (found && i < addressBook->contactCount - 1)
		{
			strcpy(addressBook->contacts[i].name, addressBook->contacts[i + 1].name);
			strcpy(addressBook->contacts[i].phone, addressBook->contacts[i + 1].phone);
			strcpy(addressBook->contacts[i].email, addressBook->contacts[i + 1].email);
		}
	}

	if (found)
	{
		addressBook->contactCount--;
		// Optional: Clear the last contact's data after the shift
		strcpy(addressBook->contacts[addressBook->contactCount].name, "");
		strcpy(addressBook->contacts[addressBook->contactCount].phone, "");
		strcpy(addressBook->contacts[addressBook->contactCount].email, "");

		printf("Contact deleted successfully by phone number.\n");
		return 1;
	}

	printf("Phone number not found.\n");
	return 0;
}

int deletemail(char *mail_delete, AddressBook *addressBook)
{
	int found = 0;

	for (int i = 0; i < addressBook->contactCount; i++)
	{
		// Check if the current contact's email matches the input
		if (strcmp(mail_delete, addressBook->contacts[i].email) == 0 && (mail_validate(mail_delete) == 0))
		{
			found = 1;
		}

		// Shift contacts after the deleted one
		if (found && i < addressBook->contactCount - 1)
		{
			strcpy(addressBook->contacts[i].name, addressBook->contacts[i + 1].name);
			strcpy(addressBook->contacts[i].phone, addressBook->contacts[i + 1].phone);
			strcpy(addressBook->contacts[i].email, addressBook->contacts[i + 1].email);
		}
	}

	if (found)
	{
		addressBook->contactCount--;
		// Optional: Clear the last contact's data after the shift
		strcpy(addressBook->contacts[addressBook->contactCount].name, "");
		strcpy(addressBook->contacts[addressBook->contactCount].phone, "");
		strcpy(addressBook->contacts[addressBook->contactCount].email, "");

		printf("Contact deleted successfully by email.\n");
		return 1;
	}

	printf("Email not found.\n");
	return 0;
}

void createContact(AddressBook *addressBook)
{
	// addressBook->contacts[1].name
	char name[20];

	// STEP1: Read a name from user
	printf("Enter the name: ");
	//__fpurge(STDIN);
	// getchar();
	scanf(" %[^\n]", name);

	// STEP2: Validate the name -> Alphabets
	while (name_validate(name) == 1)
	{
		printf("INFO: Name validation not done, Please enter valid name...\n");
		printf("Enter the name: ");
		scanf(" %[^\n]", name);
		// True -> Goto STEP3, False -> print error, Goto STEP1
	}
	// STEP3: Read a mobile number from user
	char number[100];
	printf("Enter the number:");
	scanf(" %[^\n]", number);

// STEP4: Validate the mobile number -> Digit & 10 Digits & unique
label1:
	if (strlen(number) == 10)
	{
		while (number_validate(number) == 1)
		{
			printf("INFO: Number validation not done, Please enter valid number...\n");
			printf("Enter the number: ");
			scanf(" %[^\n]", number);
			// True -> Goto STEP3, False -> print error, Goto STEP1
		}
		while (unique_number(number, addressBook) == 1)
		{
			printf("INFO: Number is already present, Please enter valid number...\n");
			printf("Enter the number: ");
			scanf(" %[^\n]", number);
		}
	}
	else
	{
		printf("INFO:Please enter valid number...\n");
		printf("Enter the number: ");
		scanf(" %[^\n]", number);
		goto label1;
	}

	// True -> Goto STEP5, False -> print error, Goto STEP3
	// STEP5: Read a email_id from user
	char mail[100];
	printf("Enter the mail:");
label2:
	scanf(" %[^\n]", mail);
	int i = 0;
	while (mail[i] != '@')
	{
		if (isupper(mail[i]))
		{
			printf("INFO:Please enter valid mail...\n");
			printf("Enter the mail: ");
			goto label2;
		}
		// printf("%d",i);
		i++;
	}
	while (mail_validate(mail) == 1)
	{
		printf("INFO: mail validation not done, Please enter valid mail...\n");
		printf("Enter the mail: ");
		scanf(" %[^\n]", mail);
	}
	while (unique_mail(mail, addressBook) == 1)
	{
		printf("INFO: mail is already present, Please enter valid mail...\n");
		printf("Enter the mail: ");
		scanf(" %[^\n]", mail);
	}
	

	// STEP6: Validate the email_ID -> @gmail.com & unique
	// True -> Goto STEP7, False -> print error, Goto STEP5

	// STEP7: store into structure[contact_count]
	int index = addressBook->contactCount;
	strcpy(addressBook->contacts[index].name, name);
	strcpy(addressBook->contacts[index].phone, number);
	strcpy(addressBook->contacts[index].email, mail);
	addressBook->contactCount++;
    saveContactsToFile(addressBook);
	/* Define the logic to create a Contacts */
}

/* Define the logic for search */
// STEP1: Print the menu Based on what searching
// STEP2: Choose the menu
void searchContact(AddressBook *addressBook)
{
	int choice;
	char name_search[100];
	char number_search[100];
	char mail_search[100];
	do
	{
		printf("Address Book Menu:\n");
		printf("search contact:\n");
		printf("1.search name:\n");
		printf("2.search number:\n");
		printf("3.search mail:\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:

			printf("Enter the name you want to search:\n");
			scanf(" %[^\n]", name_search);
			searchname(name_search, addressBook);

			break;

		case 2:
			printf("Enter the number you want to search:\n");
			scanf(" %[^\n]", number_search);
			searchnumber(number_search, addressBook);
			break;

		case 3:
			printf("Enter the mail you want to search:\n");
			scanf(" %[^\n]", mail_search);
			searchmail(mail_search, addressBook);
			break;

		case 4:
			printf("Saving and Exiting...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}

	} while (choice != 4);
	saveContactsToFile(addressBook);
}
// 1 -> Name
// Read the name
// Search the extered name is present in the database or not
// Yes -> Print the details about that contact, NO -> Print error, Goto STEP1.

// 2 -> Mobile_no
// Read the mobile_no
// Search the extered mobile_no is present in the database or not
// Yes -> Print the details about that contact, NO -> Print error, Goto STEP1.

// 3 -> Email_id
// Read the mail_id
// Search the extered mail_id is present in the database or not
// Yes -> Print the details about that contact, NO -> Print error, Goto STEP1.

void editContact(AddressBook *addressBook)
{
	int choice;
	char name_edit[100];
	char number_edit[100];
	char mail_edit[100];
	do
	{
		printf("Address Book Menu:\n");
		printf("Edit contact:\n");
		printf("1.Edit name:\n");
		printf("2.Edit number:\n");
		printf("3.Edit mail:\n");
		printf("4.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the name you want to edit:\n");
			scanf(" %[^\n]", name_edit);
			Editname(name_edit, addressBook);
			break;

		case 2:
			printf("Enter the number you want to edit:\n");
			scanf(" %[^\n]", number_edit);
			Editnumber(number_edit, addressBook);
			break;

		case 3:
			printf("Enter the mail you want to edit:\n");
			scanf(" %[^\n]", mail_edit);
			Editmail(mail_edit, addressBook);
			break;

			/* Define the logic for Editcontact */
		case 4:
			printf("Saving and Exiting...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}

	} while (choice != 4);
	saveContactsToFile(addressBook);
}

void deleteContact(AddressBook *addressBook)

{
	int choice;
	char name_delete[100];
	char number_delete[100];
	char mail_delete[100];
	do
	{
		printf("Address Book Menu:\n");
		printf("Edit contact:\n");
		printf("1.Delete name:\n");
		printf("2.Delete number:\n");
		printf("3.Delete mail:\n");
		printf("Enter your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the name you want to delete:\n");
			scanf(" %[^\n]", name_delete);
			deletename(name_delete, addressBook);
			break;

		case 2:
			printf("Enter the number you want to edit:\n");
			scanf(" %[^\n]", number_delete);
			deletenumber(number_delete, addressBook);
			break;

		case 3:
			printf("Enter the mail you want to edit:\n");
			scanf(" %[^\n]", mail_delete);
			deletemail(mail_delete, addressBook);
			break;

			/* Define the logic for Editcontact */
		case 4:
			printf("Saving and Exiting...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
		}

	} while (choice != 4);

	saveContactsToFile(addressBook);

	// printf("Enter the name you want to delete: ");
	// for (int i = 0; i < addressBook->contactCount; i++)
	// {
	// }
	/* Define the logic for deletecontact */
}

void listContacts(AddressBook *addressBook)
{
	// Sort contacts based on the chosen criteria
	//printf("Name    	Phone no     	 Email id\n");
	printf("count -> %d\n",addressBook->contactCount);
	for (int i = 0; i < addressBook->contactCount; i++)
	{
		printf("Name :%s ", addressBook->contacts[i].name);
		printf("Phone No :%s ", addressBook->contacts[i].phone);
		printf("Email ID :%s ", addressBook->contacts[i].email);
		printf("\n");
	}
	// saveContactsToFile(addressBook);
}