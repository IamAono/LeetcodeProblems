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
	ListNode * reverseList(ListNode* head) {
		if (!head || !head->next) {
			return head;
		}
		ListNode* current = head;
		ListNode* ln = current->next;
		ListNode* temp = NULL;
		while (ln) {
			temp = current;
			current = ln;
			ln = current->next;
			current->next = temp;
		}
		head->next = NULL;
		return current;
	}
};