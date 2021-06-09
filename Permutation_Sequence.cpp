class Solution {
public:
    char getDigit(vector<int> &integers, long int &fact, int &k) {
        int n = integers.size();
        
        fact = fact/n;
        
        if (k < fact) {
            int ans = 0;
            char cans = (char)(integers[ans] + '0');
            integers.erase(integers.begin() + ans);
            return cans;
        }
        int ans = (k/fact);
        char cans = (char)(integers[ans] + '0');
        k %= fact;
        
        integers.erase(integers.begin() + ans);
        return cans;
    }
    string getPermutation(int n, int k) {
        vector<int> integers;
        vector<char> ans(n, 0);
        int j = 0;
        long int fact = 1;
        
        for (int i = 1; i <= n; i++) {
            integers.push_back(i);
            fact = fact* i;
        }
        
        k--;
        while (k > 0 && j < n) {
            ans[j++] = getDigit(integers, fact, k);
        }
       
        for (int i = 0; j < n; j++, i++) {
            ans[j] = (char)(integers[i] + '0');
        }
        string sans(ans.begin(), ans.end());
        return sans;
    }
};
