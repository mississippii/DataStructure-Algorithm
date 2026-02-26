#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN


// Time Complexity: O(√n)
vector<int> primeFactorization(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

int main() {
    vector<int> factors = primeFactorization(90);
    for (int f : factors) cout << f << " ";
    cout << endl;
    // Output: 2 2 3 5
    return 0;
}
