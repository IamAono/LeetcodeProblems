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
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		int sum = 0;
		bool carry = false;
		sum += l1->val;
		sum += l2->val;
		if (sum >= 10) {
			carry = true;
			sum = sum % 10;
		}
		ListNode * current = new ListNode(sum);
		ListNode * first = new ListNode(sum);
		first->next = current;
		while (l1->next || l2->next) {
			sum = 0;
			if (carry) {
				sum++;
				carry = false;
			}
			if (l1->next) {
				l1 = l1->next;
				sum += l1->val;
			}
			if (l2->next) {
				l2 = l2->next;
				sum += l2->val;
			}
			if (sum >= 10) {
				carry = true;
				sum = sum % 10;
			}
			ListNode * n = new ListNode(sum);
			current->next = n;
			current = current->next;
		}
		if (carry) {
			ListNode * n = new ListNode(1);
			current->next = n;
		}
		first = first->next;
		return first;
	}
};