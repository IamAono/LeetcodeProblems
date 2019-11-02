/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {
    List<Integer> l = new ArrayList<Integer>();
    public BSTIterator(TreeNode root) {
        Stack<TreeNode> s = new Stack<TreeNode>();
        if(root != null) {
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
        }
        
    }
    
    /** @return the next smallest number */
    public int next() {
        int i = l.get(0);
        l.remove(0);
        return i;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        if(l.size() == 0) {
            return false;
        }
        return true;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */