/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        List<ListNode> l = new ArrayList<ListNode>();
        List<ListNode> l2 = new ArrayList<ListNode>();
        ListNode t = head;
        if(head == null) {
            return null;
        }
        while(true) {
            if(t.val < x) {
                l.add(t);
            }
            else {
                l2.add(t);
            }
            if(t.next == null) {
                break;
            }
            t = t.next;
        }
        if(l.size() == 0) {
            return head;
        }
        if(l.size() == 1) {
            ListNode t2 = l.get(0);
            if(l2.size() == 0) {
                return t2;
            }
            else {
                ListNode n = l2.get(0);
                t2.next = n;
                int i = 0;
                while(true) {
                    if(i == l2.size() - 1) {
                        n.next = null;
                        break;
                    }
                    i++;
                    n.next = l2.get(i);
                    n = n.next;
                }
            }
            return t2;
        }
        for(int i = 0; i < l.size() - 1; i++) {
            ListNode t3 = l.get(i);
            t3.next = l.get(i + 1);
        }
        head = l.get(0);
        ListNode t4 = l.get(l.size() - 1);
        if(l2.size() > 0) {
            t4.next = l2.get(0);
            int i = 0;
            t4 = t4.next;
            while(true) {
                if(i == l2.size() - 1) {
                    t4.next = null;
                    break;
                }
                i++;
                t4.next = l2.get(i);
                t4 = t4.next;
            }
        }
        return head;
    }
}