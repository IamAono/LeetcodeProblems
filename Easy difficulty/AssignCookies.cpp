class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int h = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = g.size() - 1; i > -1; i--) {
            if (s.size() == 0) {
                break;
            }
            if (s.back() >= g[i]) {
                s.erase(s.begin() + s.size() - 1);
                h++;
            }
        }
        return h;
    }
};