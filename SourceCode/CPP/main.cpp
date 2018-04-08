#include "consoleHandles.h"
#include "structs.h"
#include "login.h"
#include "roles.h"
#include "begin.h"

int main()
{
	resizeConsole(1920, 1080);
	while (1) {
		system("cls");
		User user;

		//Màn hình bắt đầu
		if (begin() == FALSE) return 0;

		//Đăng nhập
		if (!login(user))
			while (1) {
				while (getchar() != '\n');
				if (login(user)) break;
			}

		//Lựa chọn các chức năng
		while (1) {
			roles(user);
			while (getchar() != '\n');
			break;
		}

	}
	return 0;
}