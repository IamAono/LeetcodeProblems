class Solution {
public:
	vector<char> roman;
	vector<int> values;
	int romanToInt(string s) {
		unordered_map<char, int> um;
		um['I'] = 1;
		um['V'] = 5;
		um['X'] = 10;
		um['L'] = 50;
		um['C'] = 100;
		um['D'] = 500;
		um['M'] = 1000;
		int prev = 0;
		int value = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			char c = s[i];
			int val = um[c];
			if (prev > val) {
				value -= val;
			}
			else {
				value += val;
			}
			prev = val;
		}
		return value;
	}
};