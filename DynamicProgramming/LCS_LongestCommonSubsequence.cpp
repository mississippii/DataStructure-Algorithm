#include <bits/stdc++.h>
using namespace std;

/*
 * Longest Common Subsequence (LCS)
 *
 * Problem: Find the longest subsequence present in both strings.
 * Subsequence: sequence that appears in same relative order but not necessarily contiguous.
 *
 * Example:
 * s1 = "ABCDGH", s2 = "AEDFHR"
 * LCS = "ADH" (length 3)
 *
 * Recurrence:
 * if s1[i-1] == s2[j-1]: dp[i][j] = 1 + dp[i-1][j-1]
 * else: dp[i][j] = max(dp[i-1][j], dp[i][j-1])
 *
 * Time: O(m * n)
 * Space: O(m * n) or O(min(m, n)) with optimization
 */

// Method 1: Recursive with Memoization
int memo[1001][1001];

int lcsMemo(string &s1, string &s2, int i, int j) {
    if (i == 0 || j == 0) return 0;

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i-1] == s2[j-1]) {
        return memo[i][j] = 1 + lcsMemo(s1, s2, i-1, j-1);
    }

    return memo[i][j] = max(lcsMemo(s1, s2, i-1, j), lcsMemo(s1, s2, i, j-1));
}

// Method 2: Tabulation
int lcsTabulation(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];

    // Base case: empty string has LCS 0
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

// Print the LCS string
string printLCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 0; j <= n; j++) dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Backtrack to find LCS string
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs = s1[i-1] + lcs;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

// Space Optimized - O(n) space
int lcsOptimized(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    vector<int> prev(n+1, 0), curr(n+1, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        swap(prev, curr);
    }

    return prev[n];
}

int main() {
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";

    cout << "=== Longest Common Subsequence ===" << endl;
    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;

    // Method 1: Memoization
    memset(memo, -1, sizeof(memo));
    cout << "\nLCS Length (Memo): " << lcsMemo(s1, s2, s1.length(), s2.length()) << endl;

    // Method 2: Tabulation
    cout << "LCS Length (Tab): " << lcsTabulation(s1, s2) << endl;

    // Method 3: Optimized
    cout << "LCS Length (Opt): " << lcsOptimized(s1, s2) << endl;

    // Print actual LCS
    cout << "LCS String: " << printLCS(s1, s2) << endl;

    // Another example
    cout << "\n--- Another Example ---" << endl;
    s1 = "AGGTAB";
    s2 = "GXTXAYB";
    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "LCS Length: " << lcsTabulation(s1, s2) << endl;
    cout << "LCS String: " << printLCS(s1, s2) << endl;

    return 0;
}

/*
 * Related Problems:
 *
 * 1. Longest Common Substring (contiguous)
 *    - if match: dp[i][j] = 1 + dp[i-1][j-1]
 *    - else: dp[i][j] = 0
 *
 * 2. Shortest Common Supersequence
 *    - Length = m + n - LCS
 *
 * 3. Minimum Insertions/Deletions to convert s1 to s2
 *    - Deletions = m - LCS
 *    - Insertions = n - LCS
 *
 * 4. Longest Palindromic Subsequence
 *    - LCS(s, reverse(s))
 *
 * 5. Minimum insertions to make palindrome
 *    - n - LPS
 */
