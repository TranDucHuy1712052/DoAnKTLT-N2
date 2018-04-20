#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
using namespace std;

#define ERROR_WRONG_OLD_PASSWORD -69
#define ERROR_WRONG_RETYPE -96
#define ERROR_INVALID_CHARACTER -66

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

//Mấy cái struct của student
struct course {
	char className[10];
};

struct classes {
	vector <course> clas;
	int size;
};

struct studentInfo {
	char id[20];
	char fullname[50];
	char email[50];
	char mobilephone[12];
};

struct _class {
	vector <studentInfo> student;
	vector <course> courseOfList;
	int sizeOfStudent, sizeOfCourses;
};

//