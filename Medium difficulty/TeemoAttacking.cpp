class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int tick = 0;
		if (timeSeries.size() == 0) {
			return 0;
		}
		for (int i = 0; i < timeSeries.size() - 1; i++) {
			tick += min(timeSeries.at(i + 1) - timeSeries.at(i), duration);
		}
		return tick + duration;
	}
};