class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		vector<int> v;
		int s = 0;
		for (int i = 0; i < X; i++) {
			if (grumpy.at(i) == 1) {
				s += customers.at(i);
			}
		}
		v.push_back(s);
		for (int i = X; i < customers.size(); i++) {
			if (grumpy.at(i - X) == 1) {
				s -= customers.at(i - X);
			}
			if (grumpy.at(i) == 1) {
				s += customers.at(i);
			}
			v.push_back(s);
		}
		sort(v.begin(), v.end());
		s = v.back();
		for (int i = 0; i < customers.size(); i++) {
			if (grumpy.at(i) == 0) {
				s += customers.at(i);
			}
		}
		return s;
	}
};