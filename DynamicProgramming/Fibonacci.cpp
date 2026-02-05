#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

/*<--- "First, it's important to clarify that Dynamic Programming is not an algorithm.
 It is simply a technique used to solve certain types of problems in computer science." -->*/



int FibonacciByRecursion(int n){  //time Complexity of this function O(2^n)

    if(n<2)return n;
    return FibonacciByRecursion(n-1)+FibonacciByRecursion(n-2);
}


int FibonacciByDynamicProgramming(int n,int memo[]){  //time Complexity of this function O(n).This is the Beauty of Dynamic programming .
    if(n<2)return memo[n]=n;
    if(memo[n]!=-1)return memo[n];
    return memo[n]=FibonacciByDynamicProgramming(n-1,memo)+FibonacciByDynamicProgramming(n-2,memo);
}
int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin>>n;
        //In this  problem we find nth fibonacci number
        int NthFiboNumUsingRecursion=FibonacciByRecursion(n);
        cout<<"Using Recursion :"<<NthFiboNumUsingRecursion<<endl;


        int memo[n+1];
        RESET(memo,-1);
        int NthFiboFibonacciUsingDynamicProgramming= FibonacciByDynamicProgramming(n,memo);
        cout<<"Using Dynamic Programming :"<<NthFiboFibonacciUsingDynamicProgramming<<endl;

    }
    return 0;
}

