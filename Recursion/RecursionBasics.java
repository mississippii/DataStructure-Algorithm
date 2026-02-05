import java.util.*;

public class RecursionBasics {

    // 1. Factorial
    public int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    // 2. Fibonacci
    public int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    // 3. Sum of digits
    public int sumOfDigits(int n) {
        if (n == 0) return 0;
        return (n % 10) + sumOfDigits(n / 10);
    }

    // 4. Power function
    public long power(int base, int exp) {
        if (exp == 0) return 1;
        if (exp % 2 == 0) {
            long half = power(base, exp / 2);
            return half * half;
        }
        return base * power(base, exp - 1);
    }

    // 5. Reverse a string
    public String reverseString(String s) {
        if (s.isEmpty()) return s;
        return reverseString(s.substring(1)) + s.charAt(0);
    }

    // 6. Check palindrome
    public boolean isPalindrome(String s, int left, int right) {
        if (left >= right) return true;
        if (s.charAt(left) != s.charAt(right)) return false;
        return isPalindrome(s, left + 1, right - 1);
    }

    // 7. Tower of Hanoi
    public void towerOfHanoi(int n, char source, char auxiliary, char destination) {
        if (n == 1) {
            System.out.println("Move disk 1 from " + source + " to " + destination);
            return;
        }
        towerOfHanoi(n - 1, source, destination, auxiliary);
        System.out.println("Move disk " + n + " from " + source + " to " + destination);
        towerOfHanoi(n - 1, auxiliary, source, destination);
    }

    // 8. Print all subsequences of a string
    public void printSubsequences(String s, int index, String current) {
        if (index == s.length()) {
            System.out.println(current.isEmpty() ? "\"\"" : current);
            return;
        }

        // Exclude current character
        printSubsequences(s, index + 1, current);

        // Include current character
        printSubsequences(s, index + 1, current + s.charAt(index));
    }

    // 9. Generate all permutations
    public List<String> permutations(String s) {
        List<String> result = new ArrayList<>();
        permute(s.toCharArray(), 0, result);
        return result;
    }

    private void permute(char[] arr, int index, List<String> result) {
        if (index == arr.length) {
            result.add(new String(arr));
            return;
        }

        for (int i = index; i < arr.length; i++) {
            swap(arr, index, i);
            permute(arr, index + 1, result);
            swap(arr, index, i);  // Backtrack
        }
    }

    private void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // 10. Generate balanced parentheses
    public List<String> generateParentheses(int n) {
        List<String> result = new ArrayList<>();
        generateParens(n, 0, 0, "", result);
        return result;
    }

    private void generateParens(int n, int open, int close, String current, List<String> result) {
        if (current.length() == 2 * n) {
            result.add(current);
            return;
        }

        if (open < n) {
            generateParens(n, open + 1, close, current + "(", result);
        }
        if (close < open) {
            generateParens(n, open, close + 1, current + ")", result);
        }
    }

    // 11. Binary Search (recursive)
    public int binarySearch(int[] arr, int target, int left, int right) {
        if (left > right) return -1;

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearch(arr, target, left, mid - 1);
        return binarySearch(arr, target, mid + 1, right);
    }

    public static void main(String[] args) {
        RecursionBasics rb = new RecursionBasics();

        // Test factorial
        System.out.println("Factorial of 5: " + rb.factorial(5));  // 120

        // Test fibonacci
        System.out.println("Fibonacci(10): " + rb.fibonacci(10));  // 55

        // Test sum of digits
        System.out.println("Sum of digits of 12345: " + rb.sumOfDigits(12345));  // 15

        // Test power
        System.out.println("2^10: " + rb.power(2, 10));  // 1024

        // Test reverse string
        System.out.println("Reverse 'hello': " + rb.reverseString("hello"));  // olleh

        // Test palindrome
        System.out.println("Is 'racecar' palindrome? " +
                          rb.isPalindrome("racecar", 0, 6));  // true

        // Test Tower of Hanoi
        System.out.println("\nTower of Hanoi (3 disks):");
        rb.towerOfHanoi(3, 'A', 'B', 'C');

        // Test subsequences
        System.out.println("\nSubsequences of 'abc':");
        rb.printSubsequences("abc", 0, "");

        // Test permutations
        System.out.println("\nPermutations of 'abc': " + rb.permutations("abc"));

        // Test generate parentheses
        System.out.println("\nBalanced parentheses (n=3): " + rb.generateParentheses(3));

        // Test binary search
        int[] arr = {1, 3, 5, 7, 9, 11};
        System.out.println("\nBinary search for 7: " +
                          rb.binarySearch(arr, 7, 0, arr.length - 1));  // 3
    }
}

/*
 * Recursion Fundamentals
 *
 * Key Components:
 * 1. Base Case: Condition to stop recursion
 * 2. Recursive Case: Function calls itself with smaller input
 * 3. Progress: Each call should move towards base case
 *
 * Types of Recursion:
 * - Linear: One recursive call (factorial, fibonacci)
 * - Binary: Two recursive calls (merge sort, tree traversal)
 * - Multiple: Multiple recursive calls (permutations)
 * - Tail Recursion: Recursive call is last operation
 *
 * Common Patterns:
 * - Include/Exclude (subsequences, subsets)
 * - Swap and recurse (permutations)
 * - Divide and conquer (merge sort, quick sort)
 *
 * Time Complexity Analysis:
 * - Factorial: O(n)
 * - Fibonacci (naive): O(2^n)
 * - Fibonacci (memoized): O(n)
 * - Tower of Hanoi: O(2^n)
 * - Permutations: O(n!)
 */
