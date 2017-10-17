#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "\nEnter the number of processes -- ";
    cin >> n;
    int p[n], bt[n], wt[n], tat[n], i, k, temp;
    float wtavg, tatavg;
    for(i=0;i<n;i++)
    {
        p[i]=i;
        cout << "Enter Burst Time for Process "<<i<<" -- ";
        cin >> bt[i];
    }
    for(i=0;i<n;i++)
        for(k=i+1;k<n;k++)
            if(bt[i]>bt[k])
            {
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
            }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i=1;i<n;i++)
    {
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    cout << "\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n";
    for(i=0;i<n;i++)
        cout << "\n\t P"<<p[i]<<" \t\t "<<bt[i]<<" \t\t "<<wt[i]<<" \t\t "<<tat[i];
    cout << "\nAverage Waiting Time -- "<< wtavg/n;
    cout << "\nAverage Turnaround Time -- "<< tatavg/n;
    return 0;
}
