class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		if (name == typed) {
			return true;
		}
		vector<int> counts;
		for (int i = 0; i < name.length(); i++) {
			char c = name[i];
			int count = 0;
			for (int j = 0; j < typed.length(); j++) {
				if (j == 0 && typed[j] != c) {
					if (i != 0) {
						if (name[i] == name[i - 1] && counts.at(counts.size() - 1) > 1) {
							counts.at(counts.size() - 1) -= 1;
							break;
						}
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}
				else if (typed[j] != c) {
					typed = typed.substr(j, typed.length() - 1);
					counts.push_back(count);
					break;
				}
				count++;
			}
		}
		return true;
	}
};