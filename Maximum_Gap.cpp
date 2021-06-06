class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int min_ = INT_MAX;
        int max_ = INT_MIN;
        int n = nums.size();
        if (n < 2)
            return 0;
        
        for (int num: nums) {
            min_ = min(min_, num);
            max_ = max(max_, num);
        }
        
        int avg=max((max_ - min_)/(n - 1),1); 
        int size=((max_ - min_)/avg) + 1; 
        
        vector<pair<int, int>> str(size, {INT_MAX, INT_MIN});
        
        auto getIndex = [min_, avg](const int num)  {
            return (num - min_)/avg;
        };
        
        for (int num: nums) {
            int in = getIndex(num);
            
            str[in].first = min(str[in].first, num);
            str[in].second = max(str[in].second, num);
        }
        
        int pr_max = str[0].second;
        int ans = str[0].second - str[0].first;
        
        for (int i = 1; i < size; i++) {
            if (str[i].first != INT_MAX && pr_max != INT_MIN)
                ans = max(ans, str[i].first - pr_max);
            if (str[i].second != INT_MIN)
                pr_max = str[i].second;
            else if (str[i].first != INT_MAX)
                pr_max = str[i].first;
        }
        
        return ans;
    }
};
