class Solution {
public:
	int calc(int i, int j, int i2, int j2) {
		return(i + j + i2 - j2);
	}
	int maxScoreSightseeingPair(vector<int>& A) {
		int max = 0;
		int start = A.at(0);
		int startI = 0;
		for (int j = 1; j < A.size(); j++) {
			if (calc(start, A.at(j), startI, j) > max) {
				max = calc(start, A.at(j), startI, j);
			}
			if (start + startI <= A.at(j) + j) {
				start = A.at(j);
				startI = j;
			}
		}
		return max;
	}
};