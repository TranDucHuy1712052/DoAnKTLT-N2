#include "consoleHandles.h"

// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x , y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//Di chuyển bằng phím lên xuống để lựa chọn, giới hạn dòng up xuống down, enter để chọn, lên xuống khoảng cách distance
int selectionMove(coordinates begin, int up, int down, int distance)
{
	gotoxy(begin.x, begin.y);
	while (1) {
		int got = _getch();
		switch (got) {
		case UP:
			if (begin.y>up) {
				begin.y -= distance;
				gotoxy(begin.x, begin.y);
			}
			else {
				begin.y = down;
				gotoxy(begin.x, begin.y);
			}break;
		
		case DOWN:
			if (begin.y<down) {
				begin.y += distance;
				gotoxy(begin.x, begin.y);
			}
			else {
				begin.y = up;
				gotoxy(begin.x, begin.y);
			}break;
		
		case ENTER: return begin.y;
		}
	}
}

//Khi viết mật khẩu ẩn, bấm backspace nó sẽ xóa dấu *, leftmost để chặn lại không cho nó lùi quá giới hạn
void goBackwards(coordinates cur, int leftmost)
{
	if (cur.x > leftmost) printf("\b \b");
}
