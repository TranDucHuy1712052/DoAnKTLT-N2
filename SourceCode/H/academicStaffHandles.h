#pragma once
#include "structs.h"
#include "consoleHandles.h"
#include "login.h"

void inputListofClasses(classes &list, vector <_class> &classes, ListOfstudentCourses &studentList);
void ReturnListsOfAddingClass(classes list, vector <_class> classes, ListOfstudentCourses studentList, UserList users);
void ReturnListsOfAddingStudents(classes list, vector <_class> classes, ListOfstudentCourses studentList, UserList users);
void viewListClasses(classes list);
void viewListStudentsInaClass(classes list, vector <_class> classes);
void addNewEmptyClass(classes &list, vector <_class> &classes, ListOfstudentCourses studentList, UserList users);
void importStudentsFromCsvFile(UserList &userList, ListOfstudentCourses &studentList, vector <_class> &classess, classes list);