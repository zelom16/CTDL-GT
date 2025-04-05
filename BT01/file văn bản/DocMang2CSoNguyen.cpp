#include<iostream>
#define maxn 100
#define maxm 100
#define FI "MangSo.inp"
using namespace std;
void inputData(int a[maxn][maxm],int &n, int &m) {
	FILE* fi;
	fi = fopen(FI, "rt");
	if (FI == NULL) {
		cout << "khong doc duoc file";
		return;
	}
	fscanf(fi, "%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fi, "%d", &a[i][j]);
		}
	}
	fclose(fi);
}
void outputData(int a[maxn][maxm], int n, int m) {
	cout << n << " " << m<<endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
}
int main() {
	int n,m;
	int a[maxn][maxm];
	inputData(a, n, m);
	outputData(a, n, m);
	return 0;
}