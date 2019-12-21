/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if(root == null) {
            return root;
        }
        root.next = null;
        Queue<Node> q = new LinkedList<>();
        List<Node> l = new ArrayList<Node>();
        q.add(root);
        int c = 0;
        int p = 0;
        while(q.size() != 0) {
            Node n = q.remove();
            l.add(n);
            if(n.left != null) {
                q.add(n.left);
            }
            if(n.right != null) {
                q.add(n.right);
            }
        }
        for(int i = 0; i < l.size(); i++) {
            c++;
            if(c == Math.pow(2,p)) {
                l.get(i).next = null;
                p++;
                c = 0;
            }
            else {
                l.get(i).next = l.get(i + 1);
            }
        }
        return root;
    }
    
}