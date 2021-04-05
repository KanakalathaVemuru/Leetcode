class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        deque<int> dq;
        int n = A.size();
        vector<long int> cum(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            cum[i + 1] = cum[i] + A[i];
        }
        
        int ans = INT_MAX;
        deque<int> mq;
        
        for (int end = 0; end <= n; end++) {
            while (!mq.empty() && cum[end] < cum[mq.back()]) {
                mq.pop_back();
            }
            
            mq.push_back(end);
        
            while (!mq.empty() && (cum[end] - cum[mq.front()] >= K)) {
                ans = min(ans, end - mq.front());
                mq.pop_front();
            }
        }
        return (ans == INT_MAX)?-1:ans;
    }
};