#include <iostream>

using namespace std;

int main() {
    int nmb,nm;
    cout << "Enter the number of memory blokcs: ";
    cin>>nmb;
    cout << "Enter the memory: ";
    cin >> nm;
    int mb[nmb],m[nm];
    int alloted[nm] = {0};
    for(int i=0;i<nmb;i++)
    {
        cout << "Enter memory block " << i << " ";
        cin >> mb[i];
    }
    for(int i=0;i<nm;i++)
    {
        cout << "Enter memory " << i << " ";
        cin >> m[i];
    }
/*
    for(int i=0;i<nm;i++)
    {
        cout << m[i] << "\t";
    }
    cout << endl;
    for(int i=0;i<nmb;i++)
    {
        cout << mb[i]<<"\t";
    }
*/

    for(int i=0; i<nm;i++)
    {
        for(int j=0; j<nmb; j++)
        {
            if(m[i]<=mb[j])
            {
               alloted[i] = j;
               mb[j] = mb[j] - m[i];
               break;
            }
        }
    }

    for(int i=0; i<nm; i++)
    {
        if(alloted[i] == 0)
            cout << m[i] << " is not alloted" << endl;
        else
            cout << m[i] << " is alloted to block " << alloted[i] << endl;
    }

}

