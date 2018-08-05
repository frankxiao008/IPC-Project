/* -------------------------------------------
Name:Xiao Saihong
Student number:140777178
Email:sxiao15@myseneca.ca
Section:
Date:2018/07/26
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"

// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}


// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	char NL = 'x';
	int Value;
	while (NL != '\n') {
		scanf("%d%c", &Value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}

	}
	return Value;
}


// getIntInRange:
int getIntInRange(int a, int b)
{
	int num = getInt();
	while (num<a || num>b) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", a, b);
		num = getInt();
	}
	return num;
}


// yes:
int yes(void)
{
	char NL = 'x';
	char c;
	int i = 1, j;
	do {
		scanf(" %c%c", &c, &NL);
		if (NL == '\n')
		{
			switch (c) {
			case 'y':
			case 'Y':
				j = 1;
				i = 0;
				break;
			case 'n':
			case'N':
				j = 0;
				i = 0;
				break;
			}
		}
		else {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
	} while (i);
	return j;
}

// menu:
int menu(void)
{
	printf("Contact Management System\n"
		"-------------------------\n"
		"1. Display contacts\n"
		"2. Add a contact\n"
		"3. Update a contact\n"
		"4. Delete a contact\n"
		"5. Search contacts by cell phone number\n"
		"6. Sort contacts by cell phone number\n"
		"0. Exit\n"
		"\nSelect an option:> ");
	return getIntInRange(0, 6);

}


// ContactManagerSystem:
void ContactManagerSystem(void)
{
	struct Contact conta[MAXCONTACTS] = { { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
	{
		{ "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
	{
		{ "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
	{
		{ "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};

	int i,j = 0;
	int a = 0;
	do {

		if(j != 0)
			printf("\n");

		i = menu();
		switch (i) {
		case 1:
			printf("\n");
			displayContacts(conta, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(conta, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(conta, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(conta, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(conta, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(conta, MAXCONTACTS);
			pause();
			break;
		default:
			printf("\nExit the program? (Y)es/(N)o: ");
			a = yes();
			break;
	
		

		}
		j++;

	} while (a != 1);
	printf("\nContact Management System: terminated\n");
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	for (i = 0; i < size; i++) {
		if (strcmp(cellNum, contacts[i].numbers.cell) == 0)
			return i;
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
void displayContactFooter(int a)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", a);

}

// displayContact:
void displayContact(const struct Contact* anyone)
{
	printf(" %s ", anyone->name.firstName);
	if (strlen(anyone->name.middleInitial) > 0)
		printf("%s ", anyone->name.middleInitial);
	printf("%s\n", anyone->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", anyone->numbers.cell, anyone->numbers.home, anyone->numbers.business);
	printf("       %d %s, ", anyone->address.streetNumber, anyone->address.street);
	if (anyone->address.apartmentNumber > 0)
		printf("Apt# %d, ", anyone->address.apartmentNumber);
	printf("%s, %s\n", anyone->address.city, anyone->address.postalCode);


}

// displayContacts:
void displayContacts(const struct Contact someone[], int a)
{
	int i, j = 0;
	//	struct Contact *who = malloc(sizeof(struct Contact));

	displayContactHeader();

	for (i = 0; i < a; i++)
	{
		if (strlen(someone[i].numbers.cell) > 0) {
			displayContact(&someone[i]);
			j++;
		}
	}
	displayContactFooter(j);

}

// searchContacts:
void searchContacts(const struct Contact contact[], int b)
{
	char cellnum[11];
	int i;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellnum);
	i = findContactIndex(contact, MAXCONTACTS, cellnum);
	if (i >= 0) {
		printf("\n");
		displayContact(&contact[i]);
		printf("\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");

}



// addContact:
void addContact(struct Contact contact[], int c)
{
	int i;
	for (i = 0; i < c; i++) {

		if (strlen(contact[i].numbers.cell) == 0)
			break;
	}


	if (i == c)
	{
		printf("\n*** ERROR: The contact list is full! ***\n");
	}
	else {
		getContact(&contact[i]);
		printf("--- New contact added! ---\n");

	}
}


// updateContact:
void updateContact(struct Contact contact[], int d)
{
	char cellNumb[11];
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNumb);
	int i = findContactIndex(contact, d, cellNumb);
	if (i == -1) {
		printf("*** Contact NOT FOUND ***\n");

	}
	else {
		printf("\nContact found:\n");
		displayContact(&contact[i]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1) {
			char b = { '\0' };

			*contact[i].name.middleInitial = b;
			getName(&contact[i].name);
		}
		else {
			printf("\n");
		}
		clearKeyboard();
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			int c = 0;

			contact[i].address.apartmentNumber = c;
			getAddress(&contact[i].address);
		}
		else {
			printf("\n");
		}
		clearKeyboard();
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			char b = { '\0' };

			*contact[i].numbers.business = b;
			*contact[i].numbers.home = b;

			getNumbers(&contact[i].numbers);
		}
		else {
			printf("\n");
		}
		printf("--- Contact Updated! ---\n");
	}
}


// deleteContact:
void deleteContact(struct Contact contact[], int e)
{
	char cellNumb[11];
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNumb);
	int i = findContactIndex(contact, e, cellNumb);
	if (i == -1) {
		printf("\n*** Contact NOT FOUND ***\n");

	}
	else {
		printf("\nContact found:\n");
		displayContact(&contact[i]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		int j = yes();
		if (j == 1) {

			contact[i].numbers.cell[0] = '\0';
			contact[i].numbers.business[0] = '\0';
			contact[i].numbers.business[0] = '\0';
			contact[i].address.apartmentNumber = 0;
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
void sortContacts(struct Contact contact[], int f)
{
	int i, j;
	struct Contact a;
	for (i = 0; i < f - 1; i++) {
		for (j = i + 1; j < f; j++) {
			if (strcmp(contact[i].numbers.cell, contact[j].numbers.cell) > 0) {
				a = contact[i];
				contact[i] = contact[j];
				contact[j] = a;
			}
		}

	}
	printf("\n--- Contacts sorted! ---\n");

}

