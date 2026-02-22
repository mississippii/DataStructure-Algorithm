#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

//Time Complexity O(n^2)
void insertionSort(int *ara,int n){

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

    int ara[]={9,4,1,8,3,2,6,10,5,7};
    insertionSort(ara,10);
    for(int i=0;i<10;i++)
        cout<<ara[i]<<" ";
    cout<<endl;

    return 0;
}
