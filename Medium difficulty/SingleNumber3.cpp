class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums;
		}
		vector<int> v;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums.at(i) != nums.at(i + 1)) {
				v.push_back(nums.at(i));
			}
			else {
				i++;
			}
		}
		if (nums.back() != nums.at(nums.size() - 2)) {
			v.push_back(nums.back());
		}
		return v;
	}
};