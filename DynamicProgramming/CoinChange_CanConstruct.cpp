#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

/*Problem Statement:: You will be given an array listOfCoins where listOfCoins[i] represents the values of coins 0<listOfCoins[i]<10^5. Additionally,
provide a target value (target). Your task is to construct the target value using those coins as many times as possible.
Print 'YES' if it is possible, or 'NO' otherwise.
*/

bool IsPossible(int listOfCoins[],int target){
    bool *memo;
    memo = new bool[target+1];
    RESET(memo,0);
    memo[0]=true;
    for (int  i = 1; i <=target; i++){
        for (int j = 0; j < 20; j++){
            if(i-listOfCoins[j] >= 0 && memo[i-listOfCoins[j]] == true){
                memo[i]=true;
            }
        }

    }
    return memo[target];
}

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int listOfCoins[20] = {3, 5, 8, 7, 34, 23, 16, 42, 9, 11, 77, 89, 53, 30, 15, 6, 98, 45, 20, 3};
        int target;
        cout<<"Please Enter your desire number you will construct ::";
        cin>>target;
        cout<<endl<<IsPossible(listOfCoins,target)<<endl;
    }
    return 0;
}

