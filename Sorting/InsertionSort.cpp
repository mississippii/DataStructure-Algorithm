#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN


void InsertionSort(int ara[],int n){

    for(int i=1;i<n;i++){
        int key=ara[i];
        int j=i-1;
        while(j>=0 && ara[j]>key){
            ara[j+1]=ara[j];
            j--;
        }
        ara[j+1]=key;
    }
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int ara[6]={5,2,4,6,1,3};
        InsertionSort(ara,6);
        for(int i=0;i<6;i++)
            cout<<ara[i]<<" ";
        cout<<endl;

    }
    return 0;
}
