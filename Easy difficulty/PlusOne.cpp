class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int x = digits.at(digits.size() - 1);
		if (x != 9) {
			x++;
			digits.at(digits.size() - 1) = x;
		}
		else {
			digits.at(digits.size() - 1) = 0;
			if (digits.size() == 1) {
				digits.insert(digits.begin(), 1);
				return digits;
			}
			for (int i = digits.size() - 2; i > -1; i--) {
				if (digits.at(i) == 9 && i == 0) {
					digits.at(i) = 0;
					digits.insert(digits.begin(), 1);
				}
				else if (digits.at(i) == 9) {
					digits.at(i) = 0;
				}
				else {
					digits.at(i) = digits.at(i) + 1;
					break;
				}
			}
		}
		return digits;
	}
};