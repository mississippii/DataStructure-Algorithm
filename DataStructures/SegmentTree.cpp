#include<bits/stdc++.h>
using namespace std ;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

int res;

void SegmentTree(vector<int> &ara,vector<int> &tree,int node,int b,int e){

    if(b==e){
        tree[node]=ara[b];
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    SegmentTree(ara,tree,left,b,mid);
    SegmentTree(ara,tree,right,mid+1,e);
    tree[node]=tree[left]+tree[right];

}

void findval(vector<int> &tree,int node,int b,int e,int index){
    if(index<b || index>e)return;

    if(b>=index && e<=index){
        res=tree[node];
        tree[node]=0;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;
    findval(tree,left,b,mid,index);
    findval(tree,right,mid+1,e,index);
    tree[node]=tree[left]+tree[right];
}

void update(vector<int> &tree,int node,int b,int e,int index,int val)
{
    if(e<index || b>index)return;

    if(b>=index && e<=index){
        tree[node]+=val;
        return;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;

    update(tree,left,b,mid,index,val);
    update(tree,right,mid+1,e,index,val);

    tree[node]=tree[left]+tree[right];
}

int Queury(vector<int> &tree,int node,int b,int e,int i,int j){

    if(j<b || i>e)return 0;

    if(b>=i && e<=j)return tree[node];

    int mid=(b+e)/2;
    int left=node*2;
    int right=left+1;

    int x1=Queury(tree,left,b,mid,i,j);
    int x2=Queury(tree,right,mid+1,e,i,j);
    return x1+x2;
}


int main()
{
    int t;
    cin>>t;
    for(int TC=1;TC<=t;TC++){
        int n,q;
        cin>>n>>q;
        vector<int>ara,tree(n*3,0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            ara.push_back(x);
        }
//        for(auto x: ara)cout<<x<<" ";
//        cout<<endl;
        SegmentTree(ara,tree,1,0,n-1);
//        for(auto x:tree)cout<<x<<" ";
//        cout<<endl;

        cout<<"Case "<<TC<<":"<<endl;
        while(q--){
            int Q;
            cin>>Q;
            if(Q==1){
                int x;
                cin>>x;
                res=0;
                findval(tree,1,0,n-1,x);
                cout<<res<<endl;

            }
            else if(Q==2){
                int x,y;
                cin>>x>>y;
                update(tree,1,0,n-1,x,y);
            }
            else{
                int x,y;
                cin>>x>>y;
                cout<<Queury(tree,1,0,n-1,x,y)<<endl;
            }
        }
    }
    return 0;
}
