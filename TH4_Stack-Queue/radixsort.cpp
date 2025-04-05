#include <iostream>
using namespace std;

typedef struct
{
    int front; // dau hang doi
    int rear;  // cuoi hang doi
    int count; // so luong phan tu
    int size;  // kich thuoc mang
    int* arr;  // du lieu mang
} Queue;

void Init(Queue& q, int size)
{
    q.front = q.rear = -1;
    q.count = 0;
    q.size = size;
    q.arr = new int[q.size];
}
void Delete(Queue& q)
{
    q.front = q.rear = -1;
    q.size = q.count = 0;
    delete[] q.arr;
}

bool IsEmpty(Queue& q)
{
    return q.front == -1;
}

bool IsFull(Queue& q)
{
    return ((q.rear - q.front + 1 == q.size) ||
        (q.rear + 1 == q.front));
}

void Enqueue(Queue& q, int x)
{
    if (q.front == -1)
        q.front = 0;
    q.rear++;
    if (q.rear == q.size)// quay vong
        q.rear = 0;
    q.arr[q.rear] = x;
    q.count++;
}

void DisplayQueue(Queue& q)
{
    cout << "[";
    if (q.front != -1)
        for (int i = q.front; i != q.rear; i = (i + 1) % q.size)
            cout << q.arr[i] << " ";
    cout << q.arr[q.rear] << " ";
    cout << "]";
}

void ShowQueue(Queue& q)
{
    cout << "[front=" << q.front << ", rear=" << q.rear << ", cnt=" << q.count << "]: ";
    for (int i = 0; i < q.size; i++)
        cout << q.arr[i] << " ";
    cout << " -- ";
    DisplayQueue(q);
}

int Dequeue(Queue& q)
{
    int x = q.arr[q.front];
    if (q.front == q.rear)
    {
        q.front = -1;
        q.rear = -1;
    }
    else
    {
        q.front++;
        if (q.front == q.size)
            q.front = 0;
    }
    q.count--;
    return x;
}

enum DigitType { ONES = 1, TENS = 10 };


void DisplayArray(int a[] , int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
	cout << endl;
}

void RadixSort(Queue bin[] , int a[] , int n, int digit) {
    int snum;
    for (int i = 0; i < n; i++) {
        if (digit == ONES)
            snum = a[i] % 10;
        else
            snum = a[i] / 10;
        Enqueue(bin[snum], a[i]);
    }
}


void BuildArray(Queue bin [] , int a[] , int n) {
    n = 0;
    for (int i = 0; i <= 9; i++)
        while (bin[i].count > 0) {
            a[n] = Dequeue(bin[i]);
            n++;
        }
}

void testRadixSort() {
    int a[] = { 25, 17, 93, 48, 12, 36, 75, 61 };
    int n = 8;

    cout << "--- Radix Sort Test ---" << endl;

    
    Queue bin[10];
    for (int i = 0; i < 10; i++)
        Init(bin[i], n);

    cout << "Mang ban dau: ";
    DisplayArray(a, n);

 
    RadixSort(bin, a, n, ONES);
    BuildArray(bin, a, n);
    cout << "Sau khi sap xep hang don vi: ";
    DisplayArray(a, n);

    
    RadixSort(bin, a, n, TENS);
    BuildArray(bin, a, n);
    cout << "Sau khi sap xep hang chuc: ";
    DisplayArray(a, n);
   
    for (int i = 0; i < 10; i++)
        Delete(bin[i]);
}

void test1()
{
    int a[] = { 4, 1, 2, 5 }, n = 4, x;
    cout << "--- Test1 ---" << endl;

    Queue q;
    Init(q, 3);

    ShowQueue(q);
    cout << endl;

    if (!IsFull(q))
        Enqueue(q, 4);
    else
        cout << "Hang doi day (full queue)!" << endl;
    ShowQueue(q);
    cout << endl;

    if (!IsFull(q))
        Enqueue(q, 1);
    else
        cout << "Hang doi day (full queue)!" << endl;
    ShowQueue(q);
    cout << endl;

    if (!IsFull(q))
        Enqueue(q, 2);
    else
        cout << "Hang doi day (full queue)!" << endl;
    ShowQueue(q);
    cout << endl;

    if (!IsFull(q))
        Enqueue(q, 3);
    else
        cout << "Hang doi day (full queue)!" << endl;
    ShowQueue(q);
    cout << endl;

    if (!IsEmpty(q)) {
        x = Dequeue(q);
        cout << "Gia tri lay ra la: " << x << "!" << endl;
    }
    else
        cout << "Hang doi bi rong (empty queue)" << endl;
    ShowQueue(q);
    cout << endl;

    if (!IsFull(q))
        Enqueue(q, 5);
    else
        cout << "Hang doi day (full queue)!" << endl;
    ShowQueue(q);
    cout << endl;

    Delete(q);
}

int main()
{
    //test1();
    testRadixSort();
    return 0;
}