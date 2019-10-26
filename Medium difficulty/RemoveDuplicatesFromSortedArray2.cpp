class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) {
			return nums.size();
		}
		int s = nums.size();
		int count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums.at(i) != nums.at(i - 1)) {
				count = 1;
			}
			else if (count == 2) {
				nums.erase(nums.begin() + i);
				i--;
				s--;
			}
			else {
				count++;
			}
		}
		return s;
	}
};