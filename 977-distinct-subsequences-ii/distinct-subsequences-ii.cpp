class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;
        long long dp = 0;
        vector<long long> end(26,0);
        for (char c : s) {
            int x = c - 'a';
            long long oldDp =dp;
            dp = (2 * dp + 1 - end[x] +MOD)%MOD;
            end[x] = (oldDp + 1)%MOD;
        }
        return dp;
    }
};