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
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		if (!head->next) {
			return NULL;
		}
		ListNode * current = head;
		while (current->next) {
			ListNode * temp = current;
			int n2 = 0;
			while (n2 < n) {
				if (!temp->next) {
					head = head->next;
					return head;
				}
				temp = temp->next;
				n2++;
				if (n2 == n && !temp->next) {
					current->next = current->next->next;
					return head;
				}
			}
			current = current->next;
		}
		return head;
	}
};