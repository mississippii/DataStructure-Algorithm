
/*Practice Problem of LeetCode  "Pow(x, n)" Approach Divide and conquer*/

#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

double PowerOfTwoNumbers(double base,long long power){
        if(power<0)return 1/double (PowerOfTwoNumbers(base, -1*power));
        else if(power==0)return 1;
        else if (power ==1)return base;
        else if ((power&1)==1)return PowerOfTwoNumbers(base,power-1)*base;
        double temp = PowerOfTwoNumbers(base ,power/2);
        return 1LL*temp*temp;
    }

int main() {

    int TC;
    cin >> TC;
    while (TC--) {
        cout<<"Enter base and power :";
        int base,power;
        cin>>base>>power;
        double ans = PowerOfTwoNumbers(base,power);
        cout<<"Power of "<<base<<"^"<<power<<" is :"<<ans<<endl;
    }
    return 0;
}

