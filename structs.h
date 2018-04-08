#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define ERROR_WRONG_OLD_PASSWORD -69
#define ERROR_WRONG_RETYPE -96

enum {
	student, academicStaff, lecturer
};

struct User {
	char username[20];
	char fullname[50];
	char email[50];
	char mobilephone[12];
	int type;
	char password[50];
	char Class[10];
};

struct coordinates {
	int x, y;
};