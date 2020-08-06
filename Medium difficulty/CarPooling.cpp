class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		vector<int> v[1001];
		for (int i = 0; i < trips.size(); i++) {
			int start = trips[i].at(1);
			int end = trips[i].at(2);
			for (int j = start; j < end; j++) {
				if (v[j].size() == 0) {
					v[j].push_back(trips[i].at(0));
				}
				else {
					v[j].at(0) += trips[i].at(0);
					if (v[j].at(0) > capacity) {
						return false;
					}
				}
			}
		}
		return true;
	}
};