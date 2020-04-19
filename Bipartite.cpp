bool ans = true;

bool dfs(int s, vector<vector<int>>& graph, bool visited[], int color[], int c)
{
   if(visited[s] == true && color[s]!=c)
    {
        return false;
    }
   if(visited[s] == true && color[s]==c)
    {
        return true;
    }
    visited[s] = true;
    color[s] = c;
    for(auto u: graph[s])
    {
        ans = ans&dfs(u, graph, visited, color, 1-c);
    }
    return ans;
}

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool visited[graph.size()];
        int color[graph.size()];
        for(int i=0;i<graph.size();i++)
        {
            color[i] = -1;
        }
        memset(visited, false, sizeof(visited));
        bool a = dfs(0,graph,visited,color, 1);
        return a;
    }
};

