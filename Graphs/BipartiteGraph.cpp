#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

// Based on Problem in Leetcode "785. Is Graph Bipartite?"

bool IshBipartite(vector<vector<int>>&Graph,int src)
{
    int n= Graph.size();
    queue<int> Q;
    vector<bool>color(n);
    vector<bool>vis(n);
    Q.push(src);
    color[src] = true;
    vis[src] = true;
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (auto x : Graph[temp])
        {
            if (!vis[x])
            {
                Q.push(x);
                vis[x] = true;
                color[x] = !color[temp];
            }
            else
            {
                if (color[x] == color[temp])
                    return false;
            }
        }
    }
    return true;
}


int main(){
    vector<vector<int>>Graph={
                            {1,2,3},
                            {0,2},
                            {0,1,3},
                            {0,2}
                            };
    cout<<IshBipartite(Graph,1)<<endl;
    return 0;
}
