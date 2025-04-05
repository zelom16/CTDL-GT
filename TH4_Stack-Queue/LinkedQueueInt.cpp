#include <iostream>
using namespace std;


typedef struct node {
    int info;
    node* next;
} node;


typedef struct {
    int count;   
    node* front;  
    node* rear;   
} LinkedQueueInt;

// Khởi tạo hàng đợi rỗng
void InitQueue(LinkedQueueInt& q) {
    q.front = q.rear = NULL;
    q.count = 0;
}

// Tạo một nút mới
node* CreateNode(int x) {
    node* p = new node;
    p->info = x;
    p->next = NULL;
    return p;
}

// Kiểm tra hàng đợi rỗng
bool IsEmpty(LinkedQueueInt& q) {
    return q.front == NULL;
}

void Enqueue(LinkedQueueInt& q, int x) {
    node* p = CreateNode(x);
    if (IsEmpty(q)) {
        q.front = q.rear = p;
    }
    else {
        q.rear->next = p;
        q.rear = p;
    }
    q.count++;
}


int Dequeue(LinkedQueueInt& q) {
    if (IsEmpty(q)) {
        cout << "Queue rong!" << endl;
        return -1;
    }
    int x = q.front->info;
    node* p = q.front;
    q.front = q.front->next;
    if (q.front == NULL) {
        q.rear = NULL;
    }
    delete p;
    q.count--;
    return x;
}


int Peek(LinkedQueueInt& q) {
    if (IsEmpty(q)) {
        cout << "Hàng đợi rỗng!" << endl;
        return -1;
    }
    return q.front->info;
}

void ClearQueue(LinkedQueueInt& q) {
    while (!IsEmpty(q)) {
        Dequeue(q);
    }
}

void DisplayQueue(LinkedQueueInt& q) {
    cout << "[";
    node* p = q.front;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << "]";
}


void ShowQueue(LinkedQueueInt& q) {
    cout << "[front=" << q.front << ", rear=" << q.rear << ", cnt=" << q.count << "]: ";
    DisplayQueue(q);
    cout << endl;
}

void test() {
    LinkedQueueInt q;
    InitQueue(q);
    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    ShowQueue(q);

    cout << "Lay phan tu khoi hang doi: " << Dequeue(q) << endl;
    ShowQueue(q);

    cout << "Them phan tu " << endl;
    Enqueue(q, 40);
    Enqueue(q, 50);
    ShowQueue(q);

    cout << "Phan tu dau: " << Peek(q) << endl;
    ClearQueue(q);
    cout << "Sau khi xoa: ";
    ShowQueue(q);
}
int main() {
    test();
    return 0;
}
