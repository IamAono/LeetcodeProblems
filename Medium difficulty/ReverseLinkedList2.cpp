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
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		vector<ListNode*> c;
		bool b = false;
		ListNode * current = head;
		ListNode * before = current;
		int m2 = 1;
		if (m == 1) {
			b = true;
		}
		if (n == m) {
			return head;
		}
		while (true) {
			if (m2 == m - 1) {
				before = current;
				b = true;
			}
			else if (b) {
				c.push_back(current);
			}
			if (m2 == n) {
				if (!current->next) {
					c.at(0)->next = NULL;
				}
				else {
					c.at(0)->next = current->next;
				}
				break;
			}
			m2++;
			current = current->next;
		}
		for (int i = 1; i < c.size(); i++) {
			c.at(i)->next = c.at(i - 1);
		}
		if (m == 1) {
			return c.at(c.size() - 1);
		}
		else {
			before->next = c.at(c.size() - 1);
		}
		return head;
	}
};