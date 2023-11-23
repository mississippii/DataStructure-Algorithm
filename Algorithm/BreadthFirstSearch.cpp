#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

void TraversWithBFS(vector<vector<int>>& graph, vector<bool>& visited, int src){
    queue<int>Q;
    Q.push(src);
    while(!Q.empty()) {
        int temp = Q.front();
        cout<<temp<<"-->";
        Q.pop();
        for(auto x : graph[temp]){
            if(!visited[x]){
            visited[x] = true;
            Q.push(x);
            }
        }
    }
    cout<<endl;
    return;

}

int main() {

    vector<vector<int>>Graph ={
        {},
        {2,3,4},
        {6},{7,8},
        {7},
        {8,10},
        {9},
        {3,4,9},
        {3,5},
        {6,7,10},
        {9,5}};
 /*
        Adjacency List
        0-->
        1--> 2,3,4
        2--> 6
        3--> 7,8
        4--> 7
        5--> 8,10
        6--> 9
        7--> 3,4,9
        8--> 3,5
        9--> 6,7,10
        10-->9,5
*/
   int src=1;
   vector<bool>visited(11);
   TraversWithBFS(Graph,visited,src);
    return 0;
}

