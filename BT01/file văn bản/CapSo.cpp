#include <iostream>
using namespace std;
#define FI "CapSo.INP"
#define FO "CapSo.OUT"
#define maxn 100 

void Process() {
    FILE* fi = fopen(FI, "rt");
    FILE* fo = fopen(FO, "wt");

    if (fi == NULL) {
        cout<<"Khong the doc file \n";
        return;
    }
    if (fo == NULL) {
        cout<<"Khong the ghi file \n";
        fclose(fi);
        return;
    }

    int n, k, a[maxn], found = 0;
    fscanf(fi, "%d %d", &n, &k);  

    for (int i = 0; i < n; i++) {
        fscanf(fi, "%d", &a[i]);
    }
    fclose(fi);

   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == k) {
                fprintf(fo, "%d %d\n", a[i], a[j]); 
                found = 1;
            }
        }
    }

    
    if (!found) {
        fprintf(fo, "0\n");
    }

    fclose(fo);
}

int main() {
    Process();
    cout<<"complete";
    return 0;
}
