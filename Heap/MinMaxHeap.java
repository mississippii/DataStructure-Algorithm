import java.util.*;

public class MinMaxHeap {

    // Min Heap Implementation from scratch
    static class MinHeap {
        private int[] heap;
        private int size;
        private int capacity;

        public MinHeap(int capacity) {
            this.capacity = capacity;
            this.size = 0;
            this.heap = new int[capacity];
        }

        private int parent(int i) { return (i - 1) / 2; }
        private int leftChild(int i) { return 2 * i + 1; }
        private int rightChild(int i) { return 2 * i + 2; }

        private void swap(int i, int j) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        // Insert element - O(log n)
        public void insert(int val) {
            if (size == capacity) {
                System.out.println("Heap is full!");
                return;
            }

            heap[size] = val;
            int current = size;
            size++;

            // Heapify up
            while (current > 0 && heap[current] < heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }

        // Extract minimum - O(log n)
        public int extractMin() {
            if (size == 0) {
                throw new IllegalStateException("Heap is empty!");
            }

            int min = heap[0];
            heap[0] = heap[size - 1];
            size--;

            // Heapify down
            heapifyDown(0);

            return min;
        }

        private void heapifyDown(int i) {
            int smallest = i;
            int left = leftChild(i);
            int right = rightChild(i);

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != i) {
                swap(i, smallest);
                heapifyDown(smallest);
            }
        }

        public int peek() {
            if (size == 0) throw new IllegalStateException("Heap is empty!");
            return heap[0];
        }

        public int size() { return size; }
        public boolean isEmpty() { return size == 0; }

        public void printHeap() {
            System.out.print("Heap: ");
            for (int i = 0; i < size; i++) {
                System.out.print(heap[i] + " ");
            }
            System.out.println();
        }
    }

    // Kth Largest Element using Min Heap
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int num : nums) {
            minHeap.offer(num);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }

        return minHeap.peek();
    }

    // Kth Smallest Element using Max Heap
    public int findKthSmallest(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        for (int num : nums) {
            maxHeap.offer(num);
            if (maxHeap.size() > k) {
                maxHeap.poll();
            }
        }

        return maxHeap.peek();
    }

    // Top K Frequent Elements
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // Min heap based on frequency
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(
            (a, b) -> freq.get(a) - freq.get(b)
        );

        for (int num : freq.keySet()) {
            minHeap.offer(num);
            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }

        int[] result = new int[k];
        for (int i = k - 1; i >= 0; i--) {
            result[i] = minHeap.poll();
        }

        return result;
    }

    // Merge K Sorted Arrays
    public int[] mergeKSortedArrays(int[][] arrays) {
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int totalSize = 0;

        // Add first element of each array: [value, arrayIndex, elementIndex]
        for (int i = 0; i < arrays.length; i++) {
            if (arrays[i].length > 0) {
                minHeap.offer(new int[]{arrays[i][0], i, 0});
                totalSize += arrays[i].length;
            }
        }

        int[] result = new int[totalSize];
        int idx = 0;

        while (!minHeap.isEmpty()) {
            int[] curr = minHeap.poll();
            result[idx++] = curr[0];

            int arrIdx = curr[1];
            int elemIdx = curr[2];

            if (elemIdx + 1 < arrays[arrIdx].length) {
                minHeap.offer(new int[]{arrays[arrIdx][elemIdx + 1], arrIdx, elemIdx + 1});
            }
        }

        return result;
    }

    public static void main(String[] args) {
        MinMaxHeap mmh = new MinMaxHeap();

        // Test custom Min Heap
        System.out.println("=== Custom Min Heap ===");
        MinHeap minHeap = new MinHeap(10);
        minHeap.insert(5);
        minHeap.insert(3);
        minHeap.insert(8);
        minHeap.insert(1);
        minHeap.insert(6);
        minHeap.printHeap();  // 1 3 8 5 6
        System.out.println("Extract min: " + minHeap.extractMin());  // 1
        minHeap.printHeap();  // 3 5 8 6

        // Test Kth Largest
        System.out.println("\n=== Kth Largest ===");
        int[] nums1 = {3, 2, 1, 5, 6, 4};
        System.out.println("2nd largest: " + mmh.findKthLargest(nums1, 2));  // 5

        // Test Top K Frequent
        System.out.println("\n=== Top K Frequent ===");
        int[] nums2 = {1, 1, 1, 2, 2, 3};
        int[] topK = mmh.topKFrequent(nums2, 2);
        System.out.print("Top 2 frequent: ");
        for (int n : topK) System.out.print(n + " ");
        System.out.println();  // 1 2

        // Test Merge K Sorted Arrays
        System.out.println("\n=== Merge K Sorted Arrays ===");
        int[][] arrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
        int[] merged = mmh.mergeKSortedArrays(arrays);
        System.out.print("Merged: ");
        for (int n : merged) System.out.print(n + " ");
        System.out.println();  // 1 2 3 4 5 6 7 8 9
    }
}

/*
 * Heap Data Structure
 *
 * Properties:
 * - Complete Binary Tree
 * - Min Heap: Parent <= Children
 * - Max Heap: Parent >= Children
 *
 * Operations:
 * - Insert: O(log n)
 * - Extract Min/Max: O(log n)
 * - Peek: O(1)
 * - Build Heap: O(n)
 *
 * Java PriorityQueue:
 * - Min Heap (default): new PriorityQueue<>()
 * - Max Heap: new PriorityQueue<>(Collections.reverseOrder())
 * - Custom: new PriorityQueue<>((a, b) -> comparator)
 *
 * Common Problems:
 * - Kth Largest/Smallest Element
 * - Top K Frequent Elements
 * - Merge K Sorted Lists/Arrays
 * - Median in Stream
 */
