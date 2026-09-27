#include <iostream>
using namespace std;

int main()
{
    int* a[3];

    a[0] = new int[2];   
    a[1] = new int[4];   
    a[2] = new int[6];  
    for (int i = 0; i < 2; i++)
        a[0][i] = 0;

    for (int i = 0; i < 4; i++)
        a[1][i] = 0;

    for (int i = 0; i < 6; i++)
        a[2][i] = 0;

    int r, s;
    cout << "Enter -1 to exit.\n";
    while (true)
    {
        cout << "\nEnter class (0=First, 1=Business, 2=Economy): ";
        cin >> r;
        if (r == -1)
            break;
        cout << "Enter seat number: ";
        cin >> s;
        if (r < 0 || r > 2)
        {
            cout << "Invalid class!" << endl;
        }
        else if (r == 0 && (s < 0 || s >= 2))
        {
            cout << "Error: First Class has only 2 seat slots!" << endl;
        }
        else if (r == 1 && (s < 0 || s >= 4))
        {
            cout << "Error: Business Class has only 4 seat slots!" << endl;
        }
        else if (r == 2 && (s < 0 || s >= 6))
        {
            cout << "Error: Economy Class has only 6 seat slots!" << endl;
        }
        else if (a[r][s] == 1)
        {
            cout << "Seat already reserved!" << endl;
        }
        else
        {
            a[r][s] = 1;
            cout << "Seat reserved successfully!" << endl;
        }
    }

    delete[] a[0];
    delete[] a[1];
    delete[] a[2];

    return 0;
}