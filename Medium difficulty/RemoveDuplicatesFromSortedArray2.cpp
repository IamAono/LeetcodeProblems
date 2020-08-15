class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) {
			return nums.size();
		}
		for (int i = 1; i < nums.size() - 1; i++) {
			if (nums.at(i - 1) == nums.at(i) && nums.at(i + 1) == nums.at(i)) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}
		return nums.size();
	}
};