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
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		vector<int> v;
		if (lists.size() == 0) {
			return NULL;
		}
		for (int i = 0; i < lists.size(); i++) {
			if (lists.at(i)) {
				ListNode * c = lists.at(i);
				while (true) {
					v.push_back(c->val);
					if (c->next) {
						c = c->next;
					}
					else {
						break;
					}
				}
			}
		}
		if (v.size() == 0) {
			return NULL;
		}
		sort(v.begin(), v.end());
		ListNode * f = new ListNode(v.at(0));
		ListNode * f2 = f;
		if (v.size() > 1) {
			for (int i = 1; i < v.size(); i++) {
				ListNode * f3 = new ListNode(v.at(i));
				f2->next = f3;
				f2 = f3;
			}
		}
		return f;
	}
};