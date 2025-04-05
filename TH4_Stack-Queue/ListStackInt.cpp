#include<iostream>
#include<string>
using namespace std;

struct node {
    int info;
    node* next;
};


struct ListStackInt {
    int count;
    node* top;
};


void init(ListStackInt& s) {
    s.top = NULL;
    s.count = 0;
}


node* createnode(int x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}


bool isEmpty(ListStackInt& s) {
    return s.top == NULL;
}

void Delete(ListStackInt& s) {  //
    while (s.top != NULL) {
        node* p = s.top;
        s.top = s.top->next;
        delete p;  
    }
    s.count = 0;
}


void push(ListStackInt& s, int x) {
    node* p = createnode(x);
    p->next = s.top;
    s.top = p;
    s.count++;
}


int pop(ListStackInt& s) {
        int x = s.top->info;
        node* p = s.top;
        s.top = p->next;
        s.count--;
        delete p;
        return x; 
}


int peek(ListStackInt& s) {
    return s.top->info;
}


void print(ListStackInt& s) {
    if (isEmpty(s))
        cout << "STACK RONG!" << endl;
    else {
        cout << "STACK: ";
        node* p = s.top;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->next;
        }
        cout << endl;
    }
}

// (b) Đảo số
void reverseNum(ListStackInt& s, int num) {
    while (num > 0) {
        push(s, num % 10);
        num /= 10;
    }
    cout << "So dao: ";
    while (!isEmpty(s)) {
        cout << pop(s);
    }
    cout << endl;
    Delete(s);
}

// (c) 
struct ListStackChar {
    int count;
    struct nodeChar* top;
};

struct nodeChar {
    char info;
    nodeChar* next;
};

void initChar(ListStackChar& s) {
    s.top = NULL;
    s.count = 0;
}

nodeChar* createnodeChar(char x) {
    nodeChar* p = new nodeChar;
    p->info = x;
    p->next = NULL;
    return p;
}

bool isEmptyChar(ListStackChar& s) {
    return s.top == NULL;
}

void pushChar(ListStackChar& s, char x) {
    nodeChar* p = createnodeChar(x);
    p->next = s.top;
    s.top = p;
    s.count++;
}

char popChar(ListStackChar& s) {
    if (!isEmptyChar(s)) {
        char x = s.top->info;
        nodeChar* p = s.top;
        s.top = p->next;
        s.count--;
        delete p;
        return x;
    }
    return '\0';
}

void DeleteChar(ListStackChar& s) {
    while (s.top != NULL) {
        nodeChar* p = s.top;
        s.top = s.top->next;
        delete p;
    }
    s.count = 0;
}

bool ChuoiCx(string str) {
    ListStackChar s;
    initChar(s);
    int len = str.length();

    for (int i = 0; i < len / 2; i++) {
        pushChar(s, str[i]);
    }

    int start;
    if (len % 2 == 0) {
        start = len / 2;
    }
    else {
        start = len / 2 + 1;
    }

    for (int i = start; i < len; i++) {
        if (str[i] != popChar(s)) {
            DeleteChar(s);
            return false;
        }
    }
    DeleteChar(s);
    return true;
}

// (d)
void decimalToBinary(ListStackInt& s, int num) {
    while (num > 0) {
        push(s, num % 2);
        num /= 2;
    }
    cout << "Dang nhi phan: ";
    while (!isEmpty(s)) {
        cout << pop(s);
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

string trans(string infix) {
    ListStackChar s;
    initChar(s);
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isdigit(c)) {
            postfix += c;
        }
        else if (c == '(') {
            pushChar(s, c);
        }
        else if (c == ')') {
            while (!isEmptyChar(s) && s.top->info != '(') {
                postfix += popChar(s);
            }
            popChar(s); // Bỏ '('
        }
        else {
            while (!isEmptyChar(s) && priority(s.top->info) >= priority(c)) {
                postfix += popChar(s);
            }
            pushChar(s, c);
        }
    }

    while (!isEmptyChar(s)) {
        postfix += popChar(s);
    }
    DeleteChar(s);
    return postfix;
}

int calculate(string postfix) {
    ListStackInt s;
    init(s);

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            push(s, c - '0');
        }
        else {
            int b = pop(s);
            int a = pop(s);
            switch (c) {
            case '+': push(s, a + b); break;
            case '-': push(s, a - b); break;
            case '*': push(s, a * b); break;
            case '/': push(s, a / b); break;
            }
        }
    }
    int result = pop(s);
    Delete(s);
    return result;
}
void test() {
    // Test (b) Đảo số
    ListStackInt s1;
    init(s1);
    cout << "Test dao so:" << endl;
    reverseNum(s1, 12345);

    // Test (c) Đối xứng
    cout << "\nTest doi xung:" << endl;
    cout << "world: ";
    if (ChuoiCx("world"))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << "radar: ";
    if (ChuoiCx("radar"))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    // Test (d) Thập phân sang nhị phân
    ListStackInt s2;
    init(s2);
    cout << "\nTest thap phan sang nhi phan:" << endl;
    decimalToBinary(s2, 13);

    // Test (e) Biểu thức
    cout << "\nTest bieu thuc:" << endl;
    string infix = "3*(4+5)-6";
    string postfix = trans(infix);
    cout << "Trung to: " << infix << endl;
    cout << "Hau to: " << postfix << endl;
    cout << "Ket qua: " << calculate(postfix) << endl;

}
int main() {
     test();
    return 0;
}