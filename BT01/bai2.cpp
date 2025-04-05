
#include <iostream>
#include <cmath>
using namespace std;
void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = x;
}
void pttrungphuong(double a, double b, double c, double& x1, double& x2, double &x3, double &x4){
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Phuong trinh co vo so nghiem" << endl;
            }
            else {
                cout << "Phuong trinh vo nghiem" << endl;  
            }
        }
        else {
            double t = -c / b;
            if (t < 0) {
                cout << "Phuong trinh vo nghiem" << endl; 
            }
            else {
                x1 = sqrt(t);
                x2 = -sqrt(t);
                if (x1 > x2) swap(x1, x2);
                cout << "Phuong trinh co 2 nghiem" << endl;
                cout << x1 << " " << x2 << endl;
              
            }
        }
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        }
        else {
            double t1 = (-b + sqrt(delta)) / (2 * a);
            double t2 = (-b - sqrt(delta)) / (2 * a);
            int count = 0;

            if (t1 >= 0) {
                x1 = -sqrt(t1);
                x2 = sqrt(t1);
                count += 2;
            }

            if (t2 >= 0) {
                 x3 = -sqrt(t2);
                 x4 = sqrt(t2);
                count += 2;
            }
            if (x1 > x2)
                swap(x1, x2);
           
            if (x2 > x3)
                swap(x2, x3);

            if (x3 > x4)
                swap(x3, x4);
            cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
            if (count == 0) {
                cout << "Phuong trinh vo nghiem" << endl;
            }
            else {
                cout << "Phuong trinh co " << count << " nghiem" << endl;
            }
        }
       
    }
}

int main() {
    double a, b, c, x1, x2, x3, x4;
    cin >> a >> b >> c;
    pttrungphuong(a, b, c, x1, x2, x3, x4);
   
    return 0;
}

