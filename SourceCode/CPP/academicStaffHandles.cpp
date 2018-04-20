#include "academicStaffHandles.h"

char *makeFileName(course a)
{
	char *tmp = new char[18 + strlen(a.className)];
	strcpy(tmp, "classes\\class");
	strcat(tmp, a.className);
	strcat(tmp, ".csv");
	return tmp;
}

void inputClass(vector <_class> &classes, course a)
{
	studentInfo read;
	_class classe;
	char *courseName = makeFileName(a);
	
	FILE *f = fopen(courseName, "r");
	
	if (f == NULL) printf("Error: cannot open file\n");
	else {
		//Đọc dòng đầu
		char tmp[100];
		fgets(tmp, 99, f);

		//Đọc số lượng sinh viên
		fscanf(f, "%d\n", &classe.sizeOfStudent);

		//Đọc danh sách sinh viên
		for (int i=0;i<classe.sizeOfStudent;i++) {
			fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", read.id, read.fullname, read.email, read.mobilephone);
			classe.student.push_back(read);
		}

		//Bỏ qua dòng list of courses
		fgets(tmp, 99, f);
		//Đọc danh sách các môn học
		course anotherRead;
		int got = 0;
		got = fscanf(f, "%s", anotherRead.className);
		while (got == 1) {
			classe.ListOfCourses.push_back(anotherRead);
			got = fscanf(f, "%s", anotherRead.className);
		}

		classe.sizeOfCourses = classe.ListOfCourses.size();

		fclose(f);

		classes.push_back(classe);
	}
	
	delete[]courseName;
}

void inputListofClasses(classes &list, vector <_class> &classes)
{
	course read;
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

			inputClass(classes, read);

			got = fscanf(f, "%s", read.className);
		}

		list.size = list.clas.size();

		fclose(f);
	}
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
int getClass(classes list)
{
	int i;
	char name[10];
	printf("Nhap ten lop can xem danh sach sinh vien: ");
	scanf("%s", name);
	for (i = 0; i < list.size; i++) if (!strcmp(list.clas[i].className, name)) break;
	if (i == list.size) return -1;
	return i;
}

void viewListStudentsInaClass(classes list, vector <_class> classes)
{
	system("cls");
	int nth = getClass(list);
	
	if (nth == -1) printf("Lop khong ton tai.\n");
	else {
		printf("List of students in choosen class:\n");
		for (int i = 0; i < classes[nth].sizeOfStudent; i++) printf("%s\n", classes[nth].student[i].id);
	}
	printf("Nhan phim bat ky de quay lai.\n");

	_getch();
}