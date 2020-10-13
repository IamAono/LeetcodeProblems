class Solution {
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int r, c;
		int capture = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i].at(j) == 'R') {
					r = i;
					c = j;
					break;
				}
			}
		}
		// Looking north
		for (int i = r - 1; i > -1; i--) {
			if (board[i].at(c) == 'p') {
				capture++;
				break;
			}
			else if (board[i].at(c) == 'B') {
				break;
			}
		}
		// Looking east
		for (int i = c + 1; i < board[r].size(); i++) {
			if (board[r].at(i) == 'p') {
				capture++;
				break;
			}
			else if (board[r].at(i) == 'B') {
				break;
			}
		}
		// Looking south
		for (int i = r + 1; i < board.size(); i++) {
			if (board[i].at(c) == 'p') {
				capture++;
				break;
			}
			else if (board[i].at(c) == 'B') {
				break;
			}
		}
		// Looking west
		for (int i = c - 1; i > -1; i--) {
			if (board[r].at(i) == 'p') {
				capture++;
				break;
			}
			else if (board[r].at(i) == 'B') {
				break;
			}
		}
		return capture;
	}
};