import java.util.*;

public class TwoSum {

    // Two Sum II - Sorted Array (Two Pointers)
    public int[] twoSumSorted(int[] nums, int target) {
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                return new int[]{left, right};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return new int[]{-1, -1};
    }

    // Three Sum - Find all triplets that sum to zero
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            // Skip duplicates for first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.length - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }

    // Container With Most Water
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int maxArea = 0;

        while (left < right) {
            int width = right - left;
            int h = Math.min(height[left], height[right]);
            maxArea = Math.max(maxArea, width * h);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }

    // Remove Duplicates from Sorted Array (in-place)
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;

        int slow = 0;

        for (int fast = 1; fast < nums.length; fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

    // Valid Palindrome (ignore non-alphanumeric)
    public boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }
            while (left < right && !Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }

            if (Character.toLowerCase(s.charAt(left)) !=
                Character.toLowerCase(s.charAt(right))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    public static void main(String[] args) {
        TwoSum ts = new TwoSum();

        // Test Two Sum Sorted
        int[] nums1 = {2, 7, 11, 15};
        int[] result1 = ts.twoSumSorted(nums1, 9);
        System.out.println("Two Sum Sorted: [" + result1[0] + ", " + result1[1] + "]");  // [0, 1]

        // Test Three Sum
        int[] nums2 = {-1, 0, 1, 2, -1, -4};
        System.out.println("Three Sum: " + ts.threeSum(nums2));  // [[-1,-1,2],[-1,0,1]]

        // Test Container With Most Water
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        System.out.println("Max Water: " + ts.maxArea(height));  // 49

        // Test Remove Duplicates
        int[] nums3 = {1, 1, 2, 2, 3};
        int newLen = ts.removeDuplicates(nums3);
        System.out.print("After removing duplicates: ");
        for (int i = 0; i < newLen; i++) System.out.print(nums3[i] + " ");
        System.out.println();  // 1 2 3

        // Test Palindrome
        System.out.println("Is 'A man, a plan, a canal: Panama' palindrome? " +
                          ts.isPalindrome("A man, a plan, a canal: Panama"));  // true
    }
}

/*
 * Two Pointers Technique
 *
 * Patterns:
 * 1. Opposite Direction: Start from both ends, move towards center
 *    - Two Sum (sorted), Palindrome check, Container with most water
 *
 * 2. Same Direction (Fast-Slow): Both start from beginning
 *    - Remove duplicates, Linked list cycle detection
 *
 * When to Use:
 * - Array is sorted (or can be sorted)
 * - Need to find pairs/triplets with specific sum
 * - Need to compare elements from both ends
 * - In-place array modifications
 *
 * Time Complexity: Usually O(n) or O(n log n) if sorting needed
 * Space Complexity: O(1) - no extra space
 */
