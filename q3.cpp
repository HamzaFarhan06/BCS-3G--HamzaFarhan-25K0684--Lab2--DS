#include <iostream>
#include <string>
using namespace std;

int main()
{
    int cap = 3;
    int n = 0;
    string* a = new string[cap];

    for (int i = 0; i < 7; i++)
    {
        string x;
        cout << "Enter item " << i + 1 << ": ";
        cin >> x;
        if (n == cap)
        {
            int nc = cap * 2;
            cout << "Resize triggered: " << cap << " -> " << nc << endl;
            string* t = new string[nc];
            for (int j = 0; j < n; j++)
            {
                t[j] = a[j];
            }
            delete[] a;
            a = t;
            cap = nc;
        }
        a[n] = x;
        n++;
    }
    cout << "\nCart items:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    delete[] a;
    return 0;
}