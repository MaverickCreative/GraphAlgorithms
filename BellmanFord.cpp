void bellman_ford(vector<vector<int>>&times,int K,int N, int distance[])
{
    distance[K-1] = 0;
    for(int i=0;i<=(N-2);i++)
    {
        for(auto u: times)
        {
            int a = u[0];
            int b = u[1];
            int c = u[2];
            distance[b-1] = min(distance[b-1], (distance[a-1] + c));
        }
    }
}