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
    public int sumOfLeftLeaves(TreeNode root) {
        int sum = 0;
        Stack<TreeNode> nodes = new Stack<TreeNode>();
        nodes.push(root);
        while(!nodes.isEmpty()) {
            TreeNode current = nodes.pop();
            if(current != null) {
                if(current.left != null) {
                    if(current.left.left == null && current.left.right == null) {
                        sum += current.left.val;
                    }
                }
                nodes.push(current.left);
                nodes.push(current.right);
            }
        }
        return sum;
    }
}