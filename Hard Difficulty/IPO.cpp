class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		if (!k || Profits.size() == 0) {
			return 0;
		}
		vector<pair<int, int>> v;
		for (int i = 0; i < Profits.size(); i++) {
			pair<int, int> p;
			p.first = Profits.at(i);
			p.second = Capital.at(i);
			v.push_back(p);
		}
		sort(v.begin(), v.end());
		while (k--) {
			int maxProfit = 0, index = 0;
			for (int i = v.size() - 1; i >= 0; i--) {
				if (v.at(i).second <= W && v.at(i).first > maxProfit) {
					maxProfit = v.at(i).first;
					index = i;
					break;
				}
			}
			if (maxProfit == 0) {
				return W;
			}
			W += v.at(index).first;
			v.erase(v.begin() + index);
		}
		return W;
	}
};