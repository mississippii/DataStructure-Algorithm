#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN


void SelectionSort(int ara[],int n){
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(ara[i]>ara[j]){
                swap(ara[i],ara[j]);
            }
        }
    }
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int ara[10]={9,4,1,8,3,2,6,10,5,7};
        SelectionSort(ara,10);
        for(int i=0;i<10;i++)
            cout<<ara[i]<<" ";
        cout<<endl;

    }
    return 0;
}

