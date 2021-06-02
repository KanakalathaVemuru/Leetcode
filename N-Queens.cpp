class Solution {
public:
    bool isValid(vector<string> &configuration, int row, int col, int n) {
        for (int row_ = 0; row_ < n; row_++) {
            if (configuration[row_][col] == 'Q')
                return false;
        }
        
        for (int row_ = row, col_ = col; row_ >= 0 && col_ >= 0; row_--, col_--) {
            if (configuration[row_][col_] == 'Q')
                return false;
        }
        
        for (int row_ = row, col_ = col; row_ >= 0 && col_ < n; row_--, col_++) {
            if (configuration[row_][col_] == 'Q')
                return false;
        }
        return true; 
    }
    
    void backtrack(vector<string> &configuration, int n, int row, vector<vector<string>> &ans) {
        if (row == n) {
            ans.push_back(configuration);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (isValid(configuration, row, i, n)) {
                configuration[row][i] = 'Q';
                
                backtrack(configuration, n, row + 1, ans);
                
                configuration[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> initial_configuration;
        
        for (int i = 0; i < n; i++) {
            string new_(n, '.');
            initial_configuration.push_back(new_);
        }
        
        vector<vector<string>> ans;
        backtrack(initial_configuration, n, 0, ans);
        return ans;
    }
};