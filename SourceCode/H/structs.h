#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include <iostream>
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

//Danh sách tất cả user
struct UserList {
	vector <User> user;
	int size;
};

//Mấy cái struct của student
struct course {
	char courseName[10];
};

struct classs {
	char className[10];
};

//Danh sách các lớp
struct classes {
	vector <classs> clas;
	int size;
};

struct studentInfo {
	char id[20];
	char fullname[50];
	char email[50];
	char mobilephone[12];
	int pos;//Lưu vị trí trong Danh sách toàn bộ sinh viên, truy cập cho nhanh
};

//Thông tin một lớp
struct _class {
	vector <studentInfo> student;
	vector <course> ListOfCourses;
	int sizeOfStudent, sizeOfCourses;
};
//ngày / tháng / năm
struct date {
	int d, m, y;
};
//thời gian : giờ / phút
struct time {
	int h, m;
};

//Sửa cái này crash sml, đừng please T.T
struct studentCourseB {
	char course[10];
	char Class[10];
	char year[10];
	int semester;
	char lecturer[20];
	date start, end;
	time from, to;
	char dateOfWeek[10];
};

struct studentCoursesB {
	vector <studentCourseB> course;
	int size;
};

//Danh sách toàn bộ sinh viên (mấy fild id.csv)
struct ListOfstudentCoursesB {
	vector <studentCoursesB> student;
	int size;
};
//---------------------

//Thông tin 1 lịch học của 1 môn học
struct courseSchedules {//Thêm s để khỏi trùng tên hàm
	char Class[10];
	char year[10];
	int semester;
	char lecturer[20];
	date start, end;
	time from, to;
	char dateOfWeek[10];
};
//Thông tin của 1 course
struct studentCourse {
	char name[100];
	char code[10];
	vector <courseSchedules> schedules;
};
//Danh sách toàn bộ các môn học
struct studentCourses {
	vector <studentCourse> course;
	int size;
};

//Danh sách toàn bộ sinh viên
struct ListOfstudentCourses {
	vector <studentCourses> student;
	int size;
};