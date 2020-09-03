/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> a = new ArrayList<Integer>();
        if(root == null) {
            return a;
        }
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        while(!q.isEmpty()) {
            int qs = q.size();
            int largest = Integer.MIN_VALUE;
            while(qs > 0) {
                TreeNode t = q.remove();
                if(t.val > largest) {
                    largest = t.val;
                }
                if(t.left != null) {
                    q.add(t.left);
                }
                if(t.right != null) {
                    q.add(t.right);
                }
                qs--;
            }
            a.add(largest);
        }
        return a;
    }
}