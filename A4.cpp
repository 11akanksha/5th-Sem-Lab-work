#include <iostream>
using namespace std;

//TC=O(N)
long power(int a, int n)
{
    if (n == 0)
        return 1;
    else
        return a * power(a, n - 1);
}

int main()
{
    int x;
    unsigned int y;
    cout << "Enter 2 numbers : " << endl;
    cin >> x >> y;
    cout << power(x, y);
    return 0;
}