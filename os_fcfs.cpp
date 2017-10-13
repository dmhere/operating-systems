#include <iostream>
using namespace std;

int main()
{
	int n;
	cout <<"Enter total number of processes - ";

	cin>>n;

	int arival[n], burst[n], turn[n], wait[n], comp[n];

	cout<<"Enter arrival times respectively :"<<endl;
	for(int i=0; i<n; i++)
	{
		//arival[i] = 0;
		cin >> arival[i];
	}

	cout<<"Enter burst times respectively :"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>burst[i];
	}

	int wt=0,awt=0,totaltat=0,atat=0;
	comp[0]=burst[0];

	for(int i=1; i<n; i++)
	{
		comp[i]=comp[i-1]+burst[i];
	}

	for(int i=0; i<n; i++)
	{
		turn[i]=comp[i]-arival[i];
	}

	for(int i=1; i<n; i++)
	{
		wait[i]=turn[i]-burst[i];
		wt=wt+wait[i];
	}

	awt = wt/n;
	cout<<"Average waiting time is : ";
	cout<<awt<<endl;
	for(int i=0; i<n;i++)
	{
		totaltat = totaltat + turn[i];
	}
	for(int i=0; i<n; i++)
	{
		cout << turn[i] << "\t";
	}
	cout << endl;

	atat = totaltat / n;
	cout<<"Average Turn around time is : ";
	cout<<atat;
	return 0;
}
