class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, closed = 0, ans = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                closed++;
            }
            if (open == closed) {
                ans = max(ans, open + closed);
            }
            else if (closed > open) {
                open = closed = 0;
            }
        }
        
        open = closed = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                closed++;
            }
            else {
                open++;
            }
            if (open == closed) {
                ans = max(ans, open + closed);
            }
            else if (open > closed) {
                open = closed = 0;
            }
        }
        
        return ans;
    }
};
