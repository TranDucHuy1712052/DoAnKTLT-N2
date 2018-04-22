#include "password.h"

//Ẩn password khi gõ, lưu pass vào password
void hidePassword(char password[], int leftmost, int curRow)
{
	int length;
	char tmp;
	
	strcpy(password, "");
	
	while (1) {
		tmp = _getch();

		length = strlen(password);

		if (tmp == ENTER) {
			putchar('\n');
			break;
		}
		
		else if (tmp == BACKSPACE) {
			if (length > 0) {
				password[length - 1] = '\0';
				printf("\b \b");
			}
		}
		
		else {
			printf("*");
			strcat(password, " ");
			password[length] = tmp;
		}
	}
}

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
	if (strstr(newPassword, " ")) return ERROR_INVALID_CHARACTER;
	if (strcmp(newPassword, retype)) return ERROR_WRONG_RETYPE;
	return 1;
}

void changePassword(User &a, UserList &list, char newPassword[])
{
	for (int i = 0; i < list.size; i++)
		if (!strcmp(a.username, list.user[i].username)) {
			strcpy(list.user[i].password, newPassword);
			break;
		}
}

void Password(User &a, UserList &list)
{
	char oldPassword[50], newPassword[50], retype[50];
	system("cls");

	passwordMenu();
	
	gotoxy(13, 1);
	hidePassword(oldPassword, 13, 1);

	gotoxy(13, 2);
	hidePassword(newPassword, 13, 2);

	gotoxy(13, 3);
	hidePassword(retype, 13, 3);

	int check = checkPassword(oldPassword, newPassword, retype, a);
	switch (check) {
	case 1:
		changePassword(a, list, newPassword);
		printf("Doi mat khau thanh cong.\n");
		break;
	case ERROR_WRONG_OLD_PASSWORD: printf("Mat khau cu khong dung.\n"); break;
	case ERROR_WRONG_RETYPE: printf("Nhap lai mat khau moi khong dung.\n"); break;
	case ERROR_INVALID_CHARACTER: printf("Mat khau moi co ky tu khong hop le.\n");
	}

	while (getchar() != '\n');
}