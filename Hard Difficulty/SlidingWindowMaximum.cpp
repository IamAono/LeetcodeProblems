class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0) {
			return nums;
		}
		vector<int> v;
		int w = 0;
		while (w + k <= nums.size()) {
			int m = INT_MIN;
			for (int i = w; i < w + k; i++) {
				m = max(m, nums.at(i));
			}
			v.push_back(m);
			w++;
		}
		return v;
	}
};