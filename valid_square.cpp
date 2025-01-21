class Solution {
public:
    int distSquared(pair<int, int>& a, pair<int, int>& b) {
        return (a.first - b.first) * (a.first - b.first) + 
               (a.second - b.second) * (a.second - b.second);
    }

//Function for valid square.
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int, int>> points = {{p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}};
        vector<int> dists;

        // Calculate all 6 pairwise distances
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                dists.push_back(distSquared(points[i], points[j]));
            }
        }

        // Sort distances
        sort(dists.begin(), dists.end());

        // Validate the conditions for a square
        return dists[0] > 0 &&                              // No zero distance
               dists[0] == dists[1] &&                      // 4 equal sides
               dists[1] == dists[2] && 
               dists[2] == dists[3] && 
               dists[4] == dists[5] &&                     // 2 equal diagonals
               dists[4] == 2 * dists[0];                   // Diagonal = √2 * side
    }
};
