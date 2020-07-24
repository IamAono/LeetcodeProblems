class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() < 2) {
			return 0;
		}
		if (nums.at(0) > nums.at(1)) {
			return 0;
		}
		if (nums.at(nums.size() - 1) > nums.at(nums.size() - 2)) {
			return(nums.size() - 1);
		}
		for (int i = 1; i < nums.size() - 1; i++) {
			if (nums.at(i) > nums.at(i - 1) && nums.at(i) > nums.at(i + 1)) {
				return i;
			}
		}
		return 0;
	}
};