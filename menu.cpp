#include "menu.h"

void menu(User a)
{
	switch (a.type) {
	case student: Student(a); break;
	case academicStaff: AcademicStaff(a); break;
	case lecturer: Lecturer(a);
	}
}

//H�m x�m
void tmpPrint()
{
	system("cls");
	printf("Unavailable!\n");
	_getch();
}