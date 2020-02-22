class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = 0, one = 0, two = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums.at(i) == 0) {
				zero++;
			}
			else if (nums.at(i) == 1) {
				one++;
			}
			else {
				two++;
			}
		}
		int index = 0;
		while (zero--) {
			nums[index] = 0;
			index++;
		}
		while (one--) {
			nums[index] = 1;
			index++;
		}
		while (two--) {
			nums[index] = 2;
			index++;
		}
	}
};