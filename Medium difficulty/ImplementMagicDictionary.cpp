class MagicDictionary {
public:
	vector<string> v;
	int diff(string s, string s2) {
		int c = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != s2[i]) {
				c++;
				if (c == 2) {
					break;
				}
			}
		}
		return c;
	}
	/** Initialize your data structure here. */
	MagicDictionary() {

	}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (int i = 0; i < dict.size(); i++) {
			v.push_back(dict.at(i));
		}
	}

	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		if (v.size() == 0) {
			return false;
		}
		for (int i = 0; i < v.size(); i++) {
			if (v.at(i).length() != word.length()) {
				continue;
			}
			if (diff(v.at(i), word) == 1) {
				return true;
			}
		}
		return false;
	}
};

/**
* Your MagicDictionary object will be instantiated and called as such:
* MagicDictionary* obj = new MagicDictionary();
* obj->buildDict(dict);
* bool param_2 = obj->search(word);
*/