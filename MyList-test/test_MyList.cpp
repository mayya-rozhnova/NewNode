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

TEST(MyList, NoCycle_in_empty) {
	CNode *Head = NULL;
	bool f = Cycle(Head);
	EXPECT_EQ(false, f);
}

TEST(MyList, NoCycle) {
	int a[5] = {2,4,6,8,10};

	CNode* Head = CreateList(5, a);
	bool f = Cycle(Head);
	EXPECT_EQ(false, f);
}

TEST(MyList, IsCycle_one_without_cycle) {
	CNode *P = new CNode;
	CNode *Head = P;
	P->val = 1;
	P->next = NULL;
	bool f = Cycle(Head);
	EXPECT_EQ(false, f);
}

TEST(MyList, IsCycle_one_with_cycle) {
	CNode *P = new CNode;
	CNode *Head = P;
	P->val = 1;
	P->next = P;
	bool f = Cycle(Head);
	EXPECT_EQ(true, f);
}

TEST(MyList, IsCycle_cycle_first_element) {
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

TEST(MyList, Is_Cycle_cycle_second_element) {
	CNode *P=new CNode;
	CNode *Head=P;
	P->val = 1;
	CNode *Tmp2 = new CNode;
	for (int i = 1; i < 4; i++)
	{
		CNode *Tmp = new CNode;
		Tmp->val = i + 1;
		P->next = Tmp;
		P = P->next;
		if (i == 1)
		Tmp2 = P;
	}
	P->next = Tmp2;
	bool f = Cycle(Head);
	EXPECT_EQ (true, f);
}

TEST(MyList, Is_Cycle_cycle_third_element) {
	CNode *P=new CNode;
	CNode *Head=P;
	P->val = 1;
	CNode *Tmp2 = new CNode;
	for (int i = 1; i < 4; i++)
	{
		CNode *Tmp = new CNode;
		Tmp->val = i + 1;
		P->next = Tmp;
		P = P->next;
		if (i == 2)
		Tmp2 = P;
	}
	P->next = Tmp2;
	bool f = Cycle(Head);
	EXPECT_EQ (true, f);
}

TEST(MyList, Is_Cycle_cycle_last_element) {
	CNode *P=new CNode;
	CNode *Head=P;
	P->val = 1;
	CNode *Tmp2 = new CNode;
	for (int i = 1; i < 4; i++)
	{
		CNode *Tmp = new CNode;
		Tmp->val = i + 1;
		P->next = Tmp;
		P = P->next;
	}
	P->next = P;
	bool f = Cycle(Head);
	EXPECT_EQ (true, f);
}

