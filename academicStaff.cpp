#include "academicStaff.h"

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

void students()
{
	while (1) {
		studentsMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 9);
		switch (choice) {
		case 1: tmpPrint(); break;
		case 2: tmpPrint(); break;
		case 3: tmpPrint(); break;
		case 4: tmpPrint(); break;
		case 5: tmpPrint(); break;
		case 6: tmpPrint(); break;
		case 7: tmpPrint(); break;
		case 8: tmpPrint(); break;
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

void courses()
{
	while (1) {
		coursesMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 6);
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
		int choice = selectionMove(begin, 1, 6);
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
		int choice = selectionMove(begin, 1, 3);
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
		int choice = selectionMove(begin, 1, 3);
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

void AcademicStaff(User a)
{
	while (1) {
		academicStaffMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 6);
		switch (choice) {
		case 1: students(); break;
		case 2: courses(); break;
		case 3: courseSchedule(); break;
		case 4: attendanceList(); break;
		case 5: scoreboard(); break;
		case 6: return;
		}
	}

}