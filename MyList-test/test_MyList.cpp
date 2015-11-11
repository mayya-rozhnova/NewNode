#include "MyList.h"
#include <gtest.h>

TEST(MyList, CreateEmptyList) {
  CNode *head = CreateList(0, 0);
  CNode *expected_head = 0;
  EXPECT_EQ(expected_head, head);
}

TEST(MyList, CreateList) {
  const int kListSize = 10;
  int vals[kListSize];
  for (int i = 0; i < kListSize; ++i)
    vals[i] = i + 1;
  CNode *head = CreateList(kListSize, vals);

  int k = 0;
  while (head != 0) {
    EXPECT_EQ(vals[k], head->val);
    head = head->next;
    ++k;
  }
  EXPECT_EQ(kListSize, k);
}

TEST(MyList, IsCycle) {
	CNode *P=new CNode;
	CNode *Head=P;
	P->val = 1;
	for (int i = 0; i<4; i++)
	{
		CNode *Tmp = new CNode;
		Tmp->val = i + 2;
		P->next = Tmp;
		P = P->next;
	}
	P->next = Head;
	bool f = Cycle(Head);
	EXPECT_EQ (true, f);
}

TEST(Mylist, NoCycle) {
	int a[5] = {2,4,6,8,10};

	CNode* Head = CreateList(5, a);
	bool f = Cycle(Head);
	EXPECT_EQ(false, f);
}
