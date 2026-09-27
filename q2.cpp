#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of passengers: ";
    cin >> n;
    string* p = new string[n];

    cout << "Enter passenger names:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << "\nBoarding sequence:\n";

    for (int i = n - 1; i >= 0; i--)
    {
        cout << p[i] << endl;
    }

    delete[] p;

    return 0;
}