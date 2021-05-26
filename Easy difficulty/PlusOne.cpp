class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		bool b = true;
		for (int i = digits.size() - 1; i > -1; i--) {
			if (digits[i] < 9) {
				digits[i] += 1;
				b = false;
				break;
			}
			else {
				digits[i] = 0;
			}
		}
		if (b) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};