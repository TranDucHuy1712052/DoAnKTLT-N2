#include "begin.h"

void beginMenu()
{
	system("cls");

	textcolor(Green);
	printf("\tStudent Management System\n");
	textcolor(defaultColor);

	printf("1. Login\n");
	printf("2. Exit\n");
}

bool begin()
{
	beginMenu();
	coordinates begin = { 0,1 };
	int choice = selectionMove(begin, 1, 2, 1);
	switch (choice) {
	case 1: return TRUE; break;
	case 2: return FALSE;
	}
	while (getchar() != '\n');
}