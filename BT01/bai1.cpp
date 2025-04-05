#include <iostream>
#include <cmath>
using namespace std;
int ptbac2(double a, double b, double c, double& x1, double& x2) {
    int sn = -1; 
    if (a == 0) {
        if (b == 0) {
            if (c == 0)
                sn = -1; 
            else
                sn = 0;  
        }
        else { 
            sn = 1;
            x1 = -c / b;
        }
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) sn = 0; 
        else if (delta == 0) {
            sn = 1;
            x1 = -b / (2 * a);
        }
        else {
            sn = 2;
            x1 = (-b - sqrt(delta)) / (2 * a);
            x2 = (-b + sqrt(delta)) / (2 * a);
            if (x1 > x2) {
                double tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
        }
    }
    return sn;
}

int main() {
    double a, b, c;
    int sn;
    double x1, x2;
    cin >> a >> b >> c;
    sn = ptbac2(a, b, c, x1, x2);
    if (sn == -1)
        cout << "Phuong trinh co vo so nghiem";
    else if (sn == 0)
        cout << "Phuong trinh vo nghiem";
    else {
        cout << "Phuong trinh co " << sn << " nghiem\n";
        cout << x1;
        if (sn == 2)
            cout << " " << x2;

        return 0;
    }
}
