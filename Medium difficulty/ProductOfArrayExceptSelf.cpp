class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> v;
		v.push_back(1);
		for (int i = 1; i < nums.size(); i++) {
			v.push_back(v.at(i - 1) * nums.at(i - 1));
		}
		int r = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			v.at(i) = v.at(i) * r;
			r *= nums.at(i);
		}
		return v;
	}
};