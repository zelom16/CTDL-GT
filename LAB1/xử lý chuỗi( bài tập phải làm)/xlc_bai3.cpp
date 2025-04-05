#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000  

void insert(char str[], char c, int k) {
    int len = strlen(str);
    // Dịch các ký tự từ vị trí k sang phải 
    for (int i = len; i >= k; i--) {
        str[i + 1] = str[i];
    }
    // Chèn ký tự vào vị trí k
    str[k] = c;
}

int main() {
    char s[MAX], c;
    int k;
    cout<<"Moi ban nhap chuoi s: ";
    cin>>s;
    cout<<"Moi ban nhap vi tri can chen: ";
    cin>>k;
    cout<<"Moi ban nhap ky tu chen : ";
    cin>>c; 
    insert(s, c, k);
    cout<<"Chuoi sau khi them ky tu:"<<s ;
    return 0;
}
