#include <bits/stdc++.h>
using namespace std;

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
int lisDP(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 1);  // dp[i] = LIS ending at index i

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

// Method 2: Binary Search O(n log n)
int lisBinarySearch(vector<int>& nums) {
    vector<int> tails;  // tails[i] = smallest tail element for LIS of length i+1

    for (int num : nums) {
        // Find position where num should be inserted
        auto it = lower_bound(tails.begin(), tails.end(), num);

        if (it == tails.end()) {
            tails.push_back(num);  // Extend LIS
        } else {
            *it = num;  // Replace with smaller element
        }
    }

    return tails.size();
}

// Print actual LIS
vector<int> printLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    int maxLen = 1, maxIdx = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIdx = i;
        }
    }

    // Reconstruct LIS
    vector<int> lis;
    while (maxIdx != -1) {
        lis.push_back(nums[maxIdx]);
        maxIdx = parent[maxIdx];
    }

    reverse(lis.begin(), lis.end());
    return lis;
}

// Count of LIS
int countLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> len(n, 1);    // len[i] = length of LIS ending at i
    vector<int> cnt(n, 1);    // cnt[i] = count of LIS ending at i

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[j] + 1 == len[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
    }

    int maxLen = *max_element(len.begin(), len.end());
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (len[i] == maxLen) {
            result += cnt[i];
        }
    }

    return result;
}

// Longest Non-Decreasing Subsequence (allow equal elements)
int lnds(vector<int>& nums) {
    vector<int> tails;

    for (int num : nums) {
        // Use upper_bound instead of lower_bound for non-decreasing
        auto it = upper_bound(tails.begin(), tails.end(), num);

        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }

    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "=== Longest Increasing Subsequence ===" << endl;
    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // Method 1: DP
    cout << "\nLIS Length (DP O(n^2)): " << lisDP(nums) << endl;

    // Method 2: Binary Search
    cout << "LIS Length (Binary Search O(n log n)): " << lisBinarySearch(nums) << endl;

    // Print actual LIS
    vector<int> lis = printLIS(nums);
    cout << "One LIS: ";
    for (int x : lis) cout << x << " ";
    cout << endl;

    // Count LIS
    cout << "Count of LIS: " << countLIS(nums) << endl;

    // Another example
    cout << "\n--- Another Example ---" << endl;
    vector<int> nums2 = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    cout << "Array: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;
    cout << "LIS Length: " << lisBinarySearch(nums2) << endl;

    lis = printLIS(nums2);
    cout << "One LIS: ";
    for (int x : lis) cout << x << " ";
    cout << endl;

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
