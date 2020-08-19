class Solution {
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		vector<vector<int>> answer;
		pair<int, int> k;
		k.first = king[0];
		k.second = king[1];
		vector<vector<int>> board; //0 for empty, 1 for queen, 2 for king
		for (int i = 0; i < 8; i++) {
			vector<int> b;
			for (int j = 0; j < 8; j++) {
				b.push_back(0);
			}
			board.push_back(b);
		}
		board[k.first][k.second] = 2;
		for (int i = 0; i < queens.size(); i++) {
			board[queens[i][0]][queens[i][1]] = 1;
		}
		for (int i = k.first; i > -1; i--) { //checking up from king
			if (board[i][k.second] == 1) {
				vector<int> v;
				v.push_back(i);
				v.push_back(k.second);
				answer.push_back(v);
				break;
			}
		}
		for (int i = k.first; i < 8; i++) { //checking down from king
			if (board[i][k.second] == 1) {
				vector<int> v;
				v.push_back(i);
				v.push_back(k.second);
				answer.push_back(v);
				break;
			}
		}
		for (int i = k.second; i > -1; i--) { //checking left from king
			if (board[k.first][i] == 1) {
				vector<int> v;
				v.push_back(k.first);
				v.push_back(i);
				answer.push_back(v);
				break;
			}
		}
		for (int i = k.second; i < 8; i++) { //checking right from king
			if (board[k.first][i] == 1) {
				vector<int> v;
				v.push_back(k.first);
				v.push_back(i);
				answer.push_back(v);
				break;
			}
		}
		//checking the diagonals
		int x = 1;
		while (true) {
			if (k.first - x < 0 || k.second - x < 0) {
				break;
			}
			if (board[k.first - x][k.second - x] == 1) {
				vector<int> v;
				v.push_back(k.first - x);
				v.push_back(k.second - x);
				answer.push_back(v);
				break;
			}
			x++;
		}
		x = 1;
		while (true) {
			if (k.first - x < 0 || k.second + x > 7) {
				break;
			}
			if (board[k.first - x][k.second + x] == 1) {
				vector<int> v;
				v.push_back(k.first - x);
				v.push_back(k.second + x);
				answer.push_back(v);
				break;
			}
			x++;
		}
		x = 1;
		while (true) {
			if (k.first + x > 7 || k.second + x > 7) {
				break;
			}
			if (board[k.first + x][k.second + x] == 1) {
				vector<int> v;
				v.push_back(k.first + x);
				v.push_back(k.second + x);
				answer.push_back(v);
				break;
			}
			x++;
		}
		x = 1;
		while (true) {
			if (k.first + x > 7 || k.second - x < 0) {
				break;
			}
			if (board[k.first + x][k.second - x] == 1) {
				vector<int> v;
				v.push_back(k.first + x);
				v.push_back(k.second - x);
				answer.push_back(v);
				break;
			}
			x++;
		}
		return answer;
	}
};