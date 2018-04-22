#include "menu.h"

void menu(User a, UserList &list)
{
	switch (a.type) {
	case student: Student(a, list); break;
	case academicStaff: AcademicStaff(a, list); break;
	case lecturer: Lecturer(a, list);
	}
}

//H�m x�m
void tmpPrint()
{
	system("cls");
	printf("Unavailable!\n");
	_getch();
}