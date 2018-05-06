#pragma once
#include "structs.h"
#include "consoleHandles.h"
#include "login.h"

//classes
void inputListofClasses(classes &list, vector <_class> &classes, ListOfstudentCoursesB &studentList);
//void ReturnLists(classes list, vector <_class> classes, ListOfstudentCoursesB studentList, UserList users);
void ReturnListsOfAddingClass(classes list, vector <_class> classes, ListOfstudentCoursesB studentList, UserList users);
void ReturnListsOfAddingStudents(classes list, vector <_class> classes, ListOfstudentCoursesB studentList, UserList users);
void viewListClasses(classes list);
void viewListStudentsInaClass(classes list, vector <_class> classes);
void addNewEmptyClass(classes &list, vector <_class> &classes, ListOfstudentCoursesB studentList, UserList users);
void importStudentsFromCsvFile(UserList &userList, ListOfstudentCoursesB &studentList, vector <_class> &classess, classes list);

//courses
void ReadCourses(studentCourses &list, char *filename);
void rewriteCourses(studentCourses list);
void importCoursesFromCsv(studentCourses &coursesList);
void printCourse(studentCourse course);
void addNewCourse(studentCourses &coursesList);
void editCourse(studentCourses &coursesList);
void removeCourse(studentCourses &coursesList);
void viewListCourses(studentCourses coursesList);
char *makeCourseFilename(char *coursecode, int num); 