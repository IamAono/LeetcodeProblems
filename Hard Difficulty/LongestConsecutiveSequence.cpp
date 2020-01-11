class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		if (nums.size() == 1) {
			return 1;
		}
		int count = 1;
		int maxCount = 1;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums.at(i + 1) == nums.at(i)) {
				while (i < nums.size() - 2) {
					i++;
					if (nums.at(i + 1) != nums.at(i)) {
						break;
					}
				}
			}
			if (nums.at(i + 1) == nums.at(i) + 1) {
				count++;
			}
			else {
				maxCount = max(maxCount, count);
				count = 1;
			}
		}
		maxCount = max(maxCount, count);
		return maxCount;
	}
};