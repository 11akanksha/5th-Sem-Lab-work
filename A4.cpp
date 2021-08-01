#include <iostream>
using namespace std;

int s[100], t;
bool d[1000] = {false};

//sorting function helper:
void swap_ele(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//sorting function
void sort_arr(int *a, int l)
{
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = 0; j < l - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap_ele(&a[j], &a[j + 1]);
            }
        }
    }
}

void insert1(int x)
{
    int k = 0;

    for (int i = 0; i < t; i++)
    {
        if (x != s[i])
        {
            k++;
        }
    }
    if (k == t)
    {
        s[t] = x;
        t++;
    }
    //takes O(n) time
}

void display()
{
    for (int i = 0; i < t; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void removeBottomHalf()
{
    sort_arr(s, t);
    for (int i = t - 1; i >= t / 2; i--)
    {
        s[i] = 0;
    }
    t = t / 2;
    //already takes O(n) time
}

void insert2(int x)
{
    if (d[x] == false)
    {
        s[t] = x;
        d[x] = true;
        t++;
    }
    //takes O(1) time
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    t = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert1(a[i]);
    }
    display();
    removeBottomHalf();
    display();
    t = 0;
    for (int i = 0; i < n; i++)
    {
        insert2(a[i]);
    }
    display();
    removeBottomHalf();
    display();
    delete[] a;
    return 0;
}