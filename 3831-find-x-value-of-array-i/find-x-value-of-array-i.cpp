class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k,0);
        vector<long long> dp(k,0);
        for(int x : nums){
            int r = x % k;
            vector<long long> ndp(k,0);
            ndp[r]++;
            for(int rem = 0; rem < k;rem++){
                ndp[(rem * r) % k] += dp[rem];
            }
            for(int rem = 0; rem <k;rem++)
                ans[rem] += ndp[rem];
            dp.swap(ndp);
        }
        return ans;
    }
};