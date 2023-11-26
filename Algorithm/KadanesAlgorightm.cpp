#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define PI acos(-1)
#define RESET(a, b) memset(a, b, sizeof(a))
#define maxi INT_MAX
#define mini INT_MIN

int KadanesAlgorithm(int ara[], int n)
{
    int memo[n] = {0};
    memo[0] = ara[0];
    for (int i = 1; i < n; i++)
        memo[i] = max(ara[i], memo[i - 1] + ara[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, memo[i]);

    return ans;
}

int main()
{
    int ara[9] = {4, -8, -2, 8, -1, 3, 2, -6, 2};
    int ans = KadanesAlgorithm(ara, 9);
    cout << "Maximum subarray sum :" << ans << endl;
    return 0;
}
