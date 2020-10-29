class Solution {
public:
	int indexOf(char c, vector<char> v) {
		for (int i = 0; i < v.size(); i++) {
			if (v.at(i) == c) {
				return i;
			}
		}
		return 0;
	}
	string shiftingLetters(string S, vector<int>& shifts) {
		vector<char> v{ 'a', 'b', 'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		int s = 0;
		for (int i = 0; i < shifts.size(); i++) {
			if (shifts.at(i) > 26) {
				shifts.at(i) = shifts.at(i) % 26;
			}
			s += shifts.at(i);
			if (s > 26) {
				s = s % 26;
			}
		}
		for (int i = 0; i < S.length(); i++) {
			S[i] = v.at((indexOf(S[i], v) + s) % 26);
			s -= shifts.at(i);
			if (s < 0) {
				s += 26;
			}
		}
		return S;
	}
};