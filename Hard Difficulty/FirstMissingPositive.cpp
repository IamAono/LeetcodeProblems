class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 1; i <= nums.size(); i++) {
			for (int j = 0; j < nums.size(); j++) {
				if (i == nums.at(j)) {
					break;
				}
				else if (j == nums.size() - 1) {
					return i;
				}
			}
			if (i == nums.size()) {
				return nums.size() + 1;
			}
		}
		return 1;
	}
};