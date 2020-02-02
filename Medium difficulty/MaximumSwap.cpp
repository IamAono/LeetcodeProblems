class Solution {
public:
	int swap(string s, int i, int i2) {
		char temp = s[i];
		s[i] = s[i2];
		s[i2] = temp;
		int r = stoi(s);
		return r;
	}
	int maximumSwap(int num) {
		string s = to_string(num);
		if (s.length() < 2) {
			return num;
		}
		int index = -1;
		bool f = true;
		int maxI, maxV;
		while (f) {
			index++;
			if (index == s.length() - 1) {
				return num;
			}
			maxV = num;
			maxI = index;
			for (int i = index + 1; i < s.length(); i++) {
				if (swap(s, index, i) > maxV) {
					maxV = swap(s, index, i);
					maxI = i;
					f = false;
				}
			}
		}
		return maxV;
	}
};