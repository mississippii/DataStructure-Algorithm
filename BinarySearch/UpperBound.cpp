/* Upper Bound is the rightmost position of a sorted array  for a number where you placed the number without removing  any
 element  from this array and the array reamin sorted*/

#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

int UpperBound(int ara[],int startIndx,int endIndx,int value){
    if(startIndx<endIndx){
        int mid =(startIndx+endIndx)/2;
        if(ara[mid]<=value)return UpperBound(ara,mid+1,endIndx,value);
        else return UpperBound(ara,startIndx,mid,value);
    }
    return endIndx;
}

int main() {

    int ara[]={1,2,3,4,5,6,7,8,9,10,10,12,13,14,15,16};
    int TC;
    cin >> TC;
    while (TC--) {
        int searchValue;
        cout<<"Enter your desired value: ";
        cin>>searchValue;
        cout<<"Upper Bound of the "<<searchValue<<" is :"<<UpperBound(ara,0,15,searchValue)<<endl;
    }
    return 0;
}
