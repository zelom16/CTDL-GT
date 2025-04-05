#include<iostream>
#include<string>
using namespace std;
typedef struct SinhVien
{
	string hoten;
	string diachi;
	string lop;
	int khoa;

	//constructor
	SinhVien() {
		hoten = "";
		diachi = "";
		lop = "";
		khoa = 0;
	}

	SinhVien(string ht, string dc, string l, int k) {
		hoten = ht;
		diachi = dc;
		lop = l;
		khoa = k;
	}


	void outputSV() {
		cout << "Ho ten: " << hoten << endl;
		cout << "Dia chi: " << diachi << endl;
		cout << "Lop: " << lop << endl;
		cout << "Khoa: " << khoa << endl;
	}
}SV;


typedef struct ListSV {
	SV info;
	ListSV* next;
}L;

L* phead = NULL;

SV inputSV(int val) {

	SV danhsachSV[10] = {
		SV("Nguyen Van An", "123 Tran Hung Dao", "CNTT01", 2020),
		SV("Tran Thi Bich", "45 Le Loi", "CNTT02", 2021),
		SV("Nguyen Van Teo", "78 Nguyen Trai", "CNTT03", 2019),
		SV("Le Van Cuong", "Nguyen Van Cu", "CNTT01", 2020),
		SV("Pham Thi Dung", "12 Hoang Hoa Tham", "CNTT02", 2022),
		SV("Hoang Van Em", "34 Ly Thuong Kiet", "CNTT03", 2021),
		SV("Vu Thi Gai", "56 Hai Ba Trung", "CNTT01", 2020),
		SV("Nguyen Van Hung", "89 Vo Thi Sau", "CNTT02", 2019),
		SV("Tran Van Ich", "23 Pham Ngu Lao", "CNTT03", 2022),
		SV("Le Thi Kim", "67 Nguyen Hue", "CNTT01", 2021)
	};
	return danhsachSV[val];
}

// 4 hàm so sánh
int sosanhHoten(SV a, SV b) { return a.hoten.compare(b.hoten); }
int sosanhDiachi(SV a, SV b) { return a.diachi.compare(b.diachi); }
int sosanhLop(SV a, SV b) { return a.lop.compare(b.lop); }
int sosanhKhoa(SV a, SV b) { return (a.khoa - b.khoa); }


void init(L*& phead) {
	phead = NULL;
}

bool isEmpty(L* phead) {
	return(phead == NULL);
}

L* createnode(SV x) {
	L* p = new L;
	p->info = x;
	p->next = NULL;
	return p;
}

void showlist(L* phead) {
	if (phead == NULL) {
		cout << "Danh sach rong" << endl;
	}
	else {
		L* p = phead;
		int i = 1;
		while (p != NULL) {
			cout << "\nSinh vien " << i++ << ":" << endl;
			p->info.outputSV();
			p = p->next;
		}
	}
}

void clearlist(L* phead) {
	L* p;
	while (phead != NULL) {
		p = phead;
		phead = p->next;
		delete p;
	}
}

void insertfirst(L*& phead, SV x) {
	L* p = createnode(x);
	p->next = phead;
	phead = p;
}

void insertlast(L*& phead, SV x) {
	L* q = createnode(x);
	if (phead == NULL)
		phead = q;
	else {
		L* p = phead;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = q;
	}
}

void insertorder(L*& phead, SV x) {
	L* q = createnode(x);
	if (phead == NULL || phead->info.khoa > x.khoa) {
		q->next = phead;
		phead = q;
	}
	else {
		L* p = phead;
		L* r = p;
		while (p != NULL && p->info.khoa < x.khoa) {
			r = p;
			p = p->next;
		}
		q->next = p;
		r->next = q;
	}
}

L* remove(L*& phead, string hoten, string diachi) {
	L* tp = NULL;  
	L* p = phead;  
	while (p != NULL) {
		if (p->info.hoten == hoten || p->info.diachi == diachi) {
			if (p == phead) {
				phead = p->next;
				delete p;
				p = phead;
			}
			else {
				tp->next = p->next;
				delete p;
				p = tp->next;
			}
		}
		else {
			tp = p;
			p = p->next;
		}
	}
	return phead;
}


void insertlist(L*& phead, L* phead1) {
	if (phead == NULL) {
		phead = phead1;
	}
	else {
		L* p = phead;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = phead1;
	}
}



void selectionsort(L*& phead, int (*compare)(SV, SV)) {
	if (phead == NULL) return;
	L* p = phead;
	while (p != NULL) {
		L* min = p;
		L* q = p->next;
		while (q != NULL) {
			if (compare(min->info, q->info) > 0) {
				min = q;
			}
			q = q->next;
		}
		if (min != p) {
			SV temp = p->info;
			p->info = min->info;
			min->info = temp;
		}
		p = p->next;
	}
}


void test() {
	init(phead);
	cout << "Danh sach bao gom 10SV ";
	for (int i = 0; i < 10; i++) {
		SV sv = inputSV(i);
		insertlast(phead, sv);
	}
	showlist(phead);
	cout << endl;
	
	cout << "-----------------------------------------\n";
	//xoa Teo & nguoi co dia chi Nguyen Van CU
	cout << "Danh sach sau khi xoa: " << endl;
	remove(phead, "Nguyen Van Teo", "");
	remove(phead, "", "Nguyen Van Cu");
	showlist(phead);
	cout << endl;
	cout << "-----------------------------------------\n";
	//themSV
	cout << "Danh sach sau khi them" << endl;
	SV newSV("Tran Thi Mo", "25 Hong Bang", "TT0901", 2009);
	insertlast(phead, newSV);
	showlist(phead);
	cout << endl;
	cout << "-----------------------------------------\n";
    //Sap xep
	cout << "Sap xep theo khoa: " << endl;
	selectionsort(phead, sosanhKhoa);
	showlist(phead);
	clearlist(phead);

}
int main() {
	test();
	return 0;
}