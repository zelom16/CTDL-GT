#include<iostream>
//#include<string>
using namespace std;


struct StackInt {
    int* a;
    int size;
    int top;
    int count;
};


void InitStack(StackInt& s, int size) {
    s.size = size;
    s.a = new int[s.size];
    s.top = -1;
    s.count = 0;
}


bool IsEmpty(StackInt s) {
    return s.top == -1;
}


bool IsFull(StackInt s) {
    return s.top == s.size - 1;
}


void Push(StackInt& s, int x) {
        s.top++;
        s.a[s.top] = x;
        s.count++;
}


int Pop(StackInt& s) {  
        int x = s.a[s.top];
        s.top--;
        s.count--;
        return x;
}


int Peek(StackInt s) {
        return s.a[s.top];
}


void Delete(StackInt& s) {
    s.top = -1;
    s.count = 0;
    s.size = 0;
	delete[] s.a;
}

//(b)
void reverseNum(StackInt& s, int num) {
    while (num > 0) {
        int r = num % 10;
        Push(s, r);
        num = num / 10;
    }
    cout << "So dao: ";
    Pop(s);
    cout << endl;
    for (int i = 0; i < s.size; i++) {
        cout << s.a[i];
    }
    Delete(s);
}

// (c) 
struct StackString {
    char* a;
    int size;
    int top;
    int count;
};

void InitStackString(StackString& s, int size) {
    s.size = size;
    s.a = new char[s.size];
    s.top = -1;
    s.count = 0;
}

bool IsEmptyString(StackString s) {
    return s.top == -1;
}

bool IsFullString(StackString s) {
    return s.top == s.size - 1;
}

void PushString(StackString& s, char x) {
   
        s.top++;
        s.a[s.top] = x;
        s.count++;
   
}

char PopString(StackString& s) {
        char x = s.a[s.top];
        s.top--;
        s.count--;
        return x;
    return '\0';
}

void DeleteString(StackString& s) {

    s.top = -1;
    s.count = 0;
    s.size = 0;
    delete[] s.a;
}

bool ChuoiCx(string str) {
    StackString s;
    int len = str.length();
    InitStackString(s, len);

    
    for (int i = 0; i < len / 2; i++) {
        PushString(s, str[i]);
    }

    
    int start;
    if (len % 2 == 0) {
        start = len / 2;       
    }
    else {
        start = len / 2 + 1;    
    }


    for (int i = start; i < len; i++) {
        if (str[i] != PopString(s)) {
            DeleteString(s);
            return false;
        }
    }
    DeleteString(s);
    return true;
}

// (d) 
void decimalToBinary(StackInt& s, int num) {
    while (num > 0) {
        Push(s, num % 2);
        num /= 2;
    }
    cout << "Dang nhi phan: ";
    while (!IsEmpty(s)) {
        cout << Pop(s);
    }
    cout << endl;
    Delete(s);
}

// (e) 
int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}
//trung tố -> hậu tố 
string trans(string infix) {
    StackString s;
    InitStackString(s, infix.length());
    string postfix = "";

    for(int i=0;i<infix.length();i++)
     {
        char c = infix[i];
        if (isdigit(c)) {
            postfix += c;
        }
        else if (c == '(') {
            PushString(s, c);
        }
        else if (c == ')') {
            while (!IsEmptyString(s) && s.a[s.top] != '(') {
                postfix += PopString(s);
            }
            PopString(s); 
        }
        else {
            while (!IsEmptyString(s) && priority(s.a[s.top]) >= priority(c)) {
                postfix += PopString(s);
            }
            PushString(s, c);
        }
    }

    while (!IsEmptyString(s)) {
        postfix += PopString(s);
    }
    DeleteString(s);
    return postfix;
}

int calculate(string postfix) {
    StackInt s;
    InitStack(s, postfix.length());

    for (char c : postfix) {
        if (isdigit(c)) {
            Push(s, c - '0');
        }
        else {
            int b = Pop(s);
            int a = Pop(s);
            switch (c) {
            case '+': Push(s, a + b); break;
            case '-': Push(s, a - b); break;
            case '*': Push(s, a * b); break;
            case '/': Push(s, a / b); break;
            }
        }
    }
    int result = Pop(s);
    Delete(s);
    return result;
}

void test1() {
    StackInt s;
    InitStack(s, 5);
    cout << "Test dao so:" << endl;
    reverseNum(s, 12345);
}

void test2() {
    cout << "\nTest doi xung:" << endl;
    cout << "radar: ";
	if (ChuoiCx("radar"))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
    cout << "hello: ";
	if (ChuoiCx("hello"))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

void test3() {
    StackInt s;
    InitStack(s, 10);
    cout << "\nTest thap phan sang nhi phan:" << endl;
    decimalToBinary(s, 13);
}

void test4() {
    cout << "\nTest bieu thuc:" << endl;
    string infix = "3*(4+5)-6";
    string postfix = trans(infix);
    cout << "Trung to: " << infix << endl;
    cout << "Hau to: " << postfix << endl;
    cout << "Ket qua: " << calculate(postfix) << endl;
}
int main() {
    test1();
    test2();
    test3();
	test4();
   return 0;
}