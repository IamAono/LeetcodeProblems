class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int largest = -1;
		int index;
		for (int i = 0; i < nums.size(); i++) {
			if (largest < nums.at(i)) {
				largest = nums.at(i);
				index = i;
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i != index && nums.at(i) * 2 > largest) {
				return -1;
			}
		}
		return index;
	}
};