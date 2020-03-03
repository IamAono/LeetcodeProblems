class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		if (nums.size() == 1) {
			return nums.at(0);
		}
		vector<int> o;
		o.push_back(0);
		o.push_back(nums.at(0));
		for (int i = 2; i <= nums.size(); i++) {
			o.push_back(max(o.at(i - 1), nums.at(i - 1) + o.at(i - 2)));
		}
		return o.back();
	}
};