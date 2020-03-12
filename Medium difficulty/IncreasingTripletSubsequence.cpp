class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int x = INT_MAX, x2 = INT_MAX;
		for (int n : nums) {
			if (n <= x) {
				x = n;
			}
			else if (n <= x2) {
				x2 = n;
			}
			else {
				return true;
			}
		}
		return false;
	}
};