#include <iostream>
using namespace std;

int flag = 0;

void print_arr(int *a, int n)
{
    cout << "The array is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void build_max_heap(int *a, int i, int s)
{
    int p = (i - 1) / 2;

    if (p >= 0 && a[i] > a[p])
    {
        int t = a[p];
        a[p] = a[i];
        a[i] = t;
        build_max_heap(a, (i - 1) / 2, s);
    }
}

void del_max_heap(int *a, int n)
{
    int s = n;
    while (s > 0)
    {
        int t = a[0];
        a[0] = a[s - 1];
        a[s - 1] = t;
        s--;
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
            for (int i = 0; i < s; i++)
            {
                build_max_heap(a, i, s);
            }
        }
    }
}

void heap_sort_asc(int *a, int n)
{
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        build_max_heap(a, i, n);
    }
    del_max_heap(a, n);
}

void build_min_heap(int *a, int i, int s)
{
    int p = (i - 1) / 2;

    if (p >= 0 && a[i] < a[p])
    {
        int t = a[p];
        a[p] = a[i];
        a[i] = t;
        build_min_heap(a, (i - 1) / 2, s);
    }
}

void del_min_heap(int *a, int n)
{
    int s = n;
    while (s > 0)
    {
        int t = a[0];
        a[0] = a[s - 1];
        a[s - 1] = t;
        s--;
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
            for (int i = 0; i < s; i++)
            {
                build_min_heap(a, i, s);
            }
        }
    }
}

void heap_sort_desc(int *a, int n)
{
    flag = 1;
    for (int i = 0; i < n; i++)
    {
        build_min_heap(a, i, n);
    }
    del_min_heap(a, n);
}

int main()
{
    int opt = -1;
    int *a = new int[100];
    while (opt != 0)
    {
        cout << "-----------------------------------\n";
        cout << "Select what you want to do :\n";
        cout << "0. Quit\n1. Create an array\n";
        cout << "2. Display the array\n3. Sort in asc order\n";
        cout << "4. Sort in desc order\n5. Extract largest element\n";
        cout << "6. Replace value at root\n7. Insert a new element \n";
        cout << "8. Delete an element\n";
        cin >> opt;

        switch (opt)
        {
        case 1:
            int n;
            cout << "Enter no of elements: " << endl;
            cin >> n;
            cout << "Enter elements: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            break;

        case 2:
            print_arr(a, n);
            break;

        case 3:
            heap_sort_asc(a, n);
            print_arr(a, n);
            break;
        case 4:
            heap_sort_desc(a, n);
            print_arr(a, n);
            break;

        case 5:
            cout << "Largest element is : ";
            if (flag == 0)
            {
                //a is in asc order
                cout << a[n - 1] << endl;
            }
            else
            {
                //a is in desc order
                cout << a[0] << endl;
            }
            break;

        case 6:
            cout << "Enter a new value : ";
            int ele;
            cin >> ele;
            if (flag == 0)
            {
                //a used max heap
                cout << "----Maintaining the asc order of array----\n";
                a[0] = ele;
                build_max_heap(a, 0, n);
                heap_sort_asc(a, n);
                cout << "In asc order ";
                print_arr(a, n);
            }
            else
            {
                //a used min heap
                cout << "----Maintaining the desc order of array----\n";
                a[0] = ele;
                build_min_heap(a, 0, n);
                heap_sort_desc(a, n);
                cout << "In desc order ";
                print_arr(a, n);
            }
            break;

        case 7:
            cout << "Enter Element to insert: " << endl;
            int e;
            cin >> e;
            n++;
            a[n - 1] = e;
            if (flag == 0)
            {
                //a used max heap
                cout << "----Maintaining the asc order of array----\n";
                if (e < a[((n - 1) - 1) / 2])
                {
                    heap_sort_asc(a, n);
                    print_arr(a, n);
                }
                else
                {
                    for (int i = 0; i < n / 2; i++)
                    {
                        build_max_heap(a, i, n);
                    }
                    heap_sort_asc(a, n);
                    print_arr(a, n);
                }
            }
            else
            {
                //a used min heap
                cout << "----Maintaining the desc order of array----\n";
                if (e > a[((n - 1) - 1) / 2])
                {
                    heap_sort_desc(a, n);
                    print_arr(a, n);
                }
                else
                {
                    for (int i = 0; i < n / 2; i++)
                    {
                        build_min_heap(a, i, n);
                    }
                    heap_sort_desc(a, n);
                    print_arr(a, n);
                }
            }
            break;
        case 8:
            a[0] = a[n - 1];
            n--;
            if (flag == 0)
            {
                //a used max heap
                cout << "----Maintaining the asc order of array----\n";
                if (a[0] > a[1] && a[0] > a[2])
                {
                    heap_sort_asc(a, n);
                    print_arr(a, n);
                }
                else
                {
                    for (int i = 0; i < n / 2; i++)
                    {
                        build_max_heap(a, i, n);
                    }
                    heap_sort_asc(a, n);
                    print_arr(a, n);
                }
            }
            else
            {
                //a used min heap
                cout << "----Maintaining the desc order of array----\n";
                if (a[0] < a[1] && a[0] < a[2])
                {
                    heap_sort_desc(a, n);
                    print_arr(a, n);
                }
                else
                {
                    for (int i = 0; i < n / 2; i++)
                    {
                        build_min_heap(a, i, n);
                    }
                    heap_sort_desc(a, n);
                    print_arr(a, n);
                }
            }
            break;
        default:
            if (opt != 0)
            {
                cout << "Wrong option chosen.Try again!\n";
            }
        }
    }
    delete[] a;
    return 0;
}