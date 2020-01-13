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
    public List<Integer> rightSideView(TreeNode root) {
        Map<Integer, Integer> rightmostValueAtDepth = new HashMap<Integer, Integer>();
        int maxDepth = -1;
        Stack<TreeNode> nodes = new Stack<TreeNode>();
        Stack<Integer> depths = new Stack<Integer>();
        nodes.push(root);
        depths.push(0);
        while(!nodes.isEmpty()) {
            TreeNode current = nodes.pop();
            int depth = depths.pop();
            if(current != null) {
                maxDepth = Math.max(maxDepth, depth);
                if(!rightmostValueAtDepth.containsKey(depth)) {
                    rightmostValueAtDepth.put(depth, current.val);
                }
                nodes.push(current.left);
                nodes.push(current.right);
                depths.push(depth+1);
                depths.push(depth+1);
            }
        }
        List<Integer> rightView = new ArrayList<Integer>();
        for(int depth = 0; depth <= maxDepth; depth++) {
            rightView.add(rightmostValueAtDepth.get(depth));
        }
        return rightView;
    }
}