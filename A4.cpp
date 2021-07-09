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
    int r, c;
    cin >> r >> c;

    //creating 2d array in the heap
    int **a = new int *[r];
    for (int i = 0; i < r; ++i)
        a[i] = new int[c];

    //taking i/p
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    //reversing the 2d array
    int i = 0, j = c - 1;
    while (j > i)
    {
        for (int k = 0; k < r; k++)
        {
            swap_ele(&a[k][i], &a[k][j]);
        }
        i++;
        j--;
    }
    cout << "\nOutput:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}