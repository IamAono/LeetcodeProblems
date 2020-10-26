class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int dec = 0;
		int j = 0;
		if (nums.size() <= 2) {
			return true;
		}
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums.at(i) > nums.at(i + 1)) {
				dec++;
				j = i;
			}
			if (dec == 2) {
				return false;
			}
		}
		if (j == 0) {
			return true;
		}
		if (nums.at(j - 1) <= nums.at(j + 1)) {
			return true;
		}
		j++;
		if (j == nums.size() - 1) {
			return true;
		}
		if (nums.at(j - 1) <= nums.at(j + 1)) {
			return true;
		}
		return false;
	}
};