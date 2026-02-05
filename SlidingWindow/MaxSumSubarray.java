import java.util.*;

public class MaxSumSubarray {

    // Fixed size sliding window: Max sum of subarray of size k
    public int maxSumSubarrayOfSizeK(int[] nums, int k) {
        int n = nums.length;
        if (n < k) return -1;

        // Calculate sum of first window
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        int maxSum = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += nums[i] - nums[i - k];  // Add new, remove old
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;
    }

    // Variable size: Longest substring without repeating characters
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);

            if (map.containsKey(c)) {
                left = Math.max(left, map.get(c) + 1);
            }

            map.put(c, right);
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // Variable size: Minimum window substring
    public String minWindowSubstring(String s, String t) {
        if (s.length() < t.length()) return "";

        Map<Character, Integer> need = new HashMap<>();
        Map<Character, Integer> window = new HashMap<>();

        for (char c : t.toCharArray()) {
            need.put(c, need.getOrDefault(c, 0) + 1);
        }

        int left = 0, right = 0;
        int valid = 0;
        int start = 0, minLen = Integer.MAX_VALUE;

        while (right < s.length()) {
            char c = s.charAt(right);
            right++;

            if (need.containsKey(c)) {
                window.put(c, window.getOrDefault(c, 0) + 1);
                if (window.get(c).equals(need.get(c))) {
                    valid++;
                }
            }

            // Shrink window
            while (valid == need.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }

                char d = s.charAt(left);
                left++;

                if (need.containsKey(d)) {
                    if (window.get(d).equals(need.get(d))) {
                        valid--;
                    }
                    window.put(d, window.get(d) - 1);
                }
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
    }

    public static void main(String[] args) {
        MaxSumSubarray mss = new MaxSumSubarray();

        // Test 1: Max sum subarray of size k
        int[] nums = {2, 1, 5, 1, 3, 2};
        int k = 3;
        System.out.println("Max sum of subarray of size " + k + ": " +
                          mss.maxSumSubarrayOfSizeK(nums, k));  // 9 (5+1+3)

        // Test 2: Longest substring without repeating
        String s1 = "abcabcbb";
        System.out.println("Longest substring without repeating in '" + s1 + "': " +
                          mss.lengthOfLongestSubstring(s1));  // 3 ("abc")

        // Test 3: Minimum window substring
        String s = "ADOBECODEBANC";
        String t = "ABC";
        System.out.println("Minimum window substring: " +
                          mss.minWindowSubstring(s, t));  // "BANC"
    }
}

/*
 * Sliding Window Technique
 *
 * Types:
 * 1. Fixed Size Window: Window size is constant (k)
 *    - Max/Min sum of size k
 *    - First negative in every window
 *
 * 2. Variable Size Window: Window size varies based on condition
 *    - Longest substring with k distinct characters
 *    - Minimum window substring
 *
 * Pattern:
 * - Use two pointers (left, right)
 * - Expand right to include elements
 * - Shrink left when condition violated
 * - Track answer during expansion or shrinking
 *
 * Time Complexity: O(n) - each element visited at most twice
 * Space Complexity: O(1) or O(k) depending on problem
 */
