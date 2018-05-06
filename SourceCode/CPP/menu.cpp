#include "menu.h"

void menu(User a, UserList &list, studentCourses &coursesList)
{
	switch (a.type) {
	case student: Student(a, list); break;
	case academicStaff: AcademicStaff(a, list, coursesList); break;
	case lecturer: Lecturer(a, list);
	}
}

//Hàm xàm
void tmpPrint()
{
	system("cls");
	printf("Unavailable!\n");
	_getch();
}