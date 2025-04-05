#include <iostream>
#include <cmath>
using namespace std;
void giaiPTBacHai(double a, double b, double c, double* x1, double* x2, int* soNghiem) {
    double delta = b * b - 4 * a * c;
    if (delta > 0) {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
        *soNghiem = 2; 
    }
    else if (delta == 0) {
        *x1 = *x2 = -b / (2 * a);
        *soNghiem = 1; 
    }
    else {
        *soNghiem = 0; 
    }
}
int main() {
    double a, b, c, x1, x2;
    int soNghiem;
    cout << "Moi ban nhap he so a, b, c: ";
    cin >> a >> b >> c;
    if (a == 0) {
        cout << "Khong phai phuong trinh bac hai!" << endl;
        return 0;
    }
    giaiPTBacHai(a, b, c, &x1, &x2, &soNghiem);
    if (soNghiem == 2) {
        cout << "Phuong trinh co 2 nghiem: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (soNghiem == 1) {
        cout << "Phuong trinh co 1 nghiem kep x = " << x1 << endl;
    }
    else {
        cout << "Phuong trinh vo nghiem!" << endl;
    }

    return 0;
}
