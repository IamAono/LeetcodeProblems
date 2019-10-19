class Solution {
public:
	int addDigits(int num) {
		int sum = 0;
		while (num >= 1) {
			int i = num % 10;
			sum += i;
			num /= 10;
		}
		if (sum < 10) {
			return sum;
		}
		else {
			return addDigits(sum);
		}
	}
};