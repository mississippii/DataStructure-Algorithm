#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

//<-----Time Complexity O(n^2)------->

void BubbleSort(int *ara,int n){
    for(int i=0;i<n;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(ara[j]> ara[j+1]){
                swap(ara[j],ara[j+1]);
                swapped = true;
            }
        }
    for(int i=0;i<n;i++)cout<<ara[i]<<" ";
    cout<<endl;

        if(!swapped) break; // If no swapping occurred, array is sorted
    }
}

int main() {

    int ara[]={9,4,1,8,3,2,6,10,5,7};
    for(int i=0;i<10;i++)
        cout<<ara[i]<<" ";
    cout<<endl;
    BubbleSort(ara,10);

    for(int i=0;i<10;i++)
        cout<<ara[i]<<" ";
    cout<<endl;

    return 0;
}

