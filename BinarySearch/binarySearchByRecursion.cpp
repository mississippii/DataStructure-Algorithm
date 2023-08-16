#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN


bool BinarySearchByRecursion(int ara[],int desierValue,int left,int right){

    if(left<=right){
        int mid = (left+right)/2;
        if(ara[mid]==desierValue)return true;
        else if (ara[mid]>desierValue)return BinarySearchByRecursion(ara,desierValue,left,mid-1);
        else return BinarySearchByRecursion(ara,desierValue,mid+1,right);
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
        bool flag =BinarySearchByRecursion(ara,searchValue,0,15);
        if(flag)cout<<searchValue<<" Is Present this array"<<endl;
        else cout<<searchValue<<" is not Present this array"<<endl;

    }
    return 0;
}
