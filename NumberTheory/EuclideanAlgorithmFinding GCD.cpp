#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

int calculateGcd(int a,int b){
    if(b%a==0)return a;
    return calculateGcd(b%a,a);
}


int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        cout<<"Please enter two number :";
        int a,b;
        cin>>a>>b;
        int ans = calculateGcd(a,b);

        cout<<"Gcd("<<a<<","<<b<<") is: "<<ans<<endl;
    }
    return 0;
}

