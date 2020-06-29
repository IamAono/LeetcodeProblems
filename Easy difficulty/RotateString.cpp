class Solution {
public:
	bool rotateString(string A, string B) {
		int l = A.length();
		if (A.length() != B.length()) {
			return false;
		}
		if (A == B) {
			return true;
		}
		while (l--) {
			char c = A[0];
			A.erase(A.begin() + 0);
			A += c;
			if (A == B) {
				return true;
			}
		}
		return false;
	}
};