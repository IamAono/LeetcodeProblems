class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = 0;
		int max = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums.at(i) == 1 && count + 1 > max && i == nums.size() - 1) {
				max = count + 1;
			}
			else if (nums.at(i) == 1) {
				count++;
			}
			else if (count > max) {
				max = count;
				count = 0;
			}
			else {
				count = 0;
			}
		}
		return max;
	}
};