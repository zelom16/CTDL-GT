#include<iostream>
using namespace std;
int main() {
	const int k = 1000;
	int cnt[k + 1] = { 0 };
	int nx;
	cin >> nx;
	for (int i = 0; i < nx; i++) {
		int value;
		cin >> value;
		if (cnt[value] == 0)  // số chưa được đánh dấu
			cnt[value] = 1; // đánh dấu xuất hiện trong x
	}

	int ny;
	cin >> ny;
	for (int i = 0; i < ny; i++) {
		 int value;
		cin >> value;
		if (cnt[value] == 1) // đã xuất hiện ở x
			cnt[value] = 2;  // đánh dấu xuất hiện cả x và y

	}

	int nz;
	cin >> nz;
	for (int i = 0; i < nz; i++) {
		int value;
		cin >> value;
		if (cnt[value] == 2) // đã xuất hiện ở x và y
			cnt[value] = 3; // đánh dấu xuất hiện cả x và y và z
	}

	int ans = 0; 
	for (int i = 0; i <= k; i++) {
		if (cnt[i] == 3) {
			ans++;
		}
	}
	cout << ans << endl;
	for (int i = 0; i <= k; i++) {
		if (cnt[i] == 3)
			cout << i << " ";
	}
	return 0;
}
