#include <iostream>
using namespace std;

int main()
{
    int shelf[6] = {102, 0, 305, 0, 401, 908};
    cout << "Shelf before compacting: ";
    for (int i = 0; i < 6; i++)
    {
        cout << shelf[i] << " ";
    }

    int pos = 0;
    for (int i = 0; i < 6; i++)
    {
        if (shelf[i] != 0)
        {
            shelf[pos] = shelf[i];
            pos++;
        }
    }

    while (pos < 6)
    {
        shelf[pos] = 0;
        pos++;
    }

    cout << "\nShelf after compacting: ";
    for (int i = 0; i < 6; i++)
    {
        cout << shelf[i] << " ";
    }

    return 0;
}