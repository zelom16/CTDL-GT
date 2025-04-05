#include <iostream>
using namespace std;

typedef struct {
    int front;  
    int rear;   
    int count;  
    int size;   
    int* arr;   
} QueueInt;


void Init(QueueInt& q, int size) {
    q.front = q.rear = -1;
    q.count = 0;
    q.size = size;
    q.arr = new int[q.size];
}


void Delete(QueueInt& q) {
    q.front = q.rear = -1;
    q.size = q.count = 0;
    delete[] q.arr;
}


bool IsEmpty(QueueInt& q) {
    return q.front == -1;
}


bool IsFull(QueueInt& q) {
    return ((q.rear - q.front + 1 == q.size) ||
        (q.rear + 1 == q.front));
}


void Push(QueueInt& q, int x) {
    if (IsFull(q)) {
        cout << "Queue is full!" << endl;
        return ;
    }
    if (q.front == -1) {
        q.front = 0;
    }
    q.rear++;
    if (q.rear == q.size) { 
        q.rear = 0;
    }
    q.arr[q.rear] = x;
    q.count++;
 
}


void Pop(QueueInt& q, int& x) {
    if (IsEmpty(q)) {
        cout << "Queue is empty!" << endl;
   
    }
    x = q.arr[q.front];
    if (q.front == q.rear) {
        q.front = -1;
        q.rear = -1;
    }
    else {
        q.front++;
        if (q.front == q.size) {
            q.front = 0;
        }
    }
    q.count--;

}


int Peek(QueueInt& q) {
    if (IsEmpty(q)) {
        cout << "Queue is empty!" << endl;
    }
	return q.arr[q.front];
}


void Clear(QueueInt& q) {
    q.front = q.rear = -1;
    q.count = 0;
}


void DisplayQueue(QueueInt& q) {
    cout << "[";
    if (!IsEmpty(q)) {
        int i = q.front;
        while (i != q.rear) {
            cout << q.arr[i] << " ";
            i = (i + 1) % q.size;
        }
        cout << q.arr[q.rear];
    }
    cout << "]";
}


void ShowQueue(QueueInt& q) {
    cout << "[front=" << q.front << ", rear=" << q.rear << ", cnt=" << q.count << "]: ";
    for (int i = 0; i < q.size; i++) {
        cout << q.arr[i] << " ";
    }
    cout << " -- ";
    DisplayQueue(q);
}

void test() {
    QueueInt q;
    Init(q, 5);
    Push(q, 1);
    Push(q, 2);
    Push(q, 3);
    Push(q, 4);
    Push(q, 5);
    Push(q, 6); // queue day k them duoc
    ShowQueue(q);
	cout << endl;
	int x= Peek(q);
	cout << "Phan tu dau tien la: " << x << endl;
    Delete(q);
}

int main() {
	test();
    return 0;
}