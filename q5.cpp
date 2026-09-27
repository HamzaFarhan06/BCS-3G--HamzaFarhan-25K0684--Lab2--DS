#include <iostream>
using namespace std;

class SafeCommandCenter
{
private:
    int* a;
    int n;
public:
    SafeCommandCenter()
    {
        n = 5;
        a = new int[n];

        for (int i = 0; i < n; i++)
        {
            a[i] = 0;
        }
    }
    void safeWrite(int index, int value)
    {
        if (index < 0 || index >= n || value < 0 || value > 100)
        {
            cout << "CRITICAL ERROR: Invalid command!" << endl;
            cout << "Rover Emergency Braking Triggered!" << endl;
            return;
        }
        a[index] = value;
    }

    void show()
    {
        cout << "Commands: ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    ~SafeCommandCenter()
    {
        delete[] a;
    }
};

int main()
{
    SafeCommandCenter r;
    r.safeWrite(0, 50);
    r.safeWrite(1, 80);
    r.safeWrite(2, 100);
    r.show();
    cout << "\nTesting invalid commands:\n";
    r.safeWrite(5, 60);
    r.safeWrite(-1, 70);
    r.safeWrite(2, -20);
    r.safeWrite(3, 150);
    cout << "\nFinal commands:\n";
    r.show();
    return 0;
}