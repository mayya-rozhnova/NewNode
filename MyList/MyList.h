#ifndef GTEST_MYLIST_MYLIST_H
#define GTEST_MYLIST_MYLIST_H

#include "CNode.h"

void print(CNode *t);
bool Cycle(CNode *t);
CNode* CreateList(int count, const int* vals);

#endif  // GTEST_MYLIST_MYLIST_H
