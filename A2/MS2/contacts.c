/* -------------------------------------------
Name:Saihong Xiao
Student number:140777178
Email:sxiao15@myseneca.ca
Section:
Date:07/12/2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *nam)
{
	char j;
	printf("\nPlease enter the contact's first name: ");
	scanf("%30s", nam->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &j);
	if (j == 'y' || j == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", nam->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35s", nam->lastName);
}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *addr)
{
	char j;
	printf("Please enter the contact's street number: ");
	scanf(" %u", &addr->streetNumber);

	printf("Please enter the contact's street name: ");
	scanf(" %40s", addr->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &j);
	if (j == 'y' || j == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf(" %u", &addr->apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]s", addr->postalCode);

	printf("Please enter the contact's city: ");
	scanf("%40s", addr->city);

}



// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers *numb)
{
	char j;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &j);
	if (j == 'y' || j == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %20s", numb->cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &j);
	if (j == 'y' || j == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf(" %20s", numb->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &j);
	if (j == 'y' || j == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf(" %20s", numb->business);
	}

}


// Contact Numbers Input:


// Display Contact Summary Details

void display(struct Contact *cont)
{   
	int i;
	printf("\nContact Details\n");
	for (i = 0; i < 15; i++)
		printf("-");

	printf("\nName Details\n");
	printf("First name: %s\n", cont->name.firstName);
	printf("Middle initial(s): %s\n", cont->name.middleInitial);
	printf("Last name: %s\n", cont->name.lastName);

	printf("\nAddress Details\n");
	printf("Street number: %d\n", cont->address.streetNumber);
	printf("Street name: %s\n", cont->address.street);
	printf("Apartment: %d\n", cont->address.apartmentNumber);
	printf("Postal code: %s\n", cont->address.postalCode);
	printf("City: %s\n", cont->address.city);

	printf("\nPhone Numbers:\n");
	printf("Cell phone number: %s\n", cont->numbers.cell);
	printf("Home phone number: %s\n", cont->numbers.home);
	printf("Business phone number: %s\n", cont->numbers.business);
}
