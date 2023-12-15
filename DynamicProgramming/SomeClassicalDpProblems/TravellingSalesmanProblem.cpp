#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN
const int siz=1000;

/* Problem statement
Given a set of Nodes and the distance between every pair of node, the problem is to find the shortest possible route 
that visits every node exactly once and returns to the starting node.
*/
int memo[1<<20][20];

bool checkBit(int n,int i){
    return (n &(1<<i));
}
int minimuCost(int graph[][4],int bit,int at){

    if(bit == (1<<4)-1) return graph[at][0];

    int &res = memo[bit][at];
    if(res !=-1)return res;
    res = 1e9+7;

    for(int i=0;i<4;i++){
        if( !checkBit(bit,i)){
            res = min(res,minimuCost(graph, (bit |(1<<i)),i)+graph[at][i]);
        }
    }
    return res;
}
int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int graph[4][4]={
            {0,10,15,20},
            {10,0,35,25},
            {15,35,0,30},
            {20,25,30,0}
            };
        RESET(memo,-1);
        int ans = minimuCost(graph,0,0);
        cout << ans << endl;
    }
    return 0;
}
