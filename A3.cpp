#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int p = 1;
    for (int i = 0; i < n; i++)
    {
        p *= a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = p / a[i];
    }
    //the result:
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}