public class SingleNumber {

    // Problem 1: Every element appears twice except one (XOR approach)
    public int singleNumberI(int[] nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }

    // Problem 2: Every element appears three times except one (Bit counting)
    public int singleNumberII(int[] nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int num : nums) {
                cnt += (num >> i) & 1;
            }
            ans |= (cnt % 3) << i;
        }
        return ans;
    }

    // Count set bits (Brian Kernighan's Algorithm)
    public int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);  // Removes rightmost set bit
            count++;
        }
        return count;
    }

    // Check if power of 2
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    // Get ith bit
    public int getBit(int n, int i) {
        return (n >> i) & 1;
    }

    // Set ith bit
    public int setBit(int n, int i) {
        return n | (1 << i);
    }

    // Clear ith bit
    public int clearBit(int n, int i) {
        return n & ~(1 << i);
    }

    // Toggle ith bit
    public int toggleBit(int n, int i) {
        return n ^ (1 << i);
    }

    public static void main(String[] args) {
        SingleNumber sn = new SingleNumber();

        // Test Single Number I (appears twice except one)
        int[] nums1 = {4, 1, 2, 1, 2};
        System.out.println("Single Number I: " + sn.singleNumberI(nums1));  // 4

        // Test Single Number II (appears thrice except one)
        int[] nums2 = {2, 2, 3, 2};
        System.out.println("Single Number II: " + sn.singleNumberII(nums2));  // 3

        // Test count set bits
        System.out.println("Set bits in 13 (1101): " + sn.countSetBits(13));  // 3

        // Test power of 2
        System.out.println("Is 16 power of 2? " + sn.isPowerOfTwo(16));  // true
        System.out.println("Is 18 power of 2? " + sn.isPowerOfTwo(18));  // false

        // Bit operations on 13 (1101)
        int n = 13;
        System.out.println("\nBit operations on " + n + " (binary: " + Integer.toBinaryString(n) + "):");
        System.out.println("Get bit 2: " + sn.getBit(n, 2));      // 1
        System.out.println("Set bit 1: " + sn.setBit(n, 1));      // 15 (1111)
        System.out.println("Clear bit 2: " + sn.clearBit(n, 2));  // 9 (1001)
        System.out.println("Toggle bit 0: " + sn.toggleBit(n, 0)); // 12 (1100)
    }
}

/*
 * Bit Manipulation Techniques
 *
 * Key Operations:
 * - AND (&): Both bits must be 1
 * - OR (|): At least one bit must be 1
 * - XOR (^): Bits must be different (a ^ a = 0, a ^ 0 = a)
 * - NOT (~): Flip all bits
 * - Left Shift (<<): Multiply by 2^n
 * - Right Shift (>>): Divide by 2^n
 *
 * Common Tricks:
 * - n & (n-1): Removes rightmost set bit
 * - n & (-n): Isolates rightmost set bit
 * - n | (1 << i): Set ith bit
 * - n & ~(1 << i): Clear ith bit
 * - n ^ (1 << i): Toggle ith bit
 */
