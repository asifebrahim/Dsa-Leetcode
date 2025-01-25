#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cout << "Enter the matrix dimensions: ";
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Enter the matrix elements: ";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(2 * (m + n) + 1, false)));

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};


    pq.push({0, {0, 0}});
    visited[0][0][m + n] = true; 

    bool flag = false;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int val = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == m - 1 && col == n - 1 && val == 0) {
            flag = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int a = row + dx[i];
            int b = col + dy[i];

            if (a >= 0 && a < m && b >= 0 && b < n) {
                int newVal = val + (mat[a][b] == 1 ? 1 : -1);
                if (!visited[a][b][m + n + newVal]) {
                    pq.push({newVal, {a, b}});
                    visited[a][b][m + n + newVal] = true;
                }
            }
        }
    }

    if (flag)
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;

    return 0;
}
