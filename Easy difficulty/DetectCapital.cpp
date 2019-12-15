class Solution {
public:
	bool detectCapitalUse(string word) {
		string s = word;
		if (word.length() <= 1) {
			return true;
		}
		if (toupper(s[0]) == word[0]) {
			if (toupper(s[1]) == word[1]) {
				for (int i = 1; i < word.size(); i++) {
					if (tolower(s[i]) == word[i]) {
						return false;
					}
				}
				return true;
			}
			else {
				for (int i = 1; i < word.size(); i++) {
					if (toupper(s[i]) == word[i]) {
						return false;
					}
				}
				return true;
			}
		}
		else {
			for (int i = 1; i < word.size(); i++) {
				if (toupper(s[i]) == word[i]) {
					return false;
				}
			}
			return true;
		}
		return false;
	}
};