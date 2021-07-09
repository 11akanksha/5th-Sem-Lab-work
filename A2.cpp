#include <iostream>
using namespace std;

void swap_ele(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //reverse the array
    int i = 0, j = n - 1;
    while (j > i)
    {
        swap_ele(&a[i], &a[j]);
        i++;
        j--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}