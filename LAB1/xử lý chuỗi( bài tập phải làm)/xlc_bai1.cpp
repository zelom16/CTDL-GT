#include <iostream>
#include <string.h>
using namespace std;
#define MAX 1000  
void interchangesort(char str[]) {
    int l = strlen(str);
    for (int i = 0; i < l- 1; i++) {
        for (int j = i + 1; j < l; j++) {
            if (str[i] > str[j]) { 
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char s[MAX];
    cout<<"Moi ban nhap chuoi s:" ;
    cin>>s;
    interchangesort(s);
    cout<<"Chuoi sau khi sap xep: \n"<<s<<endl;
    return 0;
}
