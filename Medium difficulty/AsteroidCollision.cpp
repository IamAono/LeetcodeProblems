class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> v;
		v.push_back(asteroids.at(0));
		for (int i = 1; i < asteroids.size(); i++) {
			if (asteroids.at(i) < 0) {
				while (true) {
					if (v.size() == 0 || v.back() < 0) {
						v.push_back(asteroids.at(i));
						break;
					}
					else if (v.back() > 0) {
						if (v.back() < abs(asteroids.at(i))) {
							v.erase(v.end() - 1);
						}
						else if (v.back() == abs(asteroids.at(i))) {
							v.erase(v.end() - 1);
							break;
						}
						else {
							break;
						}
					}
				}
			}
			else {
				v.push_back(asteroids.at(i));
			}
		}
		return v;
	}
};