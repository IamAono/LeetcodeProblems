/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null) {
            return head;
        }
        ListNode l = head;
        if(head.next == null) {
            return head;
        }
        ListNode l2 = head.next;
        ListNode l3 = head.next;
        while(l.next != null && l2.next != null) {
            l.next = l2.next;
            l = l.next;
            if(l.next != null) {
                l2.next = l.next;
                l2 = l2.next;
            }
            else {
                l2.next = null;
            }
        }
        l.next = l3;
        return head;
    }
}