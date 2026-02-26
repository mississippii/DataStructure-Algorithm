#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

int EuclideanGCD(int a,int b){

    if(b==0)return a;
    if(a%b==0)return b;

    return EuclideanGCD(b,a%b);
}

vector<int> phiBrutforce(int n){
    vector<int> res;
    for(int i=2;i<n;i++){
        if(EuclideanGCD(i,n)==1){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    vector<int> res = phiBrutforce(34);
    for(int i: res){
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}