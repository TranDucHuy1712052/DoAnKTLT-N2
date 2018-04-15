#include "student.h"

void studentMenu()
{
	
	system("cls");

	textcolor(Cyan);
	printf("\tMenu\n");
	textcolor(defaultColor);

	printf("1. Check-in\n");
	printf("2. View check-in result\n");
	printf("3. View your score of a course\n");
	printf("4. View schedule\n");
	printf("5. Back\n");
}

void Student(User a)
{
	while (1) {
		studentMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 5, 1);
		switch (choice) {
		case 1: tmpPrint(); break;
		case 2: tmpPrint(); break;
		case 3: tmpPrint(); break;
		case 4: tmpPrint(); break;
		case 5: return;
		}
	}
}