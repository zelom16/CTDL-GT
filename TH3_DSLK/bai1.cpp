#include<iostream>
using namespace std;
typedef struct node {
	int info;
	node* next;
}node;

node* phead = NULL;


bool isEmpty(node* phead) {
	return(phead == NULL);
}

void init(node*& phead) {
	phead = NULL;
}

node* createnode(int x) {
	node* p = new node;
	p->info = x;
	p->next = NULL;
	return p;
}

void showlist(node* phead) {
	if (phead == NULL) {
		cout << "Danh sach rong" << endl;
	}
	else {
		node* p = phead;
		while (p != NULL) {
			cout << p->info<<" ";
			p = p->next;
		}
	}
}

void clearlist(node*& phead) {
	node* p;
	while (phead != NULL) {
		p = phead;
		phead = p->next;
		delete p;
	}
}

void insertfirst(node*& phead,int x) {
	node* p = createnode(x);
	p->next = phead;
	phead = p;
}

void insertlast(node*& phead, int x) {
	node* q = createnode(x);
	if (phead == NULL)
		phead = q;
	else {
		node* p = phead;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = q;
	}
	
}
void insertorder(node*& phead, int x) {
	node* tp;
	node* p=phead;
	bool cont = true;
	while ((p != NULL) && cont) {
		if (p->info < x) {
			tp = p;
			p = p->next;
		}
		else cont = false;
	}
	if (p == phead)
		insertfirst(phead, x);
	else
		insertlast(tp, x);
}

void insertlist(node*& phead, node* phead1) {
	if (phead == NULL) {
		phead = phead1;
  }
	else {
		node* p = phead;
		while(p->next !=NULL){
			p = p->next;
		}
		p->next = phead1;
	}
}

node* remove(node*& phead, int x) {
	node* tp = NULL;
	node* p = phead;
	while ((p != NULL)) {
		if (p->info == x) {
			if (p == phead){
				phead = p->next;
			    delete p;
				p = phead;
			}
			else{
				tp->next = p->next;
				delete p;
				p = tp->next;
			}
		}
		else
			tp = p;
		    p = p->next;
	}
	return phead;
}

struct ListINT {
	node* phead;

	
	ListINT() {
		phead = NULL;
	}

};

void test_a() {

	//Test tao danh sach
	ListINT list1;
	//showlist(list1.phead);
	cout << "List 1: ";
	cout << endl;
	//Them phan tu vao danh sach
	insertfirst(list1.phead, 10);
	insertlast(list1.phead, 20);
	insertfirst(list1.phead, 5);
	insertlast(list1.phead, 30);
	cout << "Sau khi them : ";
	showlist(list1.phead);
	//Xoa phan tu trong danh sach
	remove(list1.phead, 5);
	cout << endl << "Sau khi xoa : ";
	showlist(list1.phead);
	cout << endl;
	//Them phan tu 
	insertorder(list1.phead, 5);
	cout << "Sau khi them : ";
	showlist(list1.phead);
	cout << endl;
	//Tao danh sach moi
	ListINT list2;
	cout << "List 2: ";
	cout << endl;
	insertfirst(list2.phead, 16);
	insertlast(list2.phead, 25);
	insertfirst(list2.phead, 15);
	showlist(list2.phead);
	cout << endl;
	//Them danh sach 2 vao danh sach 1
	insertlist(list1.phead, list2.phead);
	list2.phead = NULL;
	showlist(list1.phead);
	//Huy danh sach
	//cout << "Huy danh sach: ";
	clearlist(list1.phead);
	//showlist(list1.phead);
	
}

void test_b() {
	ListINT list1;
	int n = 10;
	int a[] = { 16, 25, 15, 10, 20, 5, 30, 5, 16, 25 };
	cout << "List 1: ";
	for (int i = 0; i < n; i++) {
		insertlast(list1.phead, a[i]);
	}
	showlist(list1.phead);
	cout << endl;
	cout << "Xoa phan tu 5: ";
	remove(list1.phead, 5);
	showlist(list1.phead);
	cout << endl;
	ListINT list2;
	int m = 5;
	int b[] = { 7,18,27,38,50 };
	cout << "List 2: ";
	for (int i = 0; i < m; i++) {
		insertlast(list2.phead, b[i]);
	}
	showlist(list2.phead);
	cout << endl;
	insertlist(list1.phead, list2.phead);
	list2.phead = NULL;
	cout << "List 1 sau khi them List 2: ";
	showlist(list1.phead);
	cout << endl;
}

int main() {
	//test_a();
	test_b();
	return 0;
}