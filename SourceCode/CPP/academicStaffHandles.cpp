#include "academicStaffHandles.h"

//Tạo đường dẫn để mở file
char *makeFileClassName(classs a)
{
	char *tmp = new char[18 + strlen(a.className)];
	strcpy(tmp, "classes\\class");
	strcat(tmp, a.className);
	strcat(tmp, ".csv");
	return tmp;
}

char *makeFileStudentName(char id[10])
{
	char *tmp = new char[14 + strlen(id)];
	strcpy(tmp, "students\\");
	strcat(tmp, id);
	strcat(tmp, ".csv");
	return tmp;
}

void inputStudent(ListOfstudentCourses &studentList, char id[10])
{
	studentCourse read;
	//Đọc ở read, đẩy vô tm, xong đẩy tmp vô studentList
	studentCourses tm;

	char *idFile = makeFileStudentName(id);

	FILE *f = fopen(idFile, "r");
	if (f == NULL) printf("Error: cannot open file\n");
	else {
		//Đọc dòng đầu
		char tmp[100];
		fgets(tmp, 99, f);

		int got = fscanf(f, "%[^,],%[^,],%[^,],%d,%[^,],%d/%d/%d,%d/%d/%d,%d:%d,%d:%d,%[^\n]\n", read.course, read.Class, read.year, &read.semester, read.lecturer, &read.start.d, &read.start.m, &read.start.y, &read.end.d, &read.end.m, &read.end.y, &read.from.h, &read.from.m, &read.to.h, &read.to.m, read.dateOfWeek);
		while (got == 16) {
			tm.course.push_back(read);
			got = fscanf(f, "%[^,],%[^,],%[^,],%d,%[^,],%d/%d/%d,%d/%d/%d,%d:%d,%d:%d,%[^\n]\n", read.course, read.Class, read.year, &read.semester, read.lecturer, &read.start.d, &read.start.m, &read.start.y, &read.end.d, &read.end.m, &read.end.y, &read.from.h, &read.from.m, &read.to.h, &read.to.m, read.dateOfWeek);
		}
		tm.size = tm.course.size();

		studentList.student.push_back(tm);
		studentList.size = studentList.student.size();

		fclose(f);
	}

	remove(idFile);

	delete[]idFile;
}

void inputClass(vector <_class> &classes, ListOfstudentCourses &studentList, classs a)
{
	studentInfo read;
	_class classe;
	char *className = makeFileClassName(a);
	
	FILE *f = fopen(className, "r");
	
	if (f == NULL) printf("Error: cannot open file\n");
	else {
		int pos = studentList.student.size();
		//Đọc dòng đầu
		char tmp[100];
		fgets(tmp, 99, f);

		//Đọc số lượng sinh viên
		fscanf(f, "%d\n", &classe.sizeOfStudent);

		//Đọc danh sách sinh viên
		for (int i=0;i<classe.sizeOfStudent;i++) {
			fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", read.id, read.fullname, read.email, read.mobilephone);
			read.pos = pos++;
			classe.student.push_back(read);
			inputStudent(studentList, read.id);
		}

		//Bỏ qua dòng list of courses
		fgets(tmp, 99, f);
		//Đọc danh sách các môn học
		course anotherRead;
		int got = 0;
		got = fscanf(f, "%s", anotherRead.courseName);
		while (got == 1) {
			classe.ListOfCourses.push_back(anotherRead);
			got = fscanf(f, "%s", anotherRead.courseName);
		}

		classe.sizeOfCourses = classe.ListOfCourses.size();

		fclose(f);

		//Xóa file
		remove(className);

		classes.push_back(classe);
	}
	
	delete[]className;
}

void inputListofClasses(classes &list, vector <_class> &classes, ListOfstudentCourses &studentList)
{
	classs read;
	FILE *f = fopen("classes.csv", "r");
	if (f == NULL) printf("Error: cannot open file\n");
	else {
		//Đọc dòng đầu
		char tmp[100];
		fgets(tmp, 99, f);
		
		int got = 0;
		got = fscanf(f, "%s", read.className);
		while (got == 1) {
			list.clas.push_back(read);

			inputClass(classes, studentList, read);

			got = fscanf(f, "%s", read.className);
		}

		list.size = list.clas.size();

		fclose(f);

		//Xóa file
		remove("classes.csv");
	}
}

//Ghi lại các file đã xóa
void ReturnLists(classes list, vector <_class> classes, ListOfstudentCourses studentList)
{
	//Ghi lại file classes.csv
	FILE *f = fopen("classes.csv", "w");

	fprintf(f, "classname\n");

	for (int i = 0; i < list.size; i++) {
		fprintf(f, "%s\n", list.clas[i].className);

		//Ghi lại các file class<name>.csv
		char *className = makeFileClassName(list.clas[i]);

		FILE *g = fopen(className, "w");

		fprintf(g, "id,full name,email,mobile phone\n%d\n", classes[i].sizeOfStudent);
		for (int j = 0; j < classes[i].sizeOfStudent; j++) {
			fprintf(g, "%s,%s,%s,%s\n", classes[i].student[j].id, classes[i].student[j].fullname, classes[i].student[j].email, classes[i].student[j].mobilephone);

			//Ghi lại các file id.csv
			char *idFile = makeFileStudentName(classes[i].student[j].id);

			FILE *h = fopen(idFile, "w");

			fprintf(h, "course,class,year,semester,lecturer username,start at,end at,from,to,date of week\n");

			for (int k = 0; k < studentList.student[classes[i].student[j].pos].size; k++)
				fprintf(h, "%s,%s,%s,%d,%s,%d/%d/%d,%d/%d/%d,%d:%d,%d:%d,%s\n", studentList.student[classes[i].student[j].pos].course[k].course,
					studentList.student[classes[i].student[j].pos].course[k].Class,
					studentList.student[classes[i].student[j].pos].course[k].year,
					studentList.student[classes[i].student[j].pos].course[k].semester,
					studentList.student[classes[i].student[j].pos].course[k].lecturer,
					studentList.student[classes[i].student[j].pos].course[k].start.d,
					studentList.student[classes[i].student[j].pos].course[k].start.m,
					studentList.student[classes[i].student[j].pos].course[k].start.y,
					studentList.student[classes[i].student[j].pos].course[k].end.d,
					studentList.student[classes[i].student[j].pos].course[k].end.m,
					studentList.student[classes[i].student[j].pos].course[k].end.y,
					studentList.student[classes[i].student[j].pos].course[k].from.h,
					studentList.student[classes[i].student[j].pos].course[k].from.m,
					studentList.student[classes[i].student[j].pos].course[k].to.h,
					studentList.student[classes[i].student[j].pos].course[k].to.m,
					studentList.student[classes[i].student[j].pos].course[k].dateOfWeek);

			fclose(h);
		}

		fprintf(g, "list of courses\n");
		for (int j = 0; j < classes[i].sizeOfCourses; j++)
			fprintf(g, "%s\n", classes[i].ListOfCourses[j].courseName);

		fclose(g);

		delete[]className;
	}

	fclose(f);
}

void viewListClasses(classes list)
{
	system("cls");
	printf("List of classes:\n");
	for (int i = 0; i < list.size; i++) printf("%s\n", list.clas[i].className);
	printf("Nhan phim bat ky de quay lai.\n");
	_getch();
}

//Lấy số thứ tự của lớp trong danh sách
int getClass(classes list, char name[])
{
	int i;
	for (i = 0; i < list.size; i++) if (!strcmp(list.clas[i].className, name)) break;
	if (i == list.size) return -1;
	return i;
}

void viewListStudentsInaClass(classes list, vector <_class> classes)
{
	system("cls");

	char name[10];
	printf("Nhap ten lop can xem danh sach sinh vien: ");
	scanf("%s", name);

	int nth = getClass(list, name);
	
	if (nth == -1) printf("Lop khong ton tai.\n");
	else {
		printf("List of students in choosen class:\n");
		for (int i = 0; i < classes[nth].sizeOfStudent; i++) printf("%s - %s\n", classes[nth].student[i].id, classes[nth].student[i].fullname);
	}
	printf("Nhan phim bat ky de quay lai.\n");

	_getch();
}

void addNewEmptyClassMenu()
{
	system("cls");

	textcolor(Green);
	printf("\tAdd a new empty class\n");
	textcolor(defaultColor);

	printf("1. Add\n");
	printf("2. Back\n");
}

void addClass(classes &list, vector <_class> &classes)
{
	_class newClass;

	newClass.sizeOfStudent = 0;
	newClass.sizeOfCourses = 0;
	classes.push_back(newClass);

	classs newClassName;
	
	system("cls");

	printf("Nhap ten lop can them: ");
	scanf("%s", newClassName.className);
	
	list.clas.push_back(newClassName);
	list.size++;

	printf("Done.\n");
	
	_getch();
	while (getchar() != '\n');
}

void addNewEmptyClass(classes &list, vector <_class> &classes)
{
	while (1) {
		addNewEmptyClassMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 2, 1);
		switch (choice) {
		case 1: addClass(list, classes); break;
		case 2: return;
		}
	}
}

void importStudentsFromCsvFileMenu()
{
	system("cls");

	textcolor(Green);
	printf("\tImport students of a class from a csv file\n");
	textcolor(defaultColor);

	printf("1. Import\n");
	printf("2. Back\n");
}

void addToClass(studentInfo read, vector <_class> &classes, int nth)
{
	classes[nth].student.push_back(read);
	classes[nth].sizeOfStudent++;
}

void addToUsers(studentInfo read, UserList &userList, char className[10])
{
	User tmp;
	strcpy(tmp.username, read.id);
	strcpy(tmp.fullname, read.fullname);
	strcpy(tmp.email, read.email);
	strcpy(tmp.mobilephone, read.mobilephone);
	tmp.type = student;
	//pass có thể khác, tùy
	strcpy(tmp.password, read.id);
	strcpy(tmp.Class, className);
	
	userList.user.push_back(tmp);
	userList.size++;

}

void addToStudentList(studentInfo read, vector <_class> classess, int nth, ListOfstudentCourses &studentList, int NotEmpty)
{
	studentCourses tmp;
	if (NotEmpty) {
		tmp = studentList.student[classess[nth].student[0].pos];
	}
	else {
		tmp.size = 0;
	}
	studentList.student.push_back(tmp);
	studentList.size++;
}

void importStudents(UserList &userList, ListOfstudentCourses &studentList, vector <_class> &classess, classes list)
{
	system("cls");

	char className[10];

	printf("Nhap ten lop can them hoc sinh: ");
	scanf("%s", className);

	while (getchar() != '\n');

	//Lấy vị trí của lớp trong danh sách
	int nth = getClass(list, className);

	if (nth == -1) printf("Lop khong ton tai.\nNhan ENTER de quay lai.\n");
	else {
		char link[100];
		printf("Nhap duong dan file hoc sinh can them vao lop: ");
		gets_s(link, 99);
		
		int NotEmpty = classess[nth].sizeOfStudent;//Biến kiểm tra lớp đã có sẵn học sinh chưa

		FILE *f = fopen(link, "r");
		if (f == NULL) printf("Error: cannot open file.\nNhan ENTER de quay lai.\n");
		else {
			int pos = studentList.student.size();//Lấy vị trí của sinh viên mới cần thêm trong danh sách
			studentInfo read;
			
			//Đọc dòng đầu
			char tmp[100];
			fgets(tmp, 99, f);

			//Đọc danh sách sinh viên
			int got = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", read.id, read.fullname, read.email, read.mobilephone);
			while (got == 4) {
				read.pos = pos++;

				addToClass(read, classess, nth);
				
				addToUsers(read, userList, className);
				
				addToStudentList(read, classess, nth, studentList, NotEmpty);
				
				got = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", read.id, read.fullname, read.email, read.mobilephone);
			}

			fclose(f);
			printf("Done.\n");
		}
	}

	while (getchar() != '\n');
}

void importStudentsFromCsvFile(UserList &userList, ListOfstudentCourses &studentList, vector <_class> &classess, classes list)
{
	while (1) {
		importStudentsFromCsvFileMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 2, 1);
		switch (choice) {
		case 1: importStudents(userList, studentList, classess, list); break;
		case 2: return;
		}
	}
}