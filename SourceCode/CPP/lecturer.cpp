#include "lecturer.h"

void lecturerMenu()
{
	system("cls");
	
	textcolor(Cyan);
	printf("\tMenu\n");
	textcolor(defaultColor);

	printf("1. Import scoreboard of a course (midterm, final, lab, bonus)\n");
	printf("2. Edit grade of a student\n");
	printf("3. View a score board\n");
	printf("4. Back\n");
}

void Lecturer(User a)
{
	while (1) {
		lecturerMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 4);
		switch (choice) {
		case 1: tmpPrint(); break;
		case 2: tmpPrint(); break;
		case 3: tmpPrint(); break;
		case 4: return;
		}
	}
}