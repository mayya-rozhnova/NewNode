#include "CNode.h"
#include "MyList.h"
#include "iostream"

using namespace std;

void print(CNode *t)
{
    CNode *T=t;
	do
	{   
		cout<<t->val<<endl;
		t=t->next;
	}
	while (t!=T);
}

bool Cycle(CNode *t)
{
	CNode *F, *S;
	F=S=t;
	if (F->next == NULL) return false;
	else F = F->next;
	while (true) {
    if (F->next == NULL || F->next->next == NULL)
      return false;
    if (F->next == S || F->next->next == S)
      return true;
    F = F->next->next;
    S = S->next;
	}
}


