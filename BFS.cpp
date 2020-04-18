#include<bits/stdc++.h>

using namespace std;

void bfs(int x, queue<int> q, bool visited[], int distance[], vector<int> adj[])
{
    visited[x] = true;
    distance[x] = 0;
    q.push(x);
    while(!q.empty())
    {
        int s = q.front();
        cout<<s<<" ";
        q.pop();
        for(auto u: adj[s])
        {
            if(visited[u])
                continue;
            visited[u] =true;
            q.push(u);
            distance[u] = distance[s] + 1;
        }
    }
}
int main() {
    queue<int> q;
    int N = 6;
    bool visited[N];
    int distance[N];
    memset(visited, false, sizeof(visited));
	vector<int> adj[N];
	int u,v;
	while(cin>>u && cin>>v)
	{
	    adj[u].push_back(v);
	}
    bfs(0, q, visited, distance, adj);
}