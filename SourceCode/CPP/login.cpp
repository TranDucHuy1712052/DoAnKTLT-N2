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
bool findUser(User &a, UserList list, char id[], char password[])
{
	for (int i = 0; i < list.size; i++)
		if (!strcmp(list.user[i].username, id) && !strcmp(list.user[i].password, password)) {
			a = list.user[i];
			return true;
		}

	return false;
}

bool login(User &a, UserList list)
{
	char id[20], password[50];
	
	menuLogin();

	gotoxy(10, 1);
	gets_s(id, 19);

	gotoxy(10, 2);
	hidePassword(password, 10, 2);

	if (findUser(a, list, id, password)) {
		return true;
	}
	else {
		printf("Ten dang nhap hoac mat khau khong dung, nhan ENTER de dang nhap lai.\n");
		_getch();
		return false;
	}
}

//Đọc tất cả user vào list
void ReadUsers(UserList &list)
{
	char tmp[100];
	User a;

	FILE *f = fopen("users.csv", "r");
	if (f == NULL) printf("Error: cannot open file.\n");
	else {
		fgets(tmp, 99, f);

		int got = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^\n]\n", a.username, a.fullname, a.email, a.mobilephone, &a.type, a.password, a.Class);
		while (got == 7) {
			list.user.push_back(a);
			got = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^\n]\n", a.username, a.fullname, a.email, a.mobilephone, &a.type, a.password, a.Class);
		}

		list.size = list.user.size();

		fclose(f);
	}
}

void ReturnUsers(UserList list)
{
	FILE *f = fopen("users.csv", "w");
	
	fprintf(f, "username,full name,email,mobile phone,type,password,class\n");

	for (int i = 0; i < list.size; i++)
		fprintf(f, "%s,%s,%s,%s,%d,%s,%s\n", list.user[i].username, list.user[i].fullname, list.user[i].email, list.user[i].mobilephone, list.user[i].type, list.user[i].password, list.user[i].Class);
	
	fclose(f);
}