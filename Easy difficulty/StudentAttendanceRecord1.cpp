class Solution {
public:
	bool checkRecord(string s) {
		int l = 0;
		int a = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'A') {
				a++;
				if (a == 2) {
					return false;
				}
				l = 0;
			}
			else if (s[i] == 'L') {
				l++;
				if (l == 3) {
					return false;
				}
			}
			else {
				l = 0;
			}
		}
		return true;
	}
};