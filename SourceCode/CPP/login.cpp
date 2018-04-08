#include "login.h"

void menuLogin()
{
	system("cls");

	textcolor(Yellow);
	printf("\tStudent Management System\n");
	textcolor(defaultColor);

	printf("Username:\n");
	printf("Password:\n");
}

//Tìm xem có user không, password đúng không
bool findUser(User &a, char id[], char password[])
{
	char tmp[100];
	FILE *f = fopen("users.csv", "r");
	fgets(tmp, 99, f);
	
	int got = 7;
	while (got == 7) {
		got = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^\n]\n", a.username, a.fullname, a.email, a.mobilephone, &a.type, a.password, a.Class);
		if (!strcmp(a.username, id) && !strcmp(a.password, password)) got = -2;
	}

	fclose(f);

	if (got == -2) return true;
	return false;
}

bool login(User &a)
{
	char id[20], password[50];
	
	menuLogin();

	gotoxy(10, 1);
	gets_s(id, 19);

	gotoxy(10, 2);
	scanf("%s", password);

	if (findUser(a, id, password)) {
		return true;
	}
	else {
		printf("Ten dang nhap hoac mat khau khong dung, nhan phim bat ky de dang nhap lai.\n");
		_getch();
		return false;
	}
}