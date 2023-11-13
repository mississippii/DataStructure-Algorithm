#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

/*You will be given an array listOfCoins where listOfCoins[i] represents the values of coins, and 0<listOfCoins[i]<10 5.
 Additionally, provide a target value (target). Your task is to determine how many ways there are to construct the target value using those coins as many times as possible..
*/

int IsPossible(int listOfCoins[],int target){
    int *memo;
    memo = new int[target+1];
    RESET(memo,0);
    for(int i=0;i<=target;i++){
        memo[i]=0;
    }

    memo[0]=1;
    for (int  i = 1; i <=target; i++){
        for (int j = 0; j < 2; j++){
            if(i-listOfCoins[j] >= 0 && memo[i-listOfCoins[j]]){
                memo[i]+=memo[i-listOfCoins[j]];
            }
        }

    }

    return memo[target];
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int listOfCoins[20] ={1,2}; //{3, 5, 8, 7, 34, 23, 16, 42, 9, 11, 77, 89, 53, 30, 15, 6, 98, 45, 20, 3};
        int target;
        cout<<"Please Enter your desire number you will construct ::";
        cin>>target;
        cout<<endl<<IsPossible(listOfCoins,target)<<endl;
    }
    return 0;
}

