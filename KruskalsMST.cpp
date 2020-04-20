#include <bits/stdc++.h>
using namespace std;

int find_leader_element(int a, int link[])
{
    while(a!=link[a])
        a = link[a];
    return a;
}

bool same(int a, int b, int link[])
{
    if(find_leader_element(a, link ) == find_leader_element(b, link))
    {
        return true;
    }
    return false;
}

void unite(int a, int b,int size[], int link[])
{
    int x = find_leader_element(a, link);
    int y = find_leader_element(b, link);
    if(size[x] < size[y])
        swap(x,y);
    size[x] += size[y]; 
    link[y] = x;
}

bool mycomp(tuple<int,int,int> a, tuple<int,int,int> b)
{
    if(get<2>(a) < get<2>(b))
        return true;
    return false;
}
void findMST(vector<tuple<int,int,int>> edgeList, int link[], int size[])
{
    sort(edgeList.begin(), edgeList.end(), mycomp);
    for(auto u: edgeList)
    {
        cout<<get<2>(u)<<endl;
    }
    int sum = 0;
    for(auto u: edgeList)
    {
         if(!same(get<0>(u),get<1>(u), link))
         {
             sum = sum + get<2>(u);
             unite(get<0>(u),get<1>(u), size, link);
         }
    }
    cout<<sum<<endl;
}

int main() {
    int N;
    cin>>N;
    vector<tuple<int, int, int>> edgeList;
    int a,b,w;
    while(cin>>a && cin>>b && cin>>w)
    {
        edgeList.push_back(make_tuple(a,b,w));
    }
    int link[N];
    int size[N];
    for(int i=0;i<N;i++)
    {
        link[i] = i;
        size[i] = 1;
    }
    findMST(edgeList,link,size);
    for(int i=0;i<N;i++)
    {
        cout<<link[i]<<" ";
    }
}