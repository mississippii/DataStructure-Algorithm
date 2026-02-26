#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN


int calculateGCD(int a,int b){
    if(b>a){
        swap(a,b);
    }
    if(b==0)return a;
    int gcd = b;

    for(int i=b;i>=1;i--){
        if(a%i==0 && b%i==0){
            gcd = i;
            break;
        }
    }
    return gcd;
}

int EuclideanGCD(int a,int b){

    if(b>a){
        swap(a,b);
    }
    if(b==0)return a;
    if(a%b==0)return b;

    return EuclideanGCD(b,a%b);
}

int main() {
    cout << "=== GCD Calculation ===" << endl;
    cout<<calculateGCD(24,15)<<endl;
    cout<<EuclideanGCD(40,0)<<endl;
    return 0;
}
