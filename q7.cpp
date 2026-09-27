#include <iostream>
using namespace std;

class PlaylistManager
{
private:
    int** customPlaylists;
    int* playlistCapacities;
    int p;

public:
    
    PlaylistManager(int n)
    {
        p = n;
        customPlaylists = new int*[p];
        playlistCapacities = new int[p];
        for (int i = 0; i < p; i++)
        {
            cout << "Enter number of tracks in playlist " << i << ": ";
            cin >> playlistCapacities[i];

            customPlaylists[i] = new int[playlistCapacities[i]];

            cout << "Enter track IDs: ";
            for (int j = 0; j < playlistCapacities[i]; j++)
            {
                cin >> customPlaylists[i][j];
            }
        }
    }


    PlaylistManager(const PlaylistManager& other)
    {
        p = other.p;
        customPlaylists = new int*[p];
        playlistCapacities = new int[p];

        for (int i = 0; i < p; i++)
        {
            playlistCapacities[i] = other.playlistCapacities[i];
            customPlaylists[i] =
                new int[playlistCapacities[i]];

            for (int j = 0; j < playlistCapacities[i]; j++)
            {
                customPlaylists[i][j] =
                    other.customPlaylists[i][j];
            }
        }

        cout << "Deep copy created successfully!" << endl;
    }

    void addTrack(int x, int id)
    {
        if (x < 0 || x >= p)
        {
            cout << "Invalid playlist!" << endl;
            return;
        }
        int old = playlistCapacities[x];
        int* t = new int[old + 1];
        for (int i = 0; i < old; i++)
        {
            t[i] = customPlaylists[x][i];
        }
        t[old] = id;
        delete[] customPlaylists[x];
        customPlaylists[x] = t;
        playlistCapacities[x]++;

        cout << "Track added successfully!" << endl;
    }

    void play(int x, int y)
    {
        if (x < 0 || x >= p)
        {
            cout << "Invalid playlist!" << endl;
            return;
        }
        if (y < 0 || y >= playlistCapacities[x])
        {
            cout << "Invalid track!" << endl;
            return;
        }
        cout << "Playing track ID: "
             << customPlaylists[x][y] << endl;
    }

 
    void show()
    {
        for (int i = 0; i < p; i++)
        {
            cout << "Playlist " << i << ": ";
            for (int j = 0; j < playlistCapacities[i]; j++)
            {
                cout << customPlaylists[i][j] << " ";
            }
            cout << endl;
        }
    }


    ~PlaylistManager()
    {
        for (int i = 0; i < p; i++)
        {
            delete[] customPlaylists[i];
        }
        delete[] customPlaylists;
        delete[] playlistCapacities;
    }
};

int main()
{
    int n;
    cout << "Enter number of playlists: ";
    cin >> n;
    PlaylistManager a(n);
    cout << "\nOriginal playlists:\n";
    a.show();

    PlaylistManager b = a;

    cout << "\nCopied playlists:\n";
    b.show();

  
    int p, id;
    cout << "\nEnter playlist to add track to copy: ";
    cin >> p;
    cout << "Enter track ID: ";
    cin >> id;
    b.addTrack(p, id);
    cout << "\nOriginal after modifying copy:\n";
    a.show();
    cout << "\nCopy after modification:\n";
    b.show();

    cout << "\nTesting track access:\n";
    b.play(0, 0);

    return 0;
}