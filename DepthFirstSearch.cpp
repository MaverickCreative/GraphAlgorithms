#include <bits/stdc++.h>
using namespace std;

void dfs(int s, bool visited[], vector<int> adj[])
{
    if(visited[s])
    {
        return;
    }
    visited[s] = true;
    cout<<s<<" ";
    for(auto u: adj[s])
    {
        dfs(u, visited, adj);
    }
}


int main() {
    int N = 5;
	vector<int> adj[N];
	int u,v;
	while(cin>>u && cin>>v)
	{
	    adj[u].push_back(v);
	}
	bool visited[5];
	memset(visited, false, sizeof(visited));
	dfs(0, visited, adj );
	return 0;
}
