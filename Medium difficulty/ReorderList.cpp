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
	void reorderList(ListNode* head) {
		if (head) {
			ListNode* ln = head;
			vector<ListNode*> v;
			v.push_back(ln);
			while (ln->next) {
				ln = ln->next;
				v.push_back(ln);
			}
			int s = 0;
			int e = v.size() - 1;
			while (s < e) {
				ListNode* h = v.at(s);
				ListNode* t = v.at(e);
				h->next = t;
				if (s + 1 < e) {
					ListNode* h2 = v.at(s + 1);
					t->next = h2;
					if (s + 1 == e - 1) {
						ListNode* h2 = v.at(s + 1);
						h2->next = NULL;
					}
				}
				else {
					t->next = NULL;
				}
				s++;
				e--;
			}
		}
	}
};