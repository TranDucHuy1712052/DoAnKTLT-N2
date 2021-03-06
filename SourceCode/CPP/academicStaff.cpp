﻿#include "academicStaff.h"

void studentsMenu()
{
	system("cls");

	textcolor(Green);
	printf("\tStudents Menu\n");
	textcolor(defaultColor);

	printf("1. Import students of a class from a csv file\n");
	printf("2. Add a new student to a class\n");
	printf("3. Edit an existing student\n");
	printf("4. Remove a student\n");
	printf("5. Change students from class A to class B\n");
	printf("6. Add a new empty class\n");
	printf("7. View list of classes\n");
	printf("8. View list of students in a class\n");
	printf("9. Back\n");
}

void students(UserList &userList)
{
	//list là danh sách các lớp
	classes list;
	//classes là mảng chứa từng lớp
	vector <_class> classes;
	//studentList là danh sách tất cả sinh viên, mấy file id.csv chứa courses
	ListOfstudentCoursesB studentList;

	//nhập từ dữ liệu bên ngoài
	inputListofClasses(list, classes, studentList);

	while (1) {
		studentsMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 9, 1);
		switch (choice) {
		case 1: importStudentsFromCsvFile(userList, studentList, classes, list); break;
		case 2: tmpPrint(); break;
		case 3: tmpPrint(); break;
		case 4: tmpPrint(); break;
		case 5: tmpPrint(); break;
		case 6: addNewEmptyClass(list, classes, studentList, userList); break;
		case 7: viewListClasses(list); break;
		case 8: viewListStudentsInaClass(list, classes); break;
		case 9: return;
		}
	}
}

void coursesMenu()
{
	system("cls");

	textcolor(Green);
	printf("\tCourses Menu\n");
	textcolor(defaultColor);

	printf("1. Import courses from a csv file\n");
	printf("2. Add a new course\n");
	printf("3. Edit an existing course\n");
	printf("4. Remove a course\n");
	printf("5. View list of courses\n");
	printf("6. Back\n");
}

void courses(studentCourses &list)
{
	//nhập dữ liệu từ bên ngoài
	ReadCourses(list, "courses.csv");
	//xử lí
	while (1) {
		coursesMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 6, 1);
		switch (choice) {
		case 1: importCoursesFromCsv(list); break;
		case 2: addNewCourse(list); break; //thêm 1 môn
		case 3: editCourse(list); break; //sửa thông tin 1 môn 
		case 4: removeCourse(list); break; //xóa 1 môn
		case 5: viewListCourses(list); break; //xem thông tin các môn
		case 6: return;
		}
	}
}

void courseScheduleMenu()
{
	system("cls");

	textcolor(Green);
	printf("\tCourses Schedule Menu\n");
	textcolor(defaultColor);

	printf("1. Import courses' schedules from a csv file\n");
	printf("2. Add a course's schedule\n");
	printf("3. Edit a course's schedule\n");
	printf("4. Remove a course's schedule\n");
	printf("5. View list of schedules\n");
	printf("6. Back\n");
}

void courseSchedule()
{
	while (1) {
		courseScheduleMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 6, 1);
		switch (choice) {
		case 1: tmpPrint(); break;
		case 2: tmpPrint(); break;
		case 3: tmpPrint(); break;
		case 4: tmpPrint(); break;
		case 5: tmpPrint(); break;
		case 6: return;
		}
	}
}

void attendanceListMenu()
{
	system("cls");

	textcolor(Green);
	printf("\tAttendance List Menu\n");
	textcolor(defaultColor);

	printf("1. Search and view attendance list of a course\n");
	printf("2. Export attendance list to a csv file\n");
	printf("3. Back\n");
}

void attendanceList()
{
	while (1) {
		attendanceListMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 3, 1);
		switch (choice) {
		case 1: tmpPrint(); break;
		case 2: tmpPrint(); break;
		case 3: return;
		}
	}
}

void scoreboardMenu()
{
	system("cls");

	textcolor(Green);
	printf("\tScore Board Menu\n");
	textcolor(defaultColor);

	printf("1. Search and view scoreboard of a course\n");
	printf("2. Export a scoreboard to a csv file\n");
	printf("3. Back\n");
}

void scoreboard()
{
	while (1) {
		scoreboardMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 3, 1);
		switch (choice) {
		case 1: tmpPrint(); break;
		case 2: tmpPrint(); break;
		case 3: return;
		}
	}
}

void academicStaffMenu()
{
	system("cls");

	textcolor(Cyan);
	printf("\tMenu\n");
	textcolor(defaultColor);

	printf("1. Students\n");
	printf("2. Courses\n");
	printf("3. Courses Schedule\n");
	printf("4. Attendance List\n");
	printf("5. Scoreboard\n");
	printf("6. Back\n");
}

void AcademicStaff(User a, UserList &list, studentCourses &coursesList)
{
	while (1) {
		academicStaffMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 6, 1);
		switch (choice) {
		case 1: students(list); break;
		case 2: courses(coursesList); break;
		case 3: courseSchedule(); break;
		case 4: attendanceList(); break;
		case 5: scoreboard(); break;
		case 6: return;
		}
	}

}