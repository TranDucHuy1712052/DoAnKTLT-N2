#pragma once
#include "structs.h"
#include "consoleHandles.h"
#include "login.h"

void Password(User &a, UserList &list);
void hidePassword(char password[], int leftmost, int curRow);