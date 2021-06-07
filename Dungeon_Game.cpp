class Solution {
public:
    int dfs(vector<vector<int>> &dungeon, int i, int j, int n, int m, vector<vector<int>> &dp) {
        if (i == n || j == m)
            return INT_MAX;
        
        int health = dungeon[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        
        auto getAns = [&health](int from_here) {
            if (from_here == INT_MAX)
                return INT_MAX;
            
            if (health -  from_here <= 0) {
               return abs(health - from_here) ;
            } else 
                return 0;
        };
        
        if (i == n - 1 && j == m - 1) {
            dp[i][j] = (dungeon[i][j] < 0)?-dungeon[i][j]:0;
            return dp[i][j];
        }
    
        dp[i][j] = getAns(dfs(dungeon, i + 1, j, n, m, dp));
        dp[i][j] = min(dp[i][j], getAns(dfs(dungeon, i, j + 1, n, m, dp)));
        
        return dp[i][j];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
    
        dfs(dungeon, 0, 0, n, m, dp);
        
        return dp[0][0] + 1;
    }
};
