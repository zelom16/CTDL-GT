#include<iostream>
#define maxn 100
#define FI "DaySoNguyen.inp"
using namespace std;
void inputData(int a[], int &n)
{
	FILE* fi;
	fi = fopen(FI, "rt");
	if (fi == NULL)
	{
		cout << "khong the doc file";
		return ;
	}
	fscanf(fi, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(fi, "%d", &a[i]);
	}
	fclose(fi);
}
void outputData(int a[], int n) {
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i]<<" ";
	}
}
int main() {
	int n; 
	int a[maxn];
	inputData(a, n);
	outputData(a, n);
	return 0;
}




