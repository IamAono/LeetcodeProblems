class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		vector<int> v[N + 1];
		vector<int> v2[N + 1];
		for (int i = 0; i < trust.size(); i++) {
			v[trust.at(i).at(0)].push_back(trust.at(i).at(1));
			v2[trust.at(i).at(1)].push_back(trust.at(i).at(0));
		}
		for (int i = 1; i <= N; i++) {
			if (v[i].size() == 0 && v2[i].size() == N - 1) {
				return i;
			}
		}
		return -1;
	}
};