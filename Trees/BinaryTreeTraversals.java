import java.util.*;

public class BinaryTreeTraversals {

    // Tree Node Definition
    static class TreeNode {
        int val;
        TreeNode left, right;

        TreeNode(int val) {
            this.val = val;
            this.left = this.right = null;
        }
    }

    // ============ RECURSIVE TRAVERSALS ============

    // Inorder: Left -> Root -> Right
    public void inorderRecursive(TreeNode root, List<Integer> result) {
        if (root == null) return;
        inorderRecursive(root.left, result);
        result.add(root.val);
        inorderRecursive(root.right, result);
    }

    // Preorder: Root -> Left -> Right
    public void preorderRecursive(TreeNode root, List<Integer> result) {
        if (root == null) return;
        result.add(root.val);
        preorderRecursive(root.left, result);
        preorderRecursive(root.right, result);
    }

    // Postorder: Left -> Right -> Root
    public void postorderRecursive(TreeNode root, List<Integer> result) {
        if (root == null) return;
        postorderRecursive(root.left, result);
        postorderRecursive(root.right, result);
        result.add(root.val);
    }

    // ============ ITERATIVE TRAVERSALS ============

    // Inorder Iterative using Stack
    public List<Integer> inorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;

        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }
            curr = stack.pop();
            result.add(curr.val);
            curr = curr.right;
        }

        return result;
    }

    // Preorder Iterative using Stack
    public List<Integer> preorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            result.add(node.val);

            if (node.right != null) stack.push(node.right);
            if (node.left != null) stack.push(node.left);
        }

        return result;
    }

    // Postorder Iterative using Two Stacks
    public List<Integer> postorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        s1.push(root);

        while (!s1.isEmpty()) {
            TreeNode node = s1.pop();
            s2.push(node);

            if (node.left != null) s1.push(node.left);
            if (node.right != null) s1.push(node.right);
        }

        while (!s2.isEmpty()) {
            result.add(s2.pop().val);
        }

        return result;
    }

    // Level Order Traversal (BFS)
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                level.add(node.val);

                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }

            result.add(level);
        }

        return result;
    }

    // ============ TREE PROPERTIES ============

    // Height of tree
    public int height(TreeNode root) {
        if (root == null) return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }

    // Count nodes
    public int countNodes(TreeNode root) {
        if (root == null) return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    // Diameter of tree (longest path between any two nodes)
    private int diameter;

    public int diameterOfTree(TreeNode root) {
        diameter = 0;
        heightForDiameter(root);
        return diameter;
    }

    private int heightForDiameter(TreeNode root) {
        if (root == null) return 0;

        int leftHeight = heightForDiameter(root.left);
        int rightHeight = heightForDiameter(root.right);

        diameter = Math.max(diameter, leftHeight + rightHeight);

        return 1 + Math.max(leftHeight, rightHeight);
    }

    // Check if balanced
    public boolean isBalanced(TreeNode root) {
        return checkBalance(root) != -1;
    }

    private int checkBalance(TreeNode root) {
        if (root == null) return 0;

        int left = checkBalance(root.left);
        if (left == -1) return -1;

        int right = checkBalance(root.right);
        if (right == -1) return -1;

        if (Math.abs(left - right) > 1) return -1;

        return 1 + Math.max(left, right);
    }

    // Lowest Common Ancestor (LCA)
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null) return root;
        return left != null ? left : right;
    }

    // Build tree from given traversals
    public static void main(String[] args) {
        BinaryTreeTraversals btt = new BinaryTreeTraversals();

        /*
         * Build this tree:
         *        1
         *       / \
         *      2   3
         *     / \   \
         *    4   5   6
         */
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.right = new TreeNode(6);

        // Recursive traversals
        List<Integer> inorder = new ArrayList<>();
        List<Integer> preorder = new ArrayList<>();
        List<Integer> postorder = new ArrayList<>();

        btt.inorderRecursive(root, inorder);
        btt.preorderRecursive(root, preorder);
        btt.postorderRecursive(root, postorder);

        System.out.println("=== Recursive Traversals ===");
        System.out.println("Inorder:   " + inorder);    // [4, 2, 5, 1, 3, 6]
        System.out.println("Preorder:  " + preorder);   // [1, 2, 4, 5, 3, 6]
        System.out.println("Postorder: " + postorder);  // [4, 5, 2, 6, 3, 1]

        // Iterative traversals
        System.out.println("\n=== Iterative Traversals ===");
        System.out.println("Inorder:   " + btt.inorderIterative(root));
        System.out.println("Preorder:  " + btt.preorderIterative(root));
        System.out.println("Postorder: " + btt.postorderIterative(root));

        // Level order
        System.out.println("\n=== Level Order ===");
        System.out.println("Level order: " + btt.levelOrder(root));  // [[1], [2,3], [4,5,6]]

        // Tree properties
        System.out.println("\n=== Tree Properties ===");
        System.out.println("Height: " + btt.height(root));  // 3
        System.out.println("Total nodes: " + btt.countNodes(root));  // 6
        System.out.println("Diameter: " + btt.diameterOfTree(root));  // 4
        System.out.println("Is balanced: " + btt.isBalanced(root));  // true
    }
}

/*
 * Binary Tree Traversals Summary
 *
 * DFS Traversals:
 * - Inorder (LNR):   Left -> Node -> Right   [Sorted for BST]
 * - Preorder (NLR):  Node -> Left -> Right   [Copy tree]
 * - Postorder (LRN): Left -> Right -> Node   [Delete tree]
 *
 * BFS Traversal:
 * - Level Order: Visit nodes level by level
 *
 * Time Complexity: O(n) for all traversals
 * Space Complexity: O(h) for recursive, O(n) for level order
 *                   where h = height of tree
 *
 * Common Problems:
 * - Height/Depth of tree
 * - Diameter (longest path)
 * - Check if balanced
 * - LCA (Lowest Common Ancestor)
 * - Path sum problems
 * - Serialize/Deserialize tree
 */
