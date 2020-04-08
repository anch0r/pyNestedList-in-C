#include <stdlib.h>

typedef struct list
{
	int L[3]; //base list
	struct list *p; //nested list pointer
	list* copy();
	list* deepcopy();
}list;

list* list::copy() //shallow copy
{
	list* clist = (list*)malloc(sizeof(list));
	for (int i = 0; i < (sizeof(list) / sizeof(int)); ++i) clist->L[i] = this->L[i];
	clist->p = this->p;
	return clist;
}

list* list::deepcopy()
{
	list* clist = (list*)malloc(sizeof(list));
	for (int i = 0; i < (sizeof(list) / sizeof(int)); ++i) clist->L[i] = this->L[i];
	clist->p = (list*)malloc(sizeof(list));
	for (int i = 0; i < (sizeof(list) / sizeof(int)); ++i) clist->p->L[i] = this->p->L[i];
	clist->p->p = (list*)malloc(sizeof(list));
	for (int i = 0; i < 2; ++i) clist->p->p->L[i] = this->p->p->L[i];
	clist->p->p->L[2] = NULL;
	clist->p->p->p = nullptr;
	return clist;
}

int main()
{
	list *a = (list*)malloc(sizeof(list));
	//list init
	for (int i = 0; i < (sizeof(list)/ sizeof(int)); ++i) a->L[i] = (i + 1);
	a->p = (list*)malloc(sizeof(list));
	for (int i = 0; i < (sizeof(list) / sizeof(int)); ++i) a->p->L[i] = (i + 3);
	a->p->p = (list*)malloc(sizeof(list));
	for (int i = 0; i < 2; ++i) a->p->p->L[i] = (i + 6);
	a->p->p->L[2] = NULL;
	a->p->p->p = nullptr;

	list *b, *c, *d;
	b = a;
	c = a->copy();
	d = a->deepcopy();
	return 0;
}
