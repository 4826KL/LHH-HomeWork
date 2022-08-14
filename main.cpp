#include "MaxHeap.h"
using namespace std;
int main()
{
    int a[] = { 48, 26, 70, 45, 20, 52 };
    int i;
    int len = sizeof(a) / sizeof(a[0]);
    MaxHeap* heap = new MaxHeap();
    cout << "Add Data:";
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
        heap->insert(a[i]);
    }
    cout << endl;

    cout << "MaxHeap:";
    heap->printHeap();
    cout << endl;

    i = 71;
    heap->insert(i);
    cout << "Add Data:" << i << endl;
    cout << "MaxHeap:";
    heap->printHeap();
    cout << endl;

    i = 52;
    heap->remove(i);
    cout << "remove Data:" << i << endl;
    cout << "MaxHeap:";
    heap->printHeap();
    cout << endl;
    return 0;
}