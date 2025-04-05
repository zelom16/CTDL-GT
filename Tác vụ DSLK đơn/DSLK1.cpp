#include<iostream>
using namespace std;
typedef struct node
{
	int info;
     node* next;
}node;

node* phead = NULL; // khai báo con trỏ p 

bool isEmpty(node* phead)
{
	return(phead == NULL);
}
void Init(node*& phead) // khởi tạo danh sách rỗng
{
	phead = NULL;
}

node* createNode(int x) //  tạo node mới
{
	node* p = new node;
	p->info = x;
	p -> next = NULL;
	return p;
}

void ShowList(node* phead) // duyệt danh sách liên kết
{
	if (phead == NULL)
	{
		cout << "Danh sach rong" << endl;
	}
	else {
		node* p = phead;
		while (p != NULL) {
			cout << p->info << " ";
			p = p->next;
		}
	}
}

void ClearList(node*& phead) {
	node* p;
	while (phead != NULL) {
		p = phead;
		phead = p -> next;
		delete p;
	}
}
void InsertFirst(node*& phead, int x)
{
	node* p = createNode(x);
	p->next = phead;
	phead = p;
}

void InsertLast(node*& p, int x) {
	if (p != NULL) {
		node* q = createNode(x);
		q->next = p->next;
		p->next = q;
	}
}

void InsertOrder(node*& phead, int x) {
	node* tp;
	node* p = phead;
	bool cont = true;
	while ((p != NULL) && cont) {
		if (p->info < x) {
			tp = p;
			p = p->next;
		}
		else cont = false;
	}
	if (p == phead) 
		InsertFirst(phead, x);
	else 
		InsertLast(tp, x);
	
}

void DeleteFirst(node*&phead) {
	if (isEmpty(phead)) {
		cout << "Danh sach rong" << endl;
	}
	else {
		node* p = phead;
		phead = phead->next;
		delete p;
	}
}

void DeleteLast(node*p) {
	
		if (p == NULL || p->next == NULL) {
			cout << "khong the xoa phan tu nay" << endl;
		}
		else {
			node* q = p->next;
			p->next = q->next;
			delete q;
		}
}

node* remove(node*& phead,int x) {
	node* tp=NULL;
	node* p = phead;
	bool found = false;
	while ((p != NULL) && !found) {
		if (p->info != x) {
			tp = p;
			p = p->next;
		}
		else  found = true;		
	}
	if (found) { 
		if (p == phead) 
			phead = p->next;
		
		else 
			tp->next = p->next;
		
		delete p;
	}
	return phead;
}

void selectionSort(node* phead) {
	node* p, * q, * pmin;
	int vmin;
	for (p = phead; p->next != NULL; p = p->next) {
		vmin = p->info;
		pmin = p;
		for (q = p->next; q != NULL; q = q->next) {
			if (q->info < vmin) {
				vmin = q->info;
				pmin = q;
			}
		}
		pmin->info = p->info;
		p->info = vmin;
	}
}

node* find(node* phead, int x) {
	node* p = phead;
	while (p != NULL) {
		if (p->info == x)
			return p;
		else p = p->next;
	}	
	return NULL;
}

node* findOrder(node* phead, int x) {
	node* p = phead;
	while (p != NULL) {
		if (p->info == x)
			return p;
		else if (p->info < x) 
			p = p->next; // nếu phần tử hiện tại nhỏ hơn x thì tiếp tục duyệt
		else p = NULL;
	}
	return p;
}

void clearlist(node*& phead) {
	node* p;
	while (phead != NULL) {
		p = phead;
		phead = p->next;
		delete p;
	}
}

void interchangeSort(node* phead) {
	if (phead == NULL) return; // Nếu danh sách rỗng, không cần sắp xếp

	node* p = phead;
	while (p != NULL) {
		node* q = p->next;
		while (q != NULL) {
			if (p->info > q->info) {
				// Hoán đổi giá trị của hai node
				int temp = p->info;
				p->info = q->info;
				q->info = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}


/*
void test1()  { 
	cout << "--- TEST1 ---" << endl;
	node* phead;
	int a[] = { 1,2,3,4,5,6 }, n=6;
	Init(phead);
	if (isEmpty(phead)) {
		cout << " Danh sach rong" << endl;
	}
	else {
		cout << " Danh sach da co pha tu" << endl;
	}
}

void test2() {
	cout << "--- TEST1 ---" << endl;
	
	int n = 6, a[] = { 71, 25, 64, 31, 45, 9 };
	node* phead;
	Init(phead);
	cout << "Danh sach: " << endl;
	for (int i = 0; i < n; i++) {
		InsertFirst(phead, a[i]);
	}
	ShowList(phead);
	cout << endl;

	node* phead1;
	Init(phead1);
	InsertFirst(phead1, a[0]);
	node* p = phead1;
	cout << "Danh sach (InsertLast) : " << endl;
	for (int i = 1; i < n; i++) {
		InsertLast(p, a[i]);
		p = p->next;
	}
	ShowList(phead1);
	cout << endl;

	int x = 16;
	node* phead2;
	Init(phead2);
	InsertFirst(phead2, a[0]);
	p = phead2;
	cout << "Danh sach (InsertOrder) : " << endl;
	for (int i = 1; i < n; i++) {
		InsertLast(p, a[i]);
		p = p->next;
	}
	InsertOrder(phead2, x);
	ShowList(phead2);
	cout << endl;
	InsertOrder(phead2, 20);
	cout << "Danh sach (InsertOrder) khi them 20: " << endl;
	ShowList(phead2); 
}



void test3() {
	cout << "--- TEST3 ---" << endl;
	int n = 6, a[] = { 1,2,3,4,5,6 };
	node* phead;
	Init(phead);
	for (int i = 0; i < n; i++) {
		InsertFirst(phead, a[i]);
	}
	cout << "Danh sach luc dau:" << endl;
	ShowList(phead);
	cout << endl;
	ClearList(phead);
	cout << "Danh sach sau khi xoa" << endl;
	if (isEmpty(phead))
		cout << "Danh sach rong" << endl;
	else 
		cout << "Danh sach da co phan tu" << endl;
}

void test4() {
	cout << "--- TEST4 ---" << endl;
	int n = 6, a[] = { 2,4,6,8,10,12 };
	node* phead;
	Init(phead);
	
	cout << "Danh sach luc dau:" << endl;
	for (int i = 0; i < n; i++) {
		InsertFirst(phead, a[i]);
	}
	ShowList(phead);
	cout << endl;
	DeleteFirst(phead);
	cout << "Danh sach sau khi xoa phan tu dau tien" << endl;
	ShowList(phead);
	cout << endl;

	node* phead1;
	Init(phead1);
	cout << "Danh sach luc dau:" << endl;
	for (int i = 0; i < n; i++) {
		InsertFirst(phead1, a[i]);
	}
	ShowList(phead1);
	cout << endl;
	node* p = phead1;
	while (p->next->next != NULL) {
		p = p->next;
	}
	DeleteLast(p);
	cout << "Danh sach sau khi xoa phan tu cuoi cung" << endl;
	ShowList(phead1);
	cout << endl;

	int x = 10;
	node* phead2;
	Init(phead2);
	cout << "Danh sach luc dau:" << endl;
	for (int i = 0; i < n; i++) {
		InsertFirst(phead2, a[i]);
	}
	ShowList(phead2);
	cout << endl;
	remove(phead2, x);
	cout << "Danh sach sau khi xoa phan tu co gia tri " << x << endl;
	ShowList(phead2);
}

void test5() {
	cout << "--- TEST2 ---" << endl;
	int n = 5; int a[] = { 66,88,52,16,99 };
	Init(phead);
	for (int i = 0; i < n; i++)
		InsertFirst(phead, a[i]);
	ShowList(phead);
	cout << endl;
	int x = 10;
	node* ans=find(phead, x);
	if (ans != NULL) 
		cout << "Da tim thay " << x<< endl;
	else
		cout << "Khong tim thay " << x << endl;
	
}

void test6()
{
	cout << "--- TEST6 ---" << endl;
	int a[] = { 2, 5, 4, 2, 1, 8 }, n = 6;

	node* phead = NULL, * p;
	InsertFirst(phead, a[0]); p = phead;
	for (int i = 1; i < n; i++) {
		InsertLast(p, a[i]);
		p = p->next;
	}
	cout<<"Danh sach truoc khi sap xep: ";
	ShowList(phead);
	cout << endl;
	selectionSort(phead);
	cout<<"Danh sach sau khi sap xep: ";
	ShowList(phead);
	cout << endl;
}

void test7() {
	cout << "--- TEST3 ---" << endl;
	int n = 5; int a[] = { 45, 22, 30, 66, 50 };
	Init(phead);
	InsertFirst(phead, a[0]);
	node* p = phead;
	for (int i = 1; i < n; i++) {
		InsertLast(p, a[i]);
		p = p->next;
	}
	ShowList(phead);
	cout << endl;
	int x = 50;
	node*ans=findOrder(phead, x);
	if (ans != NULL)
		cout << "Da tim thay " << x << endl;
	else
		cout << "Khong tim thay " << x << endl;
	
}
void test8() {
	
		cout << "--- TEST2 ---" << endl;
		int n = 6, a[] = { 71, 25, 64, 31, 45, 9 };
		node* phead;
		Init(phead);
		for (int i = 0; i < n; i++) {
			InsertFirst(phead, a[i]);
		}
		if (isEmpty(phead)) 
			cout << " Danh sach rong" << endl;
		
		else 
			cout << " Danh sach da co pha tu" << endl;

}

void test9() {
	cout << "--- TEST1---" << endl;
	int n = 5; int a[] = { 55,33,7,44,66 };
	node* phead;
	Init(phead);
	for (int i = 0; i < n; i++) {
		InsertFirst(phead, a[i]);
	}
	ShowList(phead);
	cout << endl;
	if (isEmpty(phead))
		cout << "Danh sach rong" << endl;
	else
		cout << "Danh sach da co phan tu" << endl;

	cout << "Danh sach sau khi xoa: ";
	ClearList(phead);
	if (isEmpty(phead))
		cout << "Danh sach rong" << endl;
	else
		cout << "Danh sach da co phan tu" << endl;

}

void test10() {
	int n = 3, a[] = { 3,4,5 };
	node* phead2;
	Init(phead2);
	for (int i = 0; i < n; i++) {
		InsertFirst(phead2, a[i]);
	}
	ShowList(phead2);
	cout << endl;
	InsertOrder(phead2, 6);
	cout << "Danh sach (InsertOrder) khi them: " << endl;
	ShowList(phead2);
}

void test() {
	cout << "--- TEST1 ---" << endl;
	int n = 6, a[] = { 62,12,10,4,16,25 };
	node* phead;
	Init(phead);
	for (int i = 0; i < n; i++) {
		InsertFirst(phead, a[i]);
	}
	ShowList(phead);
	cout << endl;
	interchangeSort(phead);
	cout << "Danh sach sau khi sap xep: " << endl;
	ShowList(phead);
	cout << endl;
}*/
int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	// test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	//test();
	return 0;
}
