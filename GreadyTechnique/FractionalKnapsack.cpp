#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second*b.first > a.first*b.second;
}
int main() {
    int n,w;
    cin>>n>>w;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int weight,price;
        cin>>weight>>price;
        v.push_back({weight,price});
    }
    sort(v.begin(),v.end(),cmp);
    int ans=0;
    for(int i=0;i<n;i++){
        int z= min(w,v[i].first);
        w-=z;
        ans+=z*v[i].second;
    }
    cout<<ans<<endl;
    return 0;
}