#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
    int start, finish, actNo;
};

bool cmp(Activity a1, Activity a2)
{
    return (a1.finish < a2.finish);
}

void Activity_Selection(Activity a[], int n)
{
    sort(a, a + n, cmp);
    cout << "Activity Selected:\n";
    int i = 0;
    cout << "{" << a[i].actNo;
    for (int j = 1; j < n; j++)
    {
        if (a[j].start >= a[i].finish)
        {
            cout << " , " << a[j].actNo;
            i = j;
        }
    }
    cout << "}" << endl;
}

int main()
{
    int n;
    cout << "Enter total no of activities: ";
    cin >> n;
    cout << "Enter activity no. of each activity:" << endl;
    Activity *A = new Activity[n];
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        A[i].actNo = no;
    }
    cout << "Enter start time of each activity:" << endl;
    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        A[i].start = s;
    }
    cout << "Enter end time of each activity:" << endl;
    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        A[i].finish = f;
    }
    Activity_Selection(A, n);
    delete[] A;
    return 0;
}
