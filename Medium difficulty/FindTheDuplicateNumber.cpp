class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		vector<int> n[1000000];
		for (int i = 0; i < nums.size(); i++) {
			n[nums.at(i)].push_back(1);
			if (n[nums.at(i)].size() == 2) {
				return nums.at(i);
			}
		}
		return 0;
	}
};