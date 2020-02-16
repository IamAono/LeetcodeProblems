/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        String s = "";
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if(root != null) {
            q.add(root);
            s += root.val;
            s += ",";
        }
        else {
            return s;
        }
        while(q.size() > 0) {
            TreeNode t = q.remove();
            if(t.left != null) {
                q.add(t.left);
                s += t.left.val;
                s += ",";
            }
            else {
                s += "null,";
            }
            if(t.right != null) {
                q.add(t.right);
                s += t.right.val;
                s += ",";
            }
            else {
                s += "null,";
            }
        }
        if(s.length() >= 12) {
            String s2 = s.substring(s.length() - 10, s.length());
            while(s2.equals("null,null,")) {
                s = s.substring(0, s.length() - 10);
                if(s.length() >= 12) {
                    s2 = s.substring(s.length() - 10, s.length());
                }
                else {
                    break;
                }
            }
        }
        s = s.substring(0, s.length() - 1);
        return s;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.length() == 0) {
            return null;
        }
        String[] s = data.split(",");
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if(s[0] != "null") {
            TreeNode t = new TreeNode(Integer.parseInt(s[0]));
            q.add(t);
        }
        TreeNode root = q.peek();
        int i = 0;
        while(q.size() > 0) {
            TreeNode t = q.remove();
            i++;
            if(i == s.length) {
                break;
            }
            if(!s[i].equals("null")) {
                TreeNode t2 = new TreeNode(Integer.parseInt(s[i]));
                t.left = t2;
                q.add(t2);
            }
            else {
                t.left = null;
            }
            i++;
            if(i == s.length) {
                break;
            }
            if(!s[i].equals("null")) {
                TreeNode t2 = new TreeNode(Integer.parseInt(s[i]));
                t.right = t2;
                q.add(t2);
            }
            else {
                t.right = null;
            }
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));