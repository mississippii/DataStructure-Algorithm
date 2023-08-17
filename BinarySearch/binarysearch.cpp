/*<---------------Binary search---------------------->*/



#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN


bool BinarySearch(int ara[],int desierValue,int aralen){

    int left =0,right=aralen;
    while(left<=right) {
        int mid=(left+right)/2;
        if(ara[mid]==desierValue)return true;
        else if (ara[mid]>desierValue)right=mid-1;
        else left=mid+1;
    }
    return false;
}

int main() {

    int ara[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int TC;
    cin >> TC;
    while (TC--) {
        int searchValue;
        cout<<"Enter your desired value: ";
        cin>>searchValue;
        int n=16; //size of arra
        bool flag =BinarySearch(ara,searchValue,n);
        if(flag)cout<<searchValue<<" Is Present this array"<<endl;
        else cout<<searchValue<<" is not Present this array"<<endl;

    }
    return 0;
}
