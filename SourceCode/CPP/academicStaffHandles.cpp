#include "academicStaffHandles.h"

//-----
//XỬ LÍ CLASSES
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
	//14 = so ki tu them vao
	char *tmp = new char[14 + strlen(id)];
	strcpy(tmp, "students\\");
	strcat(tmp, id);
	strcat(tmp, ".csv");
	return tmp;
}

char *makeFileCourseName(char id[10])
{
	// 'courses\\' = 9 ki tu, '.csv' = 4 kt => 13 ki tu
	char *tmp = new char[13 + strlen(id)];
	strcpy(tmp, "courses\\");
	strcat(tmp, id);
	strcat(tmp, ".csv");
	return tmp;
}

void inputStudent(ListOfstudentCoursesB &studentList, char id[10])
{
	studentCourseB read;
	//Đọc ở read, đẩy vô tm, xong đẩy tmp vô studentList
	studentCoursesB tm;

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

	delete[]idFile;
}

void inputClass(vector <_class> &classes, ListOfstudentCoursesB &studentList, classs a)
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
			fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n",
				read.id, read.fullname, read.email, read.mobilephone);
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

		classes.push_back(classe);
	}
	
	delete[]className;
}

void inputListofClasses(classes &list, vector <_class> &classes, ListOfstudentCoursesB &studentList)
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
	}
}

//Ghi lại các file id.csv
void ReturnIdFiles(vector <_class> classes, ListOfstudentCoursesB studentList, int i, int j)
{
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

	delete[]idFile;
}

//2 = "AttendanceList", 3 = "Presence", 4 = "ScoreBoard"
void updateCourseFiles(char courseCode[], classes list, vector <_class> classes, int i, int count)
{
	//AttendanceList
	char *tmp = makeCourseFilename(courseCode, 2);
	FILE *f = fopen(tmp, "a");
	
	if (f != NULL) {
		for (int j = classes[i].sizeOfStudent - count; j < classes[i].sizeOfStudent; j++) {
			fprintf(f, "%s,%s,%s,%s,%s\n",
				classes[i].student[j].id, classes[i].student[j].fullname, classes[i].student[j].email, classes[i].student[j].mobilephone, list.clas[i].className);
		}
		fclose(f);
	}

	delete tmp;
	
	//Presence
	tmp = makeCourseFilename(courseCode, 3);
	f = fopen(tmp, "a");
	
	if (f != NULL) {
		for (int j = classes[i].sizeOfStudent - count; j < classes[i].sizeOfStudent; j++) {
			fprintf(f, "%s,0,0,0,0,0,0,0,0,0,0,0,0\n",
				classes[i].student[j].id);
		}
		fclose(f);
	}
	
	delete tmp;
	
	//ScoreBoard
	tmp = makeCourseFilename(courseCode, 4);
	f = fopen(tmp, "a");

	if (f != NULL) {
		for (int j = classes[i].sizeOfStudent - count; j < classes[i].sizeOfStudent; j++) {
			fprintf(f, "%s,-1,-1,-1,-1\n",
				classes[i].student[j].id);
		}
		fclose(f);
	}
	
	delete tmp;
}

//Ghi lại các file class<name>.csv CÓ ghi lại IdFiles
void ReturnClassFiles1(classes list, vector <_class> classes, ListOfstudentCoursesB studentList, int i, int count)
{
	char *className = makeFileClassName(list.clas[i]);

	FILE *g = fopen(className, "w");

	fprintf(g, "id,full name,email,mobile phone\n%d\n", classes[i].sizeOfStudent);
	
	for (int j = 0; j < classes[i].sizeOfStudent; j++) {
		fprintf(g, "%s,%s,%s,%s\n",
			classes[i].student[j].id, classes[i].student[j].fullname, classes[i].student[j].email, classes[i].student[j].mobilephone);

		//Ghi lại các file id.csv
		ReturnIdFiles(classes, studentList, i, j);
	}

	fprintf(g, "list of courses\n");
	for (int j = 0; j < classes[i].sizeOfCourses; j++) {
		fprintf(g, "%s\n", classes[i].ListOfCourses[j].courseName);
		updateCourseFiles(classes[i].ListOfCourses[j].courseName, list, classes, i, count);
	}

	fclose(g);

	delete[]className;
}

//Ghi lại các file cần sửa sau khi add students
void ReturnListsOfAddingStudents(classes list, vector <_class> classes, ListOfstudentCoursesB studentList, UserList users, int nth, int count)
{
	//Ghi lại user.csv
	ReturnUsers(users);

	//Ghi lại class<đó>.csv
	ReturnClassFiles1(list, classes, studentList, nth, count);
}

//Tạo thêm file class<name>.csv
void ReturnClassFiles2(classs newClassName)
{
	char *className = makeFileClassName(newClassName);

	FILE *g = fopen(className, "w");

	fprintf(g, "id,full name,email,mobile phone\n%d\n", 0);

	fprintf(g, "list of courses\n");

	fclose(g);

	delete[]className;
}

//Ghi lại các file cần sửa sau khi add class
void ReturnListsOfAddingClass(classs newClassName)
{
	//Ghi lại file classes.csv
	FILE *f = fopen("classes.csv", "a");

	fprintf(f, "%s\n",newClassName.className);

	//Ghi lại các file class<name>.csv
	ReturnClassFiles2(newClassName);

	fclose(f);
}

void viewListClasses(classes list)
{
	system("cls");
	printf("List of classes:\n");
	for (int i = 0; i < list.size; i++) printf("%s\n", list.clas[i].className);
	printf("Nhan ENTER de quay lai.\n");
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
	printf("Nhan ENTER de quay lai.\n");

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

bool classExisted(classs newClassName, classes &list)
{
	for (int i = 0; i < list.size; i++) if (!strcmp(newClassName.className, list.clas[i].className)) return true;
	return false;
}

void addClass(classes &list, vector <_class> &classes, ListOfstudentCoursesB studentList, UserList users)
{
	_class newClass;

	newClass.sizeOfStudent = 0;
	newClass.sizeOfCourses = 0;
	classes.push_back(newClass);

	classs newClassName;

	system("cls");

	printf("Nhap ten lop can them: ");
	scanf("%s", newClassName.className);

	if (classExisted(newClassName, list)) printf("Lop da ton tai.\nNhan ENTER de quay lai.\n");
	else {
		list.clas.push_back(newClassName);
		list.size++;

		ReturnListsOfAddingClass(newClassName);
		printf("Done.\n");
	}

	_getch();
	while (getchar() != '\n');
}

void addNewEmptyClass(classes &list, vector <_class> &classes, ListOfstudentCoursesB studentList, UserList users)
{
	while (1) {
		addNewEmptyClassMenu();

		coordinates begin = { 0,1 };
		int choice = selectionMove(begin, 1, 2, 1);
		switch (choice) {
		case 1: addClass(list, classes, studentList, users); break;
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

void addToStudentList(studentInfo read, vector <_class> classess, int nth, ListOfstudentCoursesB &studentList, int NotEmpty)
{
	studentCoursesB tmp;
	if (NotEmpty) {
		tmp = studentList.student[classess[nth].student[0].pos];
	}
	else {
		tmp.size = 0;
	}
	studentList.student.push_back(tmp);
	studentList.size++;
}

void importStudents(UserList &userList, ListOfstudentCoursesB &studentList, vector <_class> &classess, classes list)
{
	system("cls");

	char className[10];

	printf("Nhap ten lop can them hoc sinh: ");
	scanf("%s", className);

	while (getchar() != '\n');

	//Lấy vị trí của lớp trong danh sách, count đếm số sinh viên đc thêm vào
	int nth = getClass(list, className), count = 0;

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
				count++;

				read.pos = pos++;

				addToClass(read, classess, nth);
				
				addToUsers(read, userList, className);
				
				addToStudentList(read, classess, nth, studentList, NotEmpty);
				
				got = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", read.id, read.fullname, read.email, read.mobilephone);
			}

			fclose(f);
			ReturnListsOfAddingStudents(list, classess, studentList, userList, nth, count);
			printf("Done.\n");
		}
	}

	while (getchar() != '\n');
}

void importStudentsFromCsvFile(UserList &userList, ListOfstudentCoursesB &studentList, vector <_class> &classess, classes list)
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


//---------------
//XỬ LÍ COURSES

bool isCourseExist(studentCourses list, studentCourse course)
{
	for (int i = 0; i < list.size; i++)
		if (strcmp(list.course[i].name, course.name) == 0 //phải dùng hàm strcmp mới đúng
			|| strcmp(list.course[i].code, course.code) == 0)
			return true;
	return false;
}

void ReadCourses(studentCourses &list, char *filename)
{
	//dùng để đọc file courses từ đường dẫn
	studentCourse a = {}; //biến đọc
	char tmp[100]; //biến xâu chứa dòng tựa đề, không có giá trị xử lí
	char *tmp2; //xử lí các filename liên quan
	FILE *f = fopen(filename, "r");
	if (f == NULL) {
		printf("Khong doc duoc file !"); return; }
	else
	{
		fgets(tmp, 99, f); //đọc qua hàng tựa đề
		int got;
		
		while (!(feof(f)))
		{
			got = fscanf(f, "%[^,],%[^\n]\n", a.code, a.name);

			if (!(isCourseExist(list, a))) //Lưu ý, code và name của học phần là duy nhất, không trùng lặp
			{
				//thêm vào dữ liệu
				list.size++;
				list.course.push_back(a);
				//tạo ra các file liên quan
				for (int i = 1; i <= 4; i++)
				{
					tmp2 = makeCourseFilename(a.code, i); //tìm filename tương ứng
					FILE *f = fopen(tmp2, "a"); //chế độ append : Nếu đã có, chỉ mở chứ không làm mất dữ liệu, ngược lại thì tạo ra file mới.
					fclose(f);
					delete tmp2;
				}
			}
		}
		list.size = list.course.size();
		fclose(f);
	}
	//fprintf(f, "course code,year,semester,coursename,lecturer username,start at,end at");	
}

void ReadSchedules(studentCourses &list)
{
	//thứ tự : course code	year	semester	coursename	lecturer username	start at	end at
	/*  got = fscanf(f, "%[^,],%[^,],%d,%[^,],%[^,],%d/%d/%d,%d/%d/%d\n",
	&a.code, &a.year, &a.semester, &a.name, &a.lecturer,
	&a.start.d, &a.start.m, &a.start.y, &a.end.d, &a.end.m, &a.end.y); */
}
void rewriteCourses(studentCourses list)
{
	// viết lại file courses.csv
	FILE *f = fopen("courses.csv", "w");

	fprintf(f, "course code,course name\n");

	for (int i = 0; i < list.size; i++)
	{
		studentCourse tmp = list.course[i];
		fprintf(f, "%s,%s\n", tmp.code, tmp.name);
	}

	fclose(f);
}
void importCoursesFromCsv(studentCourses &coursesList)
{
	system("cls");
	// tương tự như phần "read courses" nhưng là thêm vào dữ liệu chính, và phải nhập đường dẫn trước
	// hỏi đường dẫn
	char filename[500] = "";
	printf("Nhap duong dan chua file csv can import : "); 
	scanf("%s", filename);

	ReadCourses(coursesList, filename);
	rewriteCourses(coursesList);

	//kết thúc
	printf("Da xong.\n");
	printf("Nhan ENTER de quay lai.\n");
	_getch();
}
void addNewCourse(studentCourses &coursesList)
{
	system("cls");
	char *tmp;
	studentCourse newCourse = {};
	//cin.ignore((long long)numeric_limits<streamsize>::infinity, '\n'); //xoá hết các kí tự trước đó
	//nhập dữ liệu
	printf("Course name : "); 
	while (strcmp(newCourse.name, "\0") == 0) gets_s(newCourse.name, 100);

	printf("Course code : "); 
	gets_s(newCourse.code, 10);
	
	if (isCourseExist(coursesList, newCourse))
		printf("Mon hoc da ton tai ! Co the la bi trung ma mon hoac ten mon.\n");
	else
	{
		//thêm vào dữ liệu
		coursesList.size++;

		coursesList.course.push_back(newCourse);
		//ghi lại file courses.csv
		rewriteCourses(coursesList);
		//tạo ra các file liên quan
		for (int i = 1; i <= 4; i++)
		{
			tmp = makeCourseFilename(newCourse.code, i);
			FILE *f = fopen(tmp, "w");
			fclose(f);
			delete tmp;
		}
	}
	//kết thúc
	printf("Nhan ENTER de quay lai.\n");
	_getch();
}
void editCourse(studentCourses &coursesList)
{
	system("cls");
	int id = -1; //id là thứ tự môn học cần tìm trong danh sách
	studentCourse editing = {};
	char courseCode[10] = "", *tmp, *tmp2;
	//hỏi người dùng tên môn học cần chỉnh sửa
	printf("Ma mon hoc can chinh sua? (toi da 10 ki tu): "); scanf("%s", &courseCode);
	//chỉnh sửa thông tin trong 1 course
	//tìm tên môn học thông qua courseName
	for (int i = 0;i < coursesList.size; i++)
		if (strcmp(coursesList.course[i].code, courseCode) == 0)
		{
			id = i;
			break;
		}
	
	if (id > -1)
	{//xuất thông tin để người dùng biết họ chọn đúng môn, cũng như cho họ biết mình cần sửa cái gì
		printCourse(coursesList.course[id]);
		editing = coursesList.course[id];

		//cho người dùng nhập thứ tự nội dung cần chỉnh sửa
		char key = getchar();
		bool edited = false;
		while (key == '\n' || key != 'N' || key != 'n')
		{
			printf("Nhap so thu tu noi dung can chinh sua. Neu khong con chinh sua them, nhap 'N'.\n");
			printf("Danh sach cac muc thong tin:\n0. Ten mon hoc\n1. Ma mon hoc\n");
			key = getchar();
			if (key == 'N' || key == 'n') break;
			if (key == '0')
			{
				printf("Nhap ten moi cua mon hoc : ");
				cin.ignore(1, '\n');
				gets_s(editing.name, 100);
				edited = true;
			}
			else if (key == '1')
			{
				printf("Nhap ma moi cua mon hoc : ");
				cin.ignore(1, '\n');
				gets_s(editing.code, 10);
				if (isCourseExist(coursesList, editing)) {
					printf("Ma mon hoc da ton tai.\\n");
				}
				else edited = true;
			}
		}
		if (edited) //nếu đã được chỉnh sửa
		{
			//rename các file liên quan trước
			for (int i = 1; i <= 4; i++)
			{
				tmp = makeCourseFilename(courseCode, i);
				tmp2 = makeCourseFilename(editing.code, i);
				rename(tmp, tmp2);
				delete tmp;
				delete tmp2;
			}
			//gán giá trị
			coursesList.course[id] = editing;
			rewriteCourses(coursesList); //viết lại file
		}
	}
	else printf("Khong tim thay mon hoc ban yeu cau.\n");

	//kết thúc
	printf("Hay nhan ENTER de quay lai.\n");
	_getch();
}
void printCourse(studentCourse course)
{
	//hàm này để xuất thông tin của 1 môn học
	printf("\n-----\nTHONG TIN CUA MON HOC\n");
	printf("Course code : %s\n", course.code);
	printf("Course name : %s\n", course.name);
	printf("-----\n");
}
void removeCourse(studentCourses &coursesList)
{
	system("cls"); //xóa màn hình
	int id = -1;
	char *tmp;
	//tìm tên môn học cần xóa
	char courseCode[200] = {};
	printf("Nhap ma mon hoc can xoa ? : "); scanf("%s", &courseCode);
	for (int i = 0; i < coursesList.size; i++)
		if (strcmp(coursesList.course[i].code, courseCode) == 0)
		{
			id = i; //ghi nhận vị trí của môn học cần tìm trong danh sách
			break;
		}
	if (id == -1)
	{
		printf("Khong tim thay mon hoc ban yeu cau.\n"); 
	}
	else
	{
		//xuất thông tin của môn học này để đảm bảo là người dùng xóa đúng môn học
		printCourse(coursesList.course[id]);
		//xác nhận của người dùng
		printf("Nhan Y de xoa mon hoc nay. Nhan nut khac bat ki de huy lenh.");
		char key = getchar(); //nhập từ bàn phím
		while (key == '\n')
		{
			key = getchar();
			if (key == 'Y' || key == 'y')
			{
				//xóa các file liên quan trước
				for (int i = 1; i <= 4; i++)
				{
					tmp = makeCourseFilename(courseCode, i);
					remove(tmp);
					delete tmp;
				}
				//thủ tục xóa môn học 
				coursesList.course.erase(coursesList.course.begin() + id);
				//giảm độ lớn list xuống 1 đơn vị
				coursesList.size--;
				printf("Da xoa xong!\n");
			}
			else if (key == 'n' || key == 'N') return;
		}
		//viết lại file
		rewriteCourses(coursesList);
	}
	
	printf("Nhap ENTER de quay lai\n");
	_getch();
}
void viewListCourses(studentCourses coursesList)
{
	system("cls");
	printf("List of courses:\n");
	for (int i = 0; i < coursesList.size; i++) 
		printf("%s-%s\n", coursesList.course[i].code, coursesList.course[i].name);
	printf("Nhan ENTER de quay lai.\n");
	_getch();
}

char *makeCourseFilename(char *coursecode, int num)
{
	//tạo ra tên file liên quan đến môn học, dựa theo mã môn
	//1 = Schedule,  2 = AttendanceList, 3 = Presence, 4 = ScoreBoard
	int plus = 8 + 6 + 4; //"courses\\" = 9 kí tự; 'course' = 6 kí tự; ".csv" = 4 kí tự
	if (num == 2) plus += 14;
	else if (num == 3) plus += 8;
	else if (num == 4) plus += 10;

	char *tmp = new char[strlen(coursecode) + plus + 1];
	strcpy(tmp, "courses\\"); //folder chứa các file nói trên
	strcat(tmp, "course"); //tmp = "course"
	strcat(tmp, coursecode); //tmp = "course<code>"
	if (num == 2) strcat(tmp, "AttendanceList"); 
	else if (num == 3) strcat(tmp, "Presence");
	else if (num == 4) strcat(tmp, "ScoreBoard");
	strcat(tmp, ".csv"); //đuôi file

	return tmp;
}