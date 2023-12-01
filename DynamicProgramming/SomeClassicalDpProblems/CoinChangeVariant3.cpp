#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN
const int siz=1000;
bool IsPossible(int ara[],int lenght,int targetValue){

    bool memo[siz][siz];
    RESET(memo,0);
    memo[0][0] =1;

    for(int i=1;i<lenght;i++){
        for(int j=0;j<=targetValue;j++){
            if((j-ara[i]>=0 && memo[i-1][j-ara[i]] ) || memo[i-1][j]) memo[i][j] =1;
        }
    }
    for(int i=0;i<lenght;i++){
        for(int j=0;j<=targetValue;j++)
            cout<<memo[i][j]<<" ";
        cout<<endl;
    cout<<endl;
    }
    return memo[lenght-1][targetValue];

}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int ara[10]={0,5,4,10,7,9,13,15,23,20};
        int targetValue;
        cin>>targetValue;
        if(IsPossible(ara,10,targetValue))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
