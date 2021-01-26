Path With Minimum Effort
Medium

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106



Solution:


class Solution {
public:
     bool isValid(vector<vector<int>>& h, int x, int y) {
        return x < n and x >= 0 and y < m and y >= 0;
    }
	
    bool dfs(vector<vector<int>>& h, int k, int x, int y) {
        vis[x][y] = true;
        if (x == n-1 && y == m-1)
            return true;
            
        for (int i = 0; i < 4; i++) {
            int x_curr = x + x_points[i];
            int y_curr = y + y_points[i];
            if (isValid(h, x_curr, y_curr) && 
                !vis[x_curr][y_curr] && abs(h[x_curr][y_curr] - h[x][y]) <= k)
                if (dfs(h, k, x_curr, y_curr)) return true;
        }

        return false;
    }
    
    bool possibleLessEqK(vector<vector<int>>& h, int k) {
        vis.assign(n,vector<bool> (m, false));
        return dfs(h, k, 0, 0);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        int lo = 0, hi = 1e6, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if (possibleLessEqK(heights, mid))
                hi = mid;
            else 
                lo = mid + 1;
        }
        
        return lo;
    }
    
private:
    vector<vector<bool>> vis;
    vector<int> x_points = {1, 0, -1, 0};
    vector<int> y_points = {0, 1, 0, -1};
    int n;
    int m;
};
