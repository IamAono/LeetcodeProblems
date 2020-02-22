class Solution {
public:
	string reverseWords(string s) {
		string word = "";
		vector<string> words;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ') {
				word += s[i];
			}
			else if (word.length() > 0) {
				words.push_back(word);
				word = "";
			}
		}
		if (word.length() > 0) {
			words.push_back(word);
		}
		string a = "";
		for (int i = words.size() - 1; i > -1; i--) {
			a += words.at(i);
			if (i != 0) {
				a += ' ';
			}
		}
		return a;
	}
};