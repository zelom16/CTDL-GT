#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000  
void remove(char str[], int k) {
    int len = strlen(str);
    // Dịch các ký tự phía sau về trước 1 vị trí
    for (int i = k; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = '\0'; 
}

int main() {
    char s[MAX];
    int k;
    cout<<"Moi ban nhap chuoi s : ";
    cin>> s;
    cout<<"Moi ban nhap vi tri can xoa: ";
    cin>>k;
    remove(s, k);
    cout << "Chuoi sau khi xoa \n" << s<<endl;
    return 0;
}
