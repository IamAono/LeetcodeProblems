// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		if (isBadVersion(n) && !isBadVersion(n - 1)) {
			return n;
		}
		long int mid = n / 2;
		long int low = 0;
		long int high = n;
		long int first = 0;
		while (true) {
			if (isBadVersion(mid) && !isBadVersion(mid - 1)) {
				first = mid;
				break;
			}
			else if (isBadVersion(mid)) {
				high = mid;
				mid = (mid + low) / 2;
			}
			else {
				low = mid;
				mid = (mid + high) / 2;
			}
		}
		return first;
	}
};