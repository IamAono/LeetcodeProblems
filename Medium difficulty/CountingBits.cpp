class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> v;
		v.push_back(0);
		for (int i = 1; i <= num; i++) {
			int count = 0;
			int n = i;
			while (n != 0) {
				int l = n & 1;
				if (l == 1) {
					count++;
				}
				n = n >> 1;
			}
			v.push_back(count);
		}
		return v;
	}
};