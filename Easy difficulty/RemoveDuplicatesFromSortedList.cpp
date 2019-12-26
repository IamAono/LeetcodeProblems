/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		if (!head) {
			return head;
		}
		ListNode* l = head;
		while (l->next) {
			int val = l->next->val;
			ListNode* l2 = l->next;
			while (val == l->val) {
				if (l2->next) {
					val = l2->next->val;
					l2 = l2->next;
				}
				else {
					l->next = NULL;
					return head;
				}
			}
			l->next = l2;
			l = l->next;
		}
		return head;
	}
};