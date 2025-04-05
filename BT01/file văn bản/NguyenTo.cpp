#include<iostream>
#define FI "NT.inp"
#define FO "NT.out"
#define maxn 100
#include<cmath>
using namespace std;
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
void interchangesort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap (a[i], a[j]);
		}
	}
}
int isPrime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
			return 0;
		return 1;
	}
}

void Process() {
    FILE* fi = fopen(FI, "rt");
    FILE* fo = fopen(FO, "wt");

    if (fi == NULL) {
        cout<<"Khong the doc file\n";
        return;
    }
    if (fo == NULL) {
        cout<<"Khong the ghi file\n";
        fclose(fi);
        return;
    }

    int n, a[maxn], primes[maxn], primeCount = 0;
    fscanf(fi, "%d", &n);

    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d", &a[i]);
        if (isPrime(a[i])) {
            primes[primeCount++] = a[i];  
        }
    }

   
    interchangesort(primes, primeCount);

    fprintf(fo, "%d\n", primeCount); 
    for (int i = 0; i < primeCount; i++) {
        fprintf(fo, "%d ", primes[i]); 
    }

    fclose(fi);
    fclose(fo);
}

int main() {
    Process();
    cout << "complete";
	return 0;
}