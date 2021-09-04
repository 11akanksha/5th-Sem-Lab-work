#include <iostream>
using namespace std;

//Priority Queue
//Priority : Larger the no,higher the priority
//Hence we'll use max heap.
int n;
void build_max_heap(int *a, int i)
{

    int p = (i - 1) / 2;

    if (p >= 0 && a[i] > a[p])
    {
        int t = a[p];
        a[p] = a[i];
        a[i] = t;
        build_max_heap(a, (i - 1) / 2);
    }
}

void Build_Q(int *a)
{
    for (int i = 0; i < n; i++)
    {
        build_max_heap(a, i);
    }
}

void max_heapify(int *a, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxi = i;
    if (l < n && a[l] > a[maxi])
    {
        maxi = l;
    }
    if (r < n && a[r] > a[maxi])
    {
        maxi = r;
    }
    if (maxi != i)
    {
        int temp = a[maxi];
        a[maxi] = a[i];
        a[i] = temp;
        max_heapify(a, maxi);
    }
}

void deQ(int *a)
{
    cout << "Element dequeued : " << a[0] << endl;
    a[0] = a[n - 1];
    n--;
    int maxi = 0;
    if (a[maxi] < a[1])
    {
        maxi = 1;
    }
    if (a[maxi] < a[2])
    {
        maxi = 2;
    }
    if (maxi != 0)
    {
        for (int i = 0; i < n; i++)
        {
            max_heapify(a, i);
        }
    }
}

int main()
{
    cout << "----Max priority Queue----\n";
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