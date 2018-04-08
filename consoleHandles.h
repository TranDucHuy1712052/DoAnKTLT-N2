#pragma once

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "structs.h"

#define UP 72
#define DOWN 80
#define LEFT 75  
#define RIGHT 77
#define SPACE 32
#define ENTER 13

#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define DarkCyan		3
#define DarkRed			4
#define DarkPink		5
#define DarkYellow		6
#define DarkWhite		7
#define Grey			8
#define Blue			9
#define Green			10
#define Cyan			11
#define Red				12
#define Pink			13
#define Yellow			14
#define White			15

#define defaultColor	7

void resizeConsole(int width, int height);
void textcolor(int x);
void gotoxy(int x, int y);
int selectionMove(coordinates begin, int up, int down);