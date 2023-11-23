#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

void TraverseWithDFS(vector<vector<int>>&Graph, vector<bool>&visited,int src){
    cout<<src<<"-->";
    for(auto x : Graph[src]){
        if(!visited[x]){
            visited[x] = true;
            TraverseWithDFS(Graph,visited,x);
        }
    }
    return;
}

int main() {

    vector<vector<int>>Graph ={
                                {},
                                {2,3,4},
                                {6},
                                {7,8},
                                {7},
                                {8,10},
                                {9},
                                {3,4,9},
                                {3,5},
                                {6,7,10},
                                {9,5}
                            };
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
   visited[src] = true;
   TraverseWithDFS(Graph, visited, src);
    return 0;
}

