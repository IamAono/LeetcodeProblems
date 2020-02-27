class Solution {
public:
	vector<int> v;
	void right(vector<vector<int>>& m) {
		for (int i = 0; i < m[0].size(); i++) {
			v.push_back(m[0][i]);
		}
		m.erase(m.begin());
	}
	void down(vector<vector<int>>& m) {
		for (int i = 0; i < m.size(); i++) {
			v.push_back(m[i].back());
			m[i].erase(m[i].begin() + m[i].size() - 1);
			if (m[i].size() == 0) {
				m.erase(m.begin() + i);
				i--;
			}
		}
	}
	void left(vector<vector<int>>& m) {
		for (int i = m[i].size() - 1; i > -1; i--) {
			v.push_back(m[m.size() - 1][i]);
		}
		m.erase(m.begin() + m.size() - 1);
	}
	void up(vector<vector<int>>& m) {
		for (int i = m.size() - 1; i > -1; i--) {
			v.push_back(m[i][0]);
			m[i].erase(m[i].begin());
			if (m[i].size() == 0) {
				m.erase(m.begin() + i);
			}
		}
	}
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		while (true) {
			if (matrix.size() == 0) {
				break;
			}
			right(matrix);
			if (matrix.size() == 0) {
				break;
			}
			down(matrix);
			if (matrix.size() == 0) {
				break;
			}
			left(matrix);
			if (matrix.size() == 0) {
				break;
			}
			up(matrix);
		}
		return v;
	}
};