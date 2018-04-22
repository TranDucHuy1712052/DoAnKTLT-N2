#pragma once
#include "structs.h"
#include "consoleHandles.h"

void inputListofClasses(classes &list, vector <_class> &classes, ListOfstudentCourses &studentList);
void ReturnLists(classes list, vector <_class> classes, ListOfstudentCourses studentList);
void viewListClasses(classes list);
void viewListStudentsInaClass(classes list, vector <_class> classes);
void addNewEmptyClass(classes &list, vector <_class> &classes);
void importStudentsFromCsvFile(UserList &userList, ListOfstudentCourses &studentList, vector <_class> &classess, classes list);