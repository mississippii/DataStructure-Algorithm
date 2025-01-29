#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int findParent(vector<pii> &parent, int x){
  if(parent[x].first == x) return x;
  return parent[x].first= findParent(parent, parent[x].first);
}
void Union(vector<pii> &parent, int x, int y){
  int xParent = findParent(parent, x);
  int yParent = findParent(parent, y);
  if(xParent == yParent)return;
  if(parent[xParent].second > parent[yParent].second){
    parent[yParent].first= xParent;
  }
  else if(parent[xParent].second < parent[yParent].second){
    parent[xParent].first= yParent;
  }
  else{
    parent[yParent].first = xParent;
    parent[xParent].second++;
  }
}
void Print(vector<pii> &parent){
  for(int i=0;i<parent.size();i++){
    cout<<"Node  "<<i<<" parent is "<<parent[i].first<<" and Ranked  is "<<parent[i].second<<endl;
  }
}
int main(){
  int n;
  cout<<"Enter number of nodes: ";
  cin >> n;
  vector<pii>ara(n);
  for(int i=0;i<n;i++){
    ara[i]= {i,0};
  }
  cout<<"Enter number of edge: ";
  int m;
  cin>>m;
  for(int i=1;i<=m;i++){
    int x,y;
    cin>>x>>y;
    Union(ara,x,y);
  }
  Print(ara);
  return 0;
}