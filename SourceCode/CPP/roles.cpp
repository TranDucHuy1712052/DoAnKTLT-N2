#include "roles.h"
#include "password.h"
#include "menu.h"

//Lấy loại để show info
char *getType(User a)
{
	char type[15];
	if (a.type == student) strcpy(type, "Student");
	else if (a.type == academicStaff) strcpy(type, "Academic Staff");
	else strcpy(type, "Lecturer");
	char *tmp = new char[strlen(type) + 1];
	strcpy(tmp, type);
	return tmp;
}

void rolesMenu(User a)
{
	system("cls");
	char *type = getType(a);

	textcolor(Pink);
	printf("\t%s - %s\n", a.fullname, type);
	textcolor(defaultColor);

	printf("1. Show menu\n");
	printf("2. View info\n");
	printf("3. Change password\n");
	printf("4. Logout\n");
	delete type;
}

void showInfo(User a)
{
	system("cls");

	textcolor(Red);
	printf("\tThong tin cua ban:\n");
	textcolor(defaultColor);

	printf("1. Id: %s\n", a.username);
	printf("2. Ho va ten: %s\n", a.fullname);
	printf("3. Email: %s\n", a.email);
	printf("4. So dien thoai: %s\n", a.mobilephone);

	char *type = getType(a);
	printf("5. Vai tro: %s\n", type);

	delete type;

	if (strcmp(a.Class, "0")) printf("6. Lop: %s\n", a.Class);
	printf("Nhan phim bat ky de quay lai.\n");
	_getch();
}

void roles(User a)
{
	while (1) {
		rolesMenu(a);

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 4);

		switch (choice) {
		case 1: menu(a); break;
		case 2: showInfo(a); break;
		case 3: Password(a); break;
		case 4: return;
		}	
	}
}