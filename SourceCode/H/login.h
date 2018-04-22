#pragma once
#include "structs.h"
#include "consoleHandles.h"
#include "password.h"

bool login(User &a, UserList list);
void ReadUsers(UserList &list);
void ReturnUsers(UserList list);