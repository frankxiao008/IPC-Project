
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include"contactHelpers.h"
#include"contacts.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name *nam)
{
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]s", nam->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");

	if (yes() == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]s", nam->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]s", nam->lastName);
}
// getAddress:
void getAddress(struct Address *addr)
{
	printf("Please enter the contact's street number: ");

	addr->streetNumber = getInt();
	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s", addr->street);

	printf("Do you want to enter an apartment number? (y or n): ");

	if (yes() == 1) {
		printf("Please enter the contact's apartment number: ");
		scanf(" %u", &addr->apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]s", addr->postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]s", addr->city);

}
// getNumbers:
void getNumbers(struct Numbers *numb)
{

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numb->cell);


	printf("Do you want to enter a home phone number? (y or n): ");

	if (yes() == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numb->home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numb->business);
	}

}
// getContact:
void getContact(struct Contact *cont)
{
	printf("\n");
	getName(&cont->name);
	getAddress(&cont->address);
	getNumbers(&cont->numbers);

}
