class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> isPalin(n, vector<bool>(n, 0));
        
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (len == 1) {
                    isPalin[i][j] = true;
                }
                else if (len == 2) {
                    if (s[i] == s[j])
                        isPalin[i][j] = true;
                    else
                        isPalin[i][j] = false;
                }
                else {
                    if (s[i] == s[j])
                        isPalin[i][j] = isPalin[i + 1][j - 1];
                    else
                        isPalin[i][j] = false;
                }
            }
        }
        
        vector<int> minCut(n, INT_MAX);
        
        for (int i = 0; i < n; i++) {
            if (isPalin[0][i])
                minCut[i] = 0;
            else
                minCut[i] = i;
            
            for (int j = 0; j < i; j++) {
                if (isPalin[j + 1][i] == true)
                    minCut[i] = min(minCut[i], minCut[j] + 1);
            }
        }
        
        return minCut[n - 1];
    }
};