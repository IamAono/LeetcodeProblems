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
    public int minDiffInBST(TreeNode root) {
        List<Integer> l = new ArrayList<Integer>();
        Stack<TreeNode> s = new Stack<TreeNode>();
        s.push(root);
        while(!s.isEmpty()) {
            TreeNode t = s.pop();
            l.add(t.val);
            if(t.left != null) {
                s.push(t.left);
            }
            if(t.right != null) {
                s.push(t.right);
            }
        }
        Collections.sort(l);
        int minDif = Integer.MAX_VALUE;
        for(int i = 1; i < l.size(); i++) {
            minDif = Math.min(minDif, l.get(i) - l.get(i - 1));
        }
        return minDif;
    }
}