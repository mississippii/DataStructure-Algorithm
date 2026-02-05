public class KMPAlgorithm {

    // Build LPS (Longest Proper Prefix which is also Suffix) array
    private int[] computeLPS(String pattern) {
        int m = pattern.length();
        int[] lps = new int[m];

        int len = 0;  // Length of previous longest prefix suffix
        int i = 1;
        lps[0] = 0;   // LPS of first character is always 0

        while (i < m) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];  // Don't increment i here
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    // KMP Pattern Search - Returns first occurrence index (-1 if not found)
    public int search(String text, String pattern) {
        int n = text.length();
        int m = pattern.length();

        if (m == 0) return 0;
        if (n < m) return -1;

        int[] lps = computeLPS(pattern);

        int i = 0;  // Index for text
        int j = 0;  // Index for pattern

        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;  // Pattern found at index (i - j)
            } else if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];  // Use LPS to skip comparisons
                } else {
                    i++;
                }
            }
        }

        return -1;
    }

    // Find all occurrences
    public int[] searchAll(String text, String pattern) {
        int n = text.length();
        int m = pattern.length();

        if (m == 0 || n < m) return new int[0];

        int[] lps = computeLPS(pattern);
        java.util.List<Integer> result = new java.util.ArrayList<>();

        int i = 0, j = 0;

        while (i < n) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;
            }

            if (j == m) {
                result.add(i - j);
                j = lps[j - 1];  // Continue searching for more occurrences
            } else if (i < n && text.charAt(i) != pattern.charAt(j)) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }

    // Z-Algorithm for pattern matching
    public int[] zFunction(String s) {
        int n = s.length();
        int[] z = new int[n];

        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = Math.min(r - i, z[i - l]);
            }

            while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i])) {
                z[i]++;
            }

            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }

        return z;
    }

    public static void main(String[] args) {
        KMPAlgorithm kmp = new KMPAlgorithm();

        // Test LPS array
        String pattern = "AAACAAAA";
        int[] lps = kmp.computeLPS(pattern);
        System.out.print("LPS array for '" + pattern + "': ");
        for (int val : lps) System.out.print(val + " ");
        System.out.println();  // 0 1 2 0 1 2 3 3

        // Test KMP search
        String text = "ABABDABACDABABCABAB";
        String pat = "ABABCABAB";
        int index = kmp.search(text, pat);
        System.out.println("Pattern '" + pat + "' found at index: " + index);  // 10

        // Test find all occurrences
        String text2 = "AAAAAA";
        String pat2 = "AA";
        int[] allIndices = kmp.searchAll(text2, pat2);
        System.out.print("All occurrences of '" + pat2 + "' in '" + text2 + "': ");
        for (int idx : allIndices) System.out.print(idx + " ");
        System.out.println();  // 0 1 2 3 4

        // Test Z-function
        String s = "aabxaab";
        int[] z = kmp.zFunction(s);
        System.out.print("Z-array for '" + s + "': ");
        for (int val : z) System.out.print(val + " ");
        System.out.println();  // 0 1 0 0 3 1 0
    }
}

/*
 * KMP (Knuth-Morris-Pratt) Algorithm
 *
 * Problem: Find pattern in text efficiently
 *
 * Key Idea:
 * - Preprocess pattern to build LPS array
 * - LPS[i] = length of longest proper prefix which is also suffix for pattern[0..i]
 * - Use LPS to avoid re-checking characters
 *
 * Example LPS:
 * Pattern: "ABAB"
 * LPS:     [0, 0, 1, 2]
 *
 * A    -> 0 (no proper prefix = suffix)
 * AB   -> 0
 * ABA  -> 1 ("A" is both prefix and suffix)
 * ABAB -> 2 ("AB" is both prefix and suffix)
 *
 * Time Complexity: O(n + m) where n = text length, m = pattern length
 * Space Complexity: O(m) for LPS array
 *
 * Comparison:
 * - Brute Force: O(n * m)
 * - KMP: O(n + m)
 * - Rabin-Karp: O(n + m) average, O(n * m) worst case
 */
