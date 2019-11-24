// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int low = 1;
		int high = n;
		long int n2 = n / 2;
		if (guess(low) == 0) {
			return low;
		}
		if (guess(high) == 0) {
			return high;
		}
		while (guess(n2) != 0) {
			if (guess(n2) == 1) {
				low = n2;
				n2 = (n2 + high) / 2;
			}
			else {
				high = n2;
				n2 = (low + n2) / 2;
			}
		}
		return n2;
	}
};