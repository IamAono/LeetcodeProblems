class Solution {
public:
	vector<char> roman;
	vector<int> values;
	int romanToInt(string s) {
		roman.push_back('I');
		roman.push_back('V');
		roman.push_back('X');
		roman.push_back('L');
		roman.push_back('C');
		roman.push_back('D');
		roman.push_back('M');
		values.push_back(1);
		values.push_back(5);
		values.push_back(10);
		values.push_back(50);
		values.push_back(100);
		values.push_back(500);
		values.push_back(1000);
		char prev;
		int prevI;
		int value = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			char c = s[i];
			int cVal;
			int cI;
			for (int j = 0; j < roman.size(); j++) {
				if (i != s.length() - 1) {
					if (roman.at(j) == prev) {
						prevI = j;
					}
				}
				if (roman.at(j) == c) {
					cI = j;
					cVal = values.at(j);
				}
			}
			if (i != s.length() - 1) {
				if (cI < prevI) {
					value -= values.at(cI);
				}
				else {
					value += cVal;
				}
			}
			else {
				value += cVal;
			}
			prev = c;
			prevI = cI;
		}
		return value;
	}
};