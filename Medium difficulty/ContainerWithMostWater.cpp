class Solution {
public:
	int maxArea(vector<int>& height) {
		int m = 0;
		int f = 0;
		for (int i = 0; i < height.size() - 1; i++) {
			if (height.at(f) < height.at(i) || i == 0) {
				for (int j = i + 1; j < height.size(); j++) {
					int x = (j - i) * min(height.at(j), height.at(i));
					if (x > m) {
						m = x;
						f = i;
					}
				}
			}
		}
		return m;
	}
};