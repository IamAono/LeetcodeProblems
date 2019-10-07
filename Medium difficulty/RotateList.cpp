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
	ListNode * rotateRight(ListNode* head, int k) {
		if (!head) {
			return NULL;
		}
		if (!head->next) {
			return head;
		}
		int count = 1;
		ListNode * t = head;
		while (t->next) {
			t = t->next;
			count++;
		}
		k = k % count;
		if (!head->next->next) {
			while (k--) {
				ListNode * tempHead = head;
				head = head->next;
				head->next = tempHead;
				head->next->next = NULL;
			}
			return head;
		}
		while (k--) {
			ListNode * tempHead = head;
			ListNode * current = head;
			while (current->next->next) {
				current = current->next;
				if (!current->next->next) {
					head = current->next;
					head->next = tempHead;
					current->next = NULL;
					break;
				}
			}
		}
		return head;
	}
};