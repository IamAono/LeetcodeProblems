/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<int>> s;
	void pathSum(TreeNode* t, int sum, int sum2, vector<int> v) {
		v.push_back(t->val);
		sum2 += t->val;
		if (t->left) {
			pathSum(t->left, sum, sum2, v);
		}
		if (t->right) {
			pathSum(t->right, sum, sum2, v);
		}
		if (sum2 == sum && !t->left && !t->right) {
			s.push_back(v);
		}
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root) {
			return s;
		}
		vector<int> v;
		v.push_back(root->val);
		if (root->left) {
			pathSum(root->left, sum, root->val, v);
		}
		if (root->right) {
			pathSum(root->right, sum, root->val, v);
		}
		if (!root->left && !root->right) {
			if (root->val == sum) {
				s.push_back(v);
			}
			return s;
		}
		return s;
	}
};