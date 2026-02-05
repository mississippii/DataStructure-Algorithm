import java.util.*;

public class NextGreaterElement {

    // Next Greater Element to the Right
    public int[] nextGreaterRight(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();  // Stores indices

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements smaller than current
            while (!stack.isEmpty() && stack.peek() <= nums[i]) {
                stack.pop();
            }

            result[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(nums[i]);
        }

        return result;
    }

    // Next Greater Element to the Left
    public int[] nextGreaterLeft(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && stack.peek() <= nums[i]) {
                stack.pop();
            }

            result[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(nums[i]);
        }

        return result;
    }

    // Next Smaller Element to the Right
    public int[] nextSmallerRight(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() >= nums[i]) {
                stack.pop();
            }

            result[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(nums[i]);
        }

        return result;
    }

    // Valid Parentheses
    public boolean isValidParentheses(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;

                char top = stack.pop();
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }

        return stack.isEmpty();
    }

    // Min Stack - Stack that supports getMin() in O(1)
    static class MinStack {
        private Stack<Long> stack;
        private long minVal;

        public MinStack() {
            stack = new Stack<>();
        }

        public void push(int val) {
            if (stack.isEmpty()) {
                stack.push(0L);
                minVal = val;
            } else {
                stack.push((long) val - minVal);
                if (val < minVal) {
                    minVal = val;
                }
            }
        }

        public void pop() {
            long top = stack.pop();
            if (top < 0) {
                minVal = minVal - top;
            }
        }

        public int top() {
            long top = stack.peek();
            if (top < 0) {
                return (int) minVal;
            }
            return (int) (top + minVal);
        }

        public int getMin() {
            return (int) minVal;
        }
    }

    // Largest Rectangle in Histogram
    public int largestRectangleInHistogram(int[] heights) {
        int n = heights.length;
        int[] left = new int[n];   // Index of next smaller on left
        int[] right = new int[n];  // Index of next smaller on right

        Stack<Integer> stack = new Stack<>();

        // Find next smaller to left
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            left[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        stack.clear();

        // Find next smaller to right
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) {
                stack.pop();
            }
            right[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }

        // Calculate max area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = Math.max(maxArea, area);
        }

        return maxArea;
    }

    // Stock Span Problem
    public int[] stockSpan(int[] prices) {
        int n = prices.length;
        int[] span = new int[n];
        Stack<Integer> stack = new Stack<>();  // Stores indices

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && prices[stack.peek()] <= prices[i]) {
                stack.pop();
            }

            span[i] = stack.isEmpty() ? (i + 1) : (i - stack.peek());
            stack.push(i);
        }

        return span;
    }

    public static void main(String[] args) {
        NextGreaterElement nge = new NextGreaterElement();

        int[] nums = {4, 5, 2, 10, 8};

        // Next Greater Element
        System.out.println("Array: " + Arrays.toString(nums));
        System.out.println("NGE Right: " + Arrays.toString(nge.nextGreaterRight(nums)));
        // [5, 10, 10, -1, -1]

        System.out.println("NGE Left:  " + Arrays.toString(nge.nextGreaterLeft(nums)));
        // [-1, -1, 5, -1, 10]

        System.out.println("NSE Right: " + Arrays.toString(nge.nextSmallerRight(nums)));
        // [2, 2, -1, 8, -1]

        // Valid Parentheses
        System.out.println("\n=== Valid Parentheses ===");
        System.out.println("'()[]{}' is valid: " + nge.isValidParentheses("()[]{}"));  // true
        System.out.println("'([)]' is valid: " + nge.isValidParentheses("([)]"));  // false

        // Min Stack
        System.out.println("\n=== Min Stack ===");
        MinStack minStack = new MinStack();
        minStack.push(5);
        minStack.push(2);
        minStack.push(7);
        System.out.println("Min: " + minStack.getMin());  // 2
        minStack.pop();
        System.out.println("Top: " + minStack.top());  // 2
        minStack.pop();
        System.out.println("Min after pops: " + minStack.getMin());  // 5

        // Largest Rectangle in Histogram
        System.out.println("\n=== Largest Rectangle in Histogram ===");
        int[] heights = {2, 1, 5, 6, 2, 3};
        System.out.println("Heights: " + Arrays.toString(heights));
        System.out.println("Largest area: " + nge.largestRectangleInHistogram(heights));  // 10

        // Stock Span
        System.out.println("\n=== Stock Span ===");
        int[] prices = {100, 80, 60, 70, 60, 75, 85};
        System.out.println("Prices: " + Arrays.toString(prices));
        System.out.println("Span:   " + Arrays.toString(nge.stockSpan(prices)));
        // [1, 1, 1, 2, 1, 4, 6]
    }
}

/*
 * Monotonic Stack Problems
 *
 * What is Monotonic Stack?
 * - Stack that maintains elements in sorted order (increasing or decreasing)
 * - Used to find next/previous greater/smaller elements efficiently
 *
 * Patterns:
 * 1. Next Greater Element (Right): Traverse right to left, maintain decreasing stack
 * 2. Next Greater Element (Left): Traverse left to right, maintain decreasing stack
 * 3. Next Smaller Element: Same pattern but maintain increasing stack
 *
 * Template:
 *   for (traverse array) {
 *       while (stack not empty AND condition) {
 *           stack.pop();
 *       }
 *       result[i] = stack.isEmpty() ? default : stack.peek();
 *       stack.push(current);
 *   }
 *
 * Time Complexity: O(n) - each element pushed and popped at most once
 * Space Complexity: O(n) for the stack
 *
 * Classic Problems:
 * - Next Greater Element I, II
 * - Daily Temperatures
 * - Largest Rectangle in Histogram
 * - Trapping Rain Water
 * - Stock Span Problem
 * - Min Stack
 */
