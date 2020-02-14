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
    boolean b = true;
    boolean exception1 = true;
    boolean exception2 = true;
    public boolean dfs(TreeNode root, int min, int max) {
        if(root.left != null) {
            int rlv = root.left.val;
            if(rlv >= root.val || rlv <= min || rlv >= max) {
                if(rlv == Integer.MIN_VALUE && min == Integer.MIN_VALUE && exception1) {
                    exception1 = false;
                    dfs(root.left, Math.min(min, root.val), Math.min(max, root.val));
                }
                else {
                    b = false;
                    return false;
                }
            }
            dfs(root.left, Math.min(min, root.val), Math.min(max, root.val));
        }
        if(root.right != null) {
            int rrv = root.right.val;
            if(rrv <= root.val || rrv <= min || rrv >= max) {
                if(rrv == Integer.MAX_VALUE && max == Integer.MAX_VALUE && exception2) {
                    exception2 = false;
                    dfs(root.right, Math.max(min, root.val), Math.max(max, root.val));
                }
                else {
                    b = false;
                    return false;
                }
            }
            dfs(root.right, Math.max(min, root.val), Math.max(max, root.val));
        }
        return true;
    }
    public boolean isValidBST(TreeNode root) {
        if(root == null) {
            return true;
        }
        if(root.val == Integer.MIN_VALUE) {
            exception1 = false;
        }
        if(root.val == Integer.MAX_VALUE) {
            exception2 = false;
        }
        dfs(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
        return b;
    }
}