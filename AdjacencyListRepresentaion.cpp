#include <bits/stdc++.h>
using namespace std;

int main() {
    int N = 5;
	vector<int> adj[N];
	int u,v;
	while(cin>>u && cin>>v)
	{
	    adj[u].push_back(v);
	}
	for(int i=0;i<N;i++)
	{
	    cout<<i<<" ";
	    int j = adj[i].size();
	    int k = 0;
	    while(j)
	    {
	        cout<<adj[i][k]<<" ";
	        k++;
	        j--;
	    }
	    cout<<endl;
	}
	return 0;
}

//Adjacency list representation