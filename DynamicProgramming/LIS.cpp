#include <bits/stdc++.h>
using namespace std;

#define ll            long long
#define PI            acos(-1)
#define RESET(a,b)    memset(a,b,sizeof(a))
#define maxi          INT_MAX
#define mini          INT_MIN

int memo[10001];  // For DP memoization

/*
 * Longest Increasing Subsequence (LIS)
 *
 * Problem: Find the length of longest strictly increasing subsequence.
 *
 * Example:
 * arr = [10, 9, 2, 5, 3, 7, 101, 18]
 * LIS = [2, 3, 7, 101] or [2, 5, 7, 101] (length 4)
 *
 * Methods:
 * 1. DP: O(n^2)
 * 2. Binary Search: O(n log n)
 */

// Method 1: DP O(n^2)
int lisDP(int *nums, int n, int id) {
    if(memo[id] != -1) return memo[id];
    memo[id] = 1;  // minimum LIS = the element itself
    for(int i = id + 1; i < n; i++) {
        if(nums[i] > nums[id]) {
            memo[id] = max(memo[id], 1 + lisDP(nums, n, i));
        }
    }
    return memo[id];
}

int main() {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(nums) / sizeof(nums[0]);
    RESET(memo, -1);

    cout << "=== Longest Increasing Subsequence ===" << endl;
    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;

    // Method 1: DP
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, lisDP(nums, n, i));
    }
    cout << "LIS Length (DP O(n^2)): " << ans << endl;

    return 0;
}

/*
 * Related Problems:
 *
 * 1. Longest Decreasing Subsequence
 *    - Negate all elements and find LIS
 *    - Or reverse the comparison
 *
 * 2. Longest Bitonic Subsequence
 *    - LIS from left + LDS from right - 1
 *
 * 3. Maximum Sum Increasing Subsequence
 *    - Instead of length, track sum
 *
 * 4. Russian Doll Envelopes (2D LIS)
 *    - Sort by width, then find LIS by height
 *
 * 5. Minimum Deletions to make sorted
 *    - n - LIS
 *
 * 6. Number of LIS
 *    - Track count along with length
 */
