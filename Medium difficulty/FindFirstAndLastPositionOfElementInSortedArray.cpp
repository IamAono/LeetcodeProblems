class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int first = -1;
		bool findF = false;
		int last = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums.at(i) == target) {
				if (findF) {
					last = i;
				}
				else {
					findF = true;
					first = i;
					last = i;
				}
			}
		}
		vector<int> ans;
		ans.push_back(first);
		ans.push_back(last);
		return ans;
	}
};