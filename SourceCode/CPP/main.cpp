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
		UserList list;

		//Màn hình bắt đầu
		if (begin() == FALSE) return 0;

		//Đăng nhập
		ReadUsers(list);
		
		while (1) {
			if (login(user, list)) break;
		}

		//Lựa chọn các chức năng
		while (1) {
			roles(user, list);
			break;
		}

		//Ghi lại file users.csv
		ReturnUsers(list);
	}
	
	return 0;
}