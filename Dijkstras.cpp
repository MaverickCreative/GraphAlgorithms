#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<pair<int,int>> adj[], int distance[], bool processed[], int x)
{
    distance[x] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,x));
    while(!q.empty())
    {
        int s = q.top().second;
        q.pop();
        if(processed[s])
        {
            continue;
        }
        processed[s] = true;
        for(auto u: adj[s])
        {
            int b = u.first;
            int w = u.second;
            if(distance[s] + w < distance[b])
            {
                distance[b] = distance[s]+w;
                q.push(make_pair(-distance[b],b));
            }
        }
    }
}
int main() {
    int N = 5;
	vector<pair<int,int>> adj[N];
	int u,b,w;
	while(cin>>u && cin>>b && cin>>w)
	{
	    adj[u].push_back(make_pair(b,w));
	}
    int distance[N];
    bool processed[N];
    memset(processed, false, sizeof(processed));
    for(int i=0;i<N;i++)
    {
        distance[i] = 10000;
    }
    dijkstra(adj, distance, processed, 0);
    for(int i=0;i<N;i++)
    {
        cout<<distance[i]<<" ";
    }
	return 0;
}