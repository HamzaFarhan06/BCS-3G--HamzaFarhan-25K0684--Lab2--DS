#include <iostream>
using namespace std;

void addNewStudent(int**& g, int& n)
{
    int** t = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        t[i] = new int[3];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t[i][j] = g[i][j];
        }
    }

    cout << "\nEnter grades for new student:\n";

    for (int j = 0; j < 3; j++)
    {
        cin >> t[n][j];
    }

    for (int i = 0; i < n; i++)
    {
        delete[] g[i];
    }
    delete[] g;

    g = t;
    n++;
    cout << "\nMemory transition: "
         << n - 1 << " x 3 -> " << n << " x 3\n";
    cout << "New student added successfully.\n";
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int** g = new int*[n];
    for (int i = 0; i < n; i++)
    {
        g[i] = new int[3];
    }
    cout << "Enter grades for " << n << " students:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";

        for (int j = 0; j < 3; j++)
        {
            cin >> g[i][j];
        }
    }
    cout << "\nInitial memory: " << n << " x 3\n";
    addNewStudent(g, n);
    cout << "\nUpdated grades:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";

        for (int j = 0; j < 3; j++)
        {
            cout << g[i][j] << " ";
        }

        cout << endl;
    }
   
    for (int i = 0; i < n; i++)
    {
        delete[] g[i];
    }

    delete[] g;

    return 0;
}