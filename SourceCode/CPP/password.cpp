#include "password.h"

void passwordMenu()
{
	printf("\tChange password\n");
	printf("%12s\n", "Current:");
	printf("%12s\n", "New:");
	printf("%12s\n", "Re-type new:");
}

//Kiểm tra mật khẩu cũ, mới nhập lại đúng không
int checkPassword(char oldPassword[], char newPassword[], char retype[], User a)
{
	if (strcmp(oldPassword, a.password)) return ERROR_WRONG_OLD_PASSWORD;
	if (strcmp(newPassword, retype)) return ERROR_WRONG_RETYPE;
	return 1;
}

void changePassword(User &a, char newPassword[])
{
	char tmp[100];
	User b;
	FILE *f = fopen("users.csv", "r");
	FILE *g = fopen("tmp.csv", "w");

	fgets(tmp, 99, f);
	fprintf(g, "%s", tmp);

	int got;
	while (1) {
		got = fscanf(f, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^\n]\n", b.username, b.fullname, b.email, b.mobilephone, &b.type, b.password, b.Class);
		if (got != 7) break;
		if (strcmp(b.username, a.username))
			fprintf(g, "%s,%s,%s,%s,%d,%s,%s\n", b.username, b.fullname, b.email, b.mobilephone, b.type, b.password, b.Class);
		else
			fprintf(g, "%s,%s,%s,%s,%d,%s,%s\n", b.username, b.fullname, b.email, b.mobilephone, b.type, newPassword, b.Class);
	}

	fclose(f);
	fclose(g);

	strcpy(a.password, newPassword);
	remove("users.csv");
	rename("tmp.csv", "users.csv");
}

void Password(User &a)
{
	char oldPassword[50], newPassword[50], retype[50];
	system("cls");

	passwordMenu();

	while (getchar() != '\n');
	gotoxy(13, 1);
	gets_s(oldPassword, 49);
	/*fgets(oldPassword, 49, stdin);
	oldPassword[strlen(oldPassword) - 1] = '\0';*/

	gotoxy(13, 2);
	gets_s(newPassword, 49);
	/*fgets(newPassword, 49, stdin);
	newPassword[strlen(newPassword) - 1] = '\0';*/

	gotoxy(13, 3);
	gets_s(retype, 49);
	/*fgets(retype, 49, stdin);
	retype[strlen(retype) - 1] = '\0';*/

	int check = checkPassword(oldPassword, newPassword, retype, a);
	switch (check) {
	case 1:
		changePassword(a, newPassword);
		printf("Doi mat khau thanh cong\n");
		break;
	case ERROR_WRONG_OLD_PASSWORD: printf("Mat khau cu khong dung\n"); break;
	case ERROR_WRONG_RETYPE: printf("Nhap lai mat khau moi khong dung\n");
	}

	_getch();
}