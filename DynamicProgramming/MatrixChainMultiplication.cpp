#include <bits/stdc++.h>
using namespace std;

// Matrix Chain Multiplication
// Given n matrices where matrix i has dimensions p[i-1] x p[i],
// find minimum scalar multiplications needed.
// Time: O(n^3), Space: O(n^2)

int memo[101][101];
int p[101];

int mcm(int i, int j) {
    if (i >= j) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = mcm(i, k) + mcm(k + 1, j) + p[i - 1] * p[k] * p[j];
        ans = min(ans, cost);
    }
    return memo[i][j] = ans;
}

int main() {
    // Matrices: A1(10x5), A2(5x50), A3(50x20)
    // p[] = {10, 5, 50, 20}
    int dims[] = {10, 5, 50, 20};
    int n = 3;

    for (int i = 0; i <= n; i++) p[i] = dims[i];
    memset(memo, -1, sizeof(memo));

    // mcm(1, n) = minimum cost to multiply matrices 1..n
    cout << "Minimum multiplications: " << mcm(1, n) << endl;

    return 0;
}
