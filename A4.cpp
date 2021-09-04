#include <iostream>
using namespace std;

//Priority Queue
//Priority : Smaller the no,higher the priority
//Hence we'll use min heap.
int n;
void build_min_heap(int *a, int i)
{

    int p = (i - 1) / 2;

    if (p >= 0 && a[i] < a[p])
    {
        int t = a[p];
        a[p] = a[i];
        a[i] = t;
        build_min_heap(a, (i - 1) / 2);
    }
}

void Build_Q(int *a)
{
    for (int i = n - 1; i >= 0; i--)
    {
        build_min_heap(a, i);
    }
}

void min_heapify(int *a, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int mini = i;
    if (l < n && a[l] < a[mini])
    {
        mini = l;
    }
    if (r < n && a[r] < a[mini])
    {
        mini = r;
    }
    if (mini != i)
    {
        int temp = a[mini];
        a[mini] = a[i];
        a[i] = temp;
        min_heapify(a, mini);
    }
}

void deQ(int *a)
{
    cout << "Element dequeued : " << a[0] << endl;
    a[0] = a[n - 1];
    n--;
    int mini = 0;
    if (a[mini] > a[1])
    {
        mini = 1;
    }
    if (a[mini] > a[2])
    {
        mini = 2;
    }
    if (mini != 0)
    {
        for (int i = 0; i < n; i++)
        {
            min_heapify(a, i);
        }
    }
}

int main()
{
    cout << "----Min priority Queue----\n";
    int *a = new int[20];
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Build_Q(a);
    cout << "Enqueued all the elements.\nPriority queue is ready!\n\n";
    bool to_deQ;
    cout << "Want to dequeue?\n";
    cout << "Enter 1 for yes and 0 otherwise\n";
    cin >> to_deQ;
    while (to_deQ)
    {
        if (n == 0)
        {
            cout << "Queue is empty.\n";
            break;
        }
        deQ(a);
        cout << "Want to dequeue again?\n(1 : Yes,0 : No)\n";
        cin >> to_deQ;
    }
    delete[] a;
    return 0;
}