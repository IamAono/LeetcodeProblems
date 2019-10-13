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
    ArrayList<String> ss = new ArrayList<String>();
    Stack<TreeNode> s = new Stack<TreeNode>();
    int sum = 0;
    public void f(String w) {    
        TreeNode current = s.pop();
        w += current.val;
        if(current.right == null && current.left == null) {
            ss.add(w);
        }
        if(current.right != null) {
            s.push(current.right);
            f(w);
        }
        if(current.left != null) {
            s.push(current.left);
            f(w);
        }
    }
    int sumNumbers(TreeNode root) {
        if(root == null) {
            return 0;
        }
        s.push(root);
        f("");
        for(int i = 0; i < ss.size(); i++) {
            sum += Integer.parseInt(ss.get(i));
        }
        return sum;
    }
}