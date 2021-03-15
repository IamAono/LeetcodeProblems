/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int sum;
    public int dfs(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int left = Math.max(0, dfs(root.left));
        int right = Math.max(0, dfs(root.right));
        sum = Math.max(sum, left + right + root.val);
        return Math.max(left, right) + root.val;
    }
    public int maxPathSum(TreeNode root) {
        sum = Integer.MIN_VALUE;
        dfs(root);
        return sum;
    }
}