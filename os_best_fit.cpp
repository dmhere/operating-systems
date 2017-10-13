#include <iostream>

using namespace std;

int main() {
    int no_process,no_memory;
    cout << "Enter the number of memory blokcs: ";
    cin>>no_memory;
    cout << "Enter the process size: ";
    cin >> no_process;
    int memory[no_memory],process[no_process];
    int alloted[no_process] = {0};
    for(int i=0;i<no_memory;i++)
    {
        cout << "Enter memory block " << i+1 << " ";
        cin >> memory[i];
    }
    for(int i=0;i<no_process;i++)
    {
        cout << "Enter process " << i+1 << " size ";
        cin >> process[i];
    }

    for(int i=0; i<no_process;i++)
    {
        int min_index = -1 , min_size = memory[0];
        for(int j=0; j<no_memory; j++)
        {
            if(process[i]<= memory[j])
            {
                if(memory[j] <= min_size)
                {
                    min_size = memory[j];
                    min_index = j;
                }
            }
        }
        if(min_index >= 0)
        {
            alloted[i] = min_index+1;
            memory[min_index] = memory[min_index] - process[i];
        }
    }

    cout << "final memory blocks look like: " ;
    for(int i=0;i<no_memory;i++)
    {
        cout << memory[i]<<"\t";
    }
    cout << endl;
/*
    for(int i=0;i<no_process;i++)
    {
        cout << alloted[i]<<"\t";
    }
    cout << endl;
*/
    for(int i=0; i<no_process; i++)
    {
        if(alloted[i] == 0)
            cout << process[i] << " is not alloted" << endl;
        else
            cout << process[i] << " is alloted to block " << alloted[i] << endl;
    }

}

