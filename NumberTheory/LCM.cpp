#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN


int EuclideanGCD(int a,int b){

    if(a%b==0)return b;

    return EuclideanGCD(b,a%b);
}

int calculateLCM(int a,int b){
    return (a*b)/EuclideanGCD(a,b);
}

int LcmBruteForce(int a,int b){
    if(b>a){
        swap(a,b);
    }
    int lcm = a;
    for(int i=a;i<=a*b;i++){
        if(i%a==0 && i%b==0){
            lcm = i;
            break; 
        }
    }
    return lcm;
}

int main() {
    cout << "=== LCM Calculation ===" << endl;
    cout<<calculateLCM(48,18)<<endl;
    cout<<LcmBruteForce(48,18)<<endl;
}
