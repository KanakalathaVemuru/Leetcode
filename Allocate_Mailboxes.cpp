class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
         
        vector<int> pr_dp(n, 0);
        vector<int> dp(n, INT_MAX);
        vector<vector<int>> getBest(n, vector<int>(n, INT_MAX));
        
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int left = i;
                int right = j;
                getBest[i][j] = 0;
                
                while (left < right) {
                    getBest[i][j] += houses[right--] - houses[left++];
                }
            }
        }
        
        for (int j = 0; j < n; j++) {
            pr_dp[j] = getBest[0][j];
        }
        
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = getBest[0][j];
                for (int l = 0; l < j; l++) {
                    dp[j] = min(dp[j], pr_dp[l] + getBest[l + 1][j]);
                }
            }
            
            for (int j = 0; j < n; j++) {
                pr_dp[j] = dp[j];
                dp[j] = INT_MAX;
            }
        }
        
        return pr_dp[n - 1];
    }
};
