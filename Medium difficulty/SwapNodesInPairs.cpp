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
	ListNode * swapPairs(ListNode* head) {
		if (!head) {
			return head;
		}
		int e = 0;
		ListNode * current = head;
		while (current->next) {
			if (e % 2 == 0) {
				int temp = current->val;
				current->val = current->next->val;
				current->next->val = temp;
			}
			e++;
			current = current->next;
		}
		return head;
	}
};