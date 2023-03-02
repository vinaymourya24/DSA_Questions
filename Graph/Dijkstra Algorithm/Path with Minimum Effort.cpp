class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dg(n ,vector<int>(m, INT_MAX));
        dg[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0, 0}});
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

        while(pq.size()) {
            int i = pq.top().second.first, j = pq.top().second.second;
            int dis = pq.top().first; pq.pop();

            if(i == n - 1 && j == m - 1) return dis;
            for(int k=0; k<4; k++) {
                int x = i + dx[k], y = j + dy[k];

                if(x >= 0 && x < n && y >= 0 && y < m) {
                    int d = abs(heights[i][j] - heights[x][y]);
                    if(max(d, dis) < dg[x][y]) dg[x][y] = max(d, dis), pq.push({max(d, dis), {x, y}});
                }
            }
        }
        // return dg[n - 1][m - 1];
        return -1;
    }
};