#include<iostream>
using namespace std;
struct node {
	int info;
	node* left;
	node* right;
};
typedef struct node NODE;
typedef NODE* TREE;

void init(TREE& root) {
	root = NULL;
}

void displayNode(node* p, int i,string prefix) {
	for(int j=0;j<i;j++)
		cout << " ";
	cout << prefix << p->info << endl;
}

node* CreateNode(int x) {
	node* p = new node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void createTree(TREE& p, int a[], int &n,int &i) {
	if (i < n) {
		if (a[i] == 0) {
			p = NULL;
		}
		else {
			p = CreateNode(a[i]); //N
			i++;
			createTree(p->left, a, n, i); //L
			i++;
			createTree(p->right, a, n, i); //R
		}
	}
	
}

void destroyTree(TREE& p)
{
	if (p != NULL)
	{
		destroyTree(p->left);
		destroyTree(p->right);
		node* q = p;
		delete q;
		p = NULL;
	}
}

void PreOrder(TREE root, int i,string prefix) {
	if (root != NULL) {
		displayNode(root, i,prefix);
		PreOrder(root->left,i+3,"L:");
		PreOrder(root->right,i+3,"R:");
	}
}

void inOrder(TREE& root, int i,string prefix)
{
	if (root != NULL)
	{
		inOrder(root->left, i + 3,"L: ");	// L
		displayNode(root, i,prefix);			// N
		inOrder(root->right, i + 3,"R: ");	// R
	}
}

void postOrder(TREE& root, int i,string prefix)
{
	if (root != NULL)
	{
		postOrder(root->left, i + 3,"L: ");	// L
		postOrder(root->right, i + 3,"R: "); // R
		displayNode(root, i,prefix);			// N
	}
}

void RNL(TREE& root, int i, string prefix)
{
	if (root != NULL)
	{
		RNL(root->right, i + 3, "R: "); // R
		displayNode(root, i, prefix);			// N
		RNL(root->left, i + 3, "L: ");	// L
		
	}
}
int CountNode(TREE root) {
	if (root == NULL) return 0;
	int a = CountNode(root->left);
	int b = CountNode(root->right);
	return (a + b + 1);
}
int SumNode(TREE root) {
	if (root == NULL) return 0;
	int a = SumNode(root->left);
	int b = SumNode(root->right);
	return (a + b + root->info);
}
float AVGNode(TREE root) {
	return (float) SumNode(root) / CountNode(root);
}

int DemDuong(TREE root) {
	if (root == NULL)return 0;
	int a = DemDuong(root->left);
	int b = DemDuong(root->right);
	if (root->info > 0) 
		return (a + b + 1);
		return (a + b);
	
}
int DemAm(TREE root) {
	if (root == NULL)return 0;
	int a = DemAm(root->left);
	int b = DemAm(root->right);
	if (root->info < 0) 
		return a + b + 1;
		return a + b;
	
}

int SumDuong(TREE root) {
	if (root == NULL)return 0;
	int a = SumDuong(root->left);
	int b = SumDuong(root->right);
	if (root->info > 0) 
		return( a + b + root->info);
		return (a + b );
	
}

int SumAm(TREE root) {
	if (root == NULL)return 0;
	int a = SumAm(root->left);
	int b = SumAm(root->right);
	if (root->info < 0) 
		return (a + b + root->info);
		return (a + b);
	
}

float AVG_Duong(TREE root) {
	return (float)SumDuong(root) / DemDuong(root);
}

float AVG_Am(TREE root) {
	return (float)SumAm(root) / DemAm(root);
}

void swap(TREE root) {
	if (root == NULL)return;
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
	temp = root->left->left;
	root->left->left = root->left->right;
	root->left->right = temp;
}

node* Min(TREE root) {
	if (root == NULL) return NULL;
	node* ans = root;
	while (ans->left)
		ans = ans->left;
	return ans;
}
int DemCon(TREE root) {
	if (root == NULL) return 0;
	if ((root->left && !root->right) || (!root->left && root->right))
		return 1 + DemCon(root->left) + DemCon(root->right);
	return DemCon(root->left) + DemCon(root->right);
}
void LNR(TREE t, FILE* f) {
	if (t != NULL) {
		LNR(t->left, f);
		fprintf(f, "%d ", t->info);
		LNR(t->right, f);
	}
}
void NLR(TREE t, FILE* f) {
	if (t != NULL) {
		fprintf(f, "%d ", t->info);
		NLR(t->left, f);
		NLR(t->right, f);
	}
}
void LRN(TREE t, FILE* f) {
	if (t != NULL) {
		LRN(t->left, f);
		LRN(t->right, f);
		fprintf(f, "%d ", t->info);
	}
}
int output(const char* filename, TREE t) {
	FILE* f = fopen(filename, "wb");
	if (f == NULL) return 0;
	LRN(t, f);//LRN(t, f);  LNR(t, f); NLR(t, f);
	fclose(f);
}
void test1() {
	int a[] = { 10,5,3,0,0,9,7,0,0,0,15,12,0,0,18,0,20,0,0 };
	int n = sizeof(a) / sizeof(int);
	int i = 0;
	TREE root;
	init(root);
	createTree(root, a, n, i);
	//NLR
	cout << "NLR: " << endl;
	PreOrder(root, 0,"Root: ");
	cout << endl;
	
	//LNR
	cout << "LNR: " << endl;
	inOrder(root, 0,"Root: ");
	cout << endl;
	//LRN
	cout << "LRN: " << endl;
	postOrder(root, 0,"Root: ");
	cout << endl;
	//RLN
	cout << "RNL: " << endl;
	RNL(root, 0, "Root: ");
	cout << endl;
}

void test2() {
	int a[] = { 10,5,3,0,0,9,7,0,0,0,15,12,0,0,18,0,20,0,0 };
	int n = sizeof(a) / sizeof(int);
	int i = 0;
	TREE root;
	init(root);
	createTree(root, a, n, i);
	cout << "PreOrder: " << endl;
	PreOrder(root, 0,"Root: ");
	cout << endl;
	cout << "=====================================================\n";
	cout << "Left Node : " << CountNode(root->left) << endl;
	cout << "Right Node: " << CountNode(root->right) << endl;
	cout << "=====================================================\n";
	cout << "Count Node: " << CountNode(root) << endl;
	cout << "Sum Node: " << SumNode(root) << endl;
	cout << "AVG Node: " << AVGNode(root) << endl;
	cout << "Node duong: " << DemDuong(root) << endl;
	cout << "Tong node duong: " << SumDuong(root) << endl;
	cout << "AVG Node(-): " << AVG_Duong(root) << endl;
	cout << "Node am: " << DemAm(root) << endl;
	cout << "Tong node am: " << SumAm(root) << endl;
	cout << "AVG Node(-): " << AVG_Am(root) << endl;
}

void test3() {
	int a[] = { 10,5,-3,0,0,9,-7,0,0,0,15,-12,0,0,18,0,-20,0,0 };
	int n = sizeof(a) / sizeof(int);
	int i = 0;
	TREE root;
	init(root);
	createTree(root, a, n, i);
	cout << "PreOrder: " << endl;
	PreOrder(root, 0, "Root: ");
	cout << endl;
	cout << "=====================================================\n";
	cout << "Tong node am: " << SumAm(root) << endl;
	cout << "Tong node duong: " << SumDuong(root) << endl;
	cout << "Ti so a/b (a: tong node duong, b: tong node am): " << (float)SumDuong(root) / SumAm(root) << endl;
}


void test4() {
	int a[] = { 10,5,3,0,0,9,7,0,0,0,15,12,0,0,18,0,20,0,0 }; 
	int n = sizeof(a) / sizeof(int);
	int i = 0;
	TREE root;
	init(root);
	createTree(root, a, n, i);
	cout << "PreOrder: " << endl;
	PreOrder(root, 0, "Root: ");
	cout << endl;
	cout << "=====================================================\n";
	cout << "PreOrder(swap): " << endl;
	swap(root);
	PreOrder(root, 0, "Root: ");
	cout << endl;
}


void test5() {
	int a[] = { 10,5,3,0,0,9,7,0,0,0,15,12,0,0,18,0,20,0,0 }; 
	int n = sizeof(a) / sizeof(int);
	int i = 0;
	TREE root;
	init(root);
	createTree(root, a, n, i);
	cout << "PostOrder: " << endl;
	postOrder(root, 0, "Root: ");
	cout << endl;
	cout << "=====================================================\n";
}
void test6() {
	int a[] = { 10,5,3,0,0,9,7,0,0,0,15,12,0,0,18,0,20,0,0 };
	int n = sizeof(a) / sizeof(int);
	int i = 0;
	TREE root;
	init(root);
	createTree(root, a, n, i);
	cout << "PreOrder: " << endl;
	PreOrder(root, 0, "Root: ");
	cout << endl;
	cout << "=====================================================\n";
	cout << "Min: " << Min(root)->info << endl;
}
void test7() {
	int a[] = { 10,5,3,0,0,9,7,0,0,0,15,12,0,0,18,0,20,0,0 }; 
	int n = sizeof(a) / sizeof(int);
	int i = 0;
	TREE root;
	init(root);
	createTree(root, a, n, i);
	cout << "PreOrder: " << endl;
	PreOrder(root, 0, "Root: ");
	cout << endl;
	cout << "=====================================================\n";
	cout << "So nut co 1 nhanh con: " << DemCon(root) << endl;
}
void test8() {
	int a[] = { 10,5,3,0,0,9,7,0,0,0,15,12,0,0,18,0,20,0,0 };
	int n = sizeof(a) / sizeof(int);
	int i = 0;
	TREE root;
	init(root);
	createTree(root, a, n, i);
	output("data.out()", root);
}

int main() {
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	return 0;
}