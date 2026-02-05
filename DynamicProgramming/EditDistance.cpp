#include <bits/stdc++.h>
using namespace std;

/*
 * Edit Distance (Levenshtein Distance)
 *
 * Problem: Find minimum operations to convert string s1 to s2.
 * Operations: Insert, Delete, Replace (each costs 1)
 *
 * Example:
 * s1 = "horse", s2 = "ros"
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (delete 'r')
 * rose -> ros (delete 'e')
 * Edit Distance = 3
 *
 * Recurrence:
 * if s1[i-1] == s2[j-1]: dp[i][j] = dp[i-1][j-1]
 * else: dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
 *                       (delete)    (insert)    (replace)
 *
 * Time: O(m * n)
 * Space: O(m * n) or O(n) with optimization
 */

// Method 1: Recursive with Memoization
int memo[1001][1001];

int editMemo(string &s1, string &s2, int i, int j) {
    // Base cases
    if (i == 0) return j;  // Insert all of s2
    if (j == 0) return i;  // Delete all of s1

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i-1] == s2[j-1]) {
        return memo[i][j] = editMemo(s1, s2, i-1, j-1);
    }

    int insertOp = editMemo(s1, s2, i, j-1);     // Insert s2[j-1] into s1
    int deleteOp = editMemo(s1, s2, i-1, j);     // Delete s1[i-1]
    int replaceOp = editMemo(s1, s2, i-1, j-1);  // Replace s1[i-1] with s2[j-1]

    return memo[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
}

// Method 2: Tabulation
int editTabulation(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];

    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;  // Delete all from s1
    for (int j = 0; j <= n; j++) dp[0][j] = j;  // Insert all from s2

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],    // Delete
                    dp[i][j-1],    // Insert
                    dp[i-1][j-1]   // Replace
                });
            }
        }
    }

    return dp[m][n];
}

// Space Optimized - O(n)
int editOptimized(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    vector<int> prev(n+1), curr(n+1);

    // Base case: first row
    for (int j = 0; j <= n; j++) prev[j] = j;

    for (int i = 1; i <= m; i++) {
        curr[0] = i;  // Base case: first column

        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                curr[j] = prev[j-1];
            } else {
                curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
            }
        }

        swap(prev, curr);
    }

    return prev[n];
}

// Print the operations
void printOperations(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }

    cout << "Edit Distance: " << dp[m][n] << endl;
    cout << "Operations:" << endl;

    // Backtrack to find operations
    int i = m, j = n;
    vector<string> ops;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && s1[i-1] == s2[j-1]) {
            i--; j--;
        } else if (j > 0 && (i == 0 || dp[i][j] == dp[i][j-1] + 1)) {
            ops.push_back("Insert '" + string(1, s2[j-1]) + "' at position " + to_string(i));
            j--;
        } else if (i > 0 && (j == 0 || dp[i][j] == dp[i-1][j] + 1)) {
            ops.push_back("Delete '" + string(1, s1[i-1]) + "' at position " + to_string(i-1));
            i--;
        } else {
            ops.push_back("Replace '" + string(1, s1[i-1]) + "' with '" + string(1, s2[j-1]) + "' at position " + to_string(i-1));
            i--; j--;
        }
    }

    reverse(ops.begin(), ops.end());
    for (const string& op : ops) {
        cout << "  " << op << endl;
    }
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    cout << "=== Edit Distance ===" << endl;
    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;

    // Method 1: Memoization
    memset(memo, -1, sizeof(memo));
    cout << "\nEdit Distance (Memo): " << editMemo(s1, s2, s1.length(), s2.length()) << endl;

    // Method 2: Tabulation
    cout << "Edit Distance (Tab): " << editTabulation(s1, s2) << endl;

    // Method 3: Optimized
    cout << "Edit Distance (Opt): " << editOptimized(s1, s2) << endl;

    // Print operations
    cout << "\n";
    printOperations(s1, s2);

    // Another example
    cout << "\n--- Another Example ---" << endl;
    s1 = "intention";
    s2 = "execution";
    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << "Edit Distance: " << editTabulation(s1, s2) << endl;

    return 0;
}

/*
 * Variations:
 *
 * 1. Weighted Edit Distance
 *    - Different costs for insert, delete, replace
 *
 * 2. Only Insert and Delete (no replace)
 *    - dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1])
 *    - Result = m + n - 2*LCS
 *
 * 3. Only Insertions
 *    - LCS approach: n - LCS(s1, s2)
 *
 * 4. Wildcard Matching
 *    - Similar DP with special handling for * and ?
 *
 * 5. Regular Expression Matching
 *    - Handle . and * operators
 */
