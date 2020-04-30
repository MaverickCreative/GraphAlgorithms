class Solution {
    bool check_cycle(vector<int> adj[], int pro[], int x)
    {
        if(pro[x] == 1)
        {
            return false;
        }
        pro[x] = 1;
        for(auto u: adj[x])
        {
            if(!check_cycle(adj, pro, u))
            {
                return false;
            }
        }
        pro[x] = 2;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int pro[numCourses];
        vector<int> adj[numCourses];
        if(p.size() == 0 || p.size()==1)
        {
            return true;
        }
        for(int i=0;i<p.size();i++)
        {
            int a = p[i][0];
            int b = p[i][1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++)
        {
            pro[i] = 0;
        }
        for(int i=0;i<numCourses;i++){
           if(!pro[i]){
               if(!check_cycle(adj, pro, i)) return false;
           }
       }
        return true;
    }
};