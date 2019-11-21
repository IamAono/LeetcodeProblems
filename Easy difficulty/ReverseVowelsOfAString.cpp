class Solution {
public:
	string reverseVowels(string s) {
		vector<char> v;
		for (int i = 0; i < s.length(); i++) {
			if (s.at(i) == 'a' || s.at(i) == 'e' || s.at(i) == 'i' || s.at(i) == 'o' || s.at(i) == 'u') {
				v.push_back(s.at(i));
			}
			else if (s.at(i) == 'A' || s.at(i) == 'E' || s.at(i) == 'I' || s.at(i) == 'O' || s.at(i) == 'U') {
				v.push_back(s.at(i));
			}
		}
		string s2 = "";
		for (int i = 0; i < s.length(); i++) {
			if (s.at(i) == 'a' || s.at(i) == 'e' || s.at(i) == 'i' || s.at(i) == 'o' || s.at(i) == 'u') {
				s2 += v.at(v.size() - 1);
				v.erase(v.begin() + v.size() - 1);
			}
			else if (s.at(i) == 'A' || s.at(i) == 'E' || s.at(i) == 'I' || s.at(i) == 'O' || s.at(i) == 'U') {
				s2 += v.at(v.size() - 1);
				v.erase(v.begin() + v.size() - 1);
			}
			else {
				s2 += s.at(i);
			}
		}
		return s2;
	}
};