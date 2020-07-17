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
	ListNode * middleNode(ListNode* head) {
		vector<ListNode*> v;
		v.push_back(head);
		int count = 1;
		while (head->next) {
			v.push_back(head->next);
			head = head->next;
			count++;
		}
		return v.at(count / 2);
	}
};