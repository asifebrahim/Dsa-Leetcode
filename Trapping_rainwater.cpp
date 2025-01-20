class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<bool>> dp(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            pq.emplace(heightMap[i][0], i, 0);
            dp[i][0] = true;
            pq.emplace(heightMap[i][n - 1], i, n - 1);
            dp[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            pq.emplace(heightMap[0][j], 0, j);
            dp[0][j] = true;
            pq.emplace(heightMap[m - 1][j], m - 1, j);
            dp[m - 1][j] = true;
        }

        int ans = 0;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        while (!pq.empty()) {
            auto [height, row, col] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int rowi = row + dx[i];
                int coli = col + dy[i];
                if (rowi >= 0 && rowi < m && coli >= 0 && coli < n && !dp[rowi][coli]) {
                    ans += max(0, height - heightMap[rowi][coli]);
                    pq.emplace(max(height, heightMap[rowi][coli]), rowi, coli);
                    dp[rowi][coli] = true; 
                }
            }
        }

        return ans;
    }
};


/*
    Since we are using a minheap then we are always going to check the min height cell first
    and we also keep track of the visited cells. If any cell is not vis we check if its height is
     less than the current height then we add the difference to the ans and then we add the max 
     of the two heights to the heap and then we mark the cell as visited. We keep on doing this 
     until the heap is empty. We add the max of the two heights because for that index if the cell
     height is lower than the boundary height then the max height will be the boundary height and
     it will be deciding factor in the future though we work with min heights for storing water.
    Time Complexity: O(m*n*log(m*n)) where m and n are the dimensions of the heightMap.
    Space Complexity: O(m*n).

    We dont check neighbours while adding the height to the ans because
    if a cellls height is greater than the boundary height and its other neighbour height is also lower 
    than the cells height then the boundary height is gonna be less than the neighbour height as
    we are using minheap and the min height always gonna come first and we gonna reach a cell through min height
     first and mark it as visited for that index and height so we don't have to check for it in future. 
*/