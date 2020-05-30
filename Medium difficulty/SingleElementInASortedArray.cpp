class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums.at(0);
		}
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums.at(i + 1) == nums.at(i)) {
				i += 1;
			}
			else {
				return(nums.at(i));
			}
		}
		return nums.at(nums.size() - 1);
	}
};