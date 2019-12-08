class Solution {
public:
	bool mod(int x) {
		int x2 = x;
		while (x2 > 0) {
			int m = x2 % 10;
			if (m == 0) {
				return false;
			}
			else if (x % m != 0) {
				return false;
			}
			x2 /= 10;
		}
		return true;
	}
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> v;
		for (int i = left; i <= right; i++) {
			if (mod(i)) {
				v.push_back(i);
			}
		}
		return v;
	}
};