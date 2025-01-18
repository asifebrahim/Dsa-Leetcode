class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<>> pq;
        set<tuple<int, int, int>> st;
        pq.push({0, {grid[0][0], {0, 0}}});
        int ans = INT_MAX;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int count = it.first;
            int dir = it.second.first;
            int row = it.second.second.first;
            int col = it.second.second.second;

            if (st.count({row, col, dir})) continue;
            st.insert({row, col, dir});

            if (row == m - 1 && col == n - 1) {
                ans = min(ans, count);
                continue;
            }

            for (int i = 1; i <= 4; i++) {
                if (i != dir) {
                    pq.push({count + 1, {i, {row, col}}});
                }
            }

            if (dir == 1 && col + 1 < n) {
                pq.push({count, {grid[row][col + 1], {row, col + 1}}});
            } else if (dir == 2 && col - 1 >= 0) {
                pq.push({count, {grid[row][col - 1], {row, col - 1}}});
            } else if (dir == 3 && row + 1 < m) {
                pq.push({count, {grid[row + 1][col], {row + 1, col}}});
            } else if (dir == 4 && row - 1 >= 0) {
                pq.push({count, {grid[row - 1][col], {row - 1, col}}});
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
