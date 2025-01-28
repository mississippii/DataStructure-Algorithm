#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> convertAdjList(int graph[][6],int n) {
    vector<vector<pii>> adjList(n);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(graph[i][j]<1)continue;
            adjList[i].push_back({j,graph[i][j]});
            adjList[j].push_back({i,graph[i][j]});
        }
    }
    return adjList;
}
void dijkstra(vector<vector<pii>>&graph ,int src) {
    int n = graph.size();
    vector<int> dist(n,INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()) {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();
        if (dist[currNode] < currDist) continue;
        for (pii neighbor : graph[currNode]) {
            int nextNode = neighbor.first;
            int nextDist = neighbor.second;
            if (dist[nextNode] > dist[currNode] + nextDist) {
                dist[nextNode] = dist[currNode] + nextDist;
                pq.push({dist[nextNode],nextNode});
            }
        }
    }

    cout << "Node\tDistance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "----->" << dist[i] << endl;
    }

}
int main(){
  int graph[6][6]={
              {0,14,9,0,0,7},
              {14,0,2,8,0,0},
              {9,2,0,0,11,10},
              {0,8,0,0,6,0},
              {0,0,11,6,0,15},
              {7,0,10,0,15,0}
                };
    vector<vector<pii>>adjList = convertAdjList(graph,6);
    int source = 0;
    dijkstra(adjList,source);
  return 0;
}