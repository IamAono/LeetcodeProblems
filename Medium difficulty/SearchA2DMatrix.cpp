class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) {
			return false;
		}
		bool b = false;
		int r;
		for (int i = 0; i < matrix.size(); i++) {
			if (b) {
				break;
			}
			if (matrix[i].size() == 0) {
				return false;
			}
			for (int j = 0; j < matrix[i].size(); j++) {
				if (target == matrix[i].at(j)) {
					return true;
				}
				else if (matrix.size() == 1 || i == matrix.size() - 1 && target > matrix[i].at(0)) {
					if (j == matrix[i].size() - 1) {
						return false;
					}
				}
				else if (j == 0) {
					if (target < matrix[i].at(j)) {
						if (i == 0) {
							return false;
						}
						b = true;
						r = i - 1;
						break;
					}
					if (target > matrix[i].at(j)) {
						break;
					}
				}
			}
		}
		for (int i = 0; i < matrix[r].size(); i++) {
			if (matrix[r].at(i) == target) {
				return true;
			}
		}
		return false;
	}
};