class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int increase = 0;
        vector<int> v(grid[0].size(), 0);
        vector<int> v2(grid.size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                v[j] = max(v[j], grid[i][j]);
                v2[i] = max(v2[i], grid[i][j]);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int k = min(v2[j], v[i]);
                increase += k - grid[i][j];
            }
        }
        return increase;
    }
};