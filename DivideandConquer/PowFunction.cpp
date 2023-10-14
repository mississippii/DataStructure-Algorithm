
/*Practice Problem of LeetCode  "Pow(x, n)" Approach Divide and conquer*/

#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

double PowerOfTwoNumbers(double base,long long pow){
        if(pow<0)return 1/double (PowerOfTwoNumbers(base, -1*pow));
        else if(pow==0)return 1;
        else if (pow ==1)return base;
        else if ((pow&1)==1)return PowerOfTwoNumbers(base,pow-1)*base;
        double temp = PowerOfTwoNumbers(base ,pow/2);
        return 1LL*temp*temp;
    }

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        cout<<"Enter base and power :";
        int base,pow;
        cin>>base>>pow;
        double ans = PowerOfTwoNumbers(base,pow);
        cout<<"Power of "<<base<<"^"<<pow<<" is :"<<ans<<endl;
    }
    return 0;
}

