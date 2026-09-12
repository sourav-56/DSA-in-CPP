class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals){
        int n = intervals.size();
        vector<vector<long long>> a(n, vector<long long>(4));
        for (int i = 0; i < n; ++i) {
            a[i][0] = intervals[i][0];
            a[i][1] = intervals[i][1];
            a[i][2] = intervals[i][2];
            a[i][3] = i;               
        }
        sort(a.begin(), a.end(), [](const vector<long long>& x, const vector<long long>& y){
            if (x[1] != y[1]) return x[1] < y[1];
            if (x[2] != y[2]) return x[2] > y[2];
            return x[3] < y[3];
        });
        vector<long long> rights(n);
        for (int i = 0; i < n; ++i){
            rights[i] = a[i][1];
        }
        struct State {
            long long weight = 0;
            vector<int> indices;
        };
        auto better = [](const State& s1, const State& s2){
            if (s1.weight != s2.weight){
                return s1.weight > s2.weight;
            }
            return s1.indices < s2.indices;
        };
        vector<int> p(n);
        for (int i = 0; i < n; ++i){
            auto it = lower_bound(rights.begin(), rights.end(), a[i][0]);
            int idx = distance(rights.begin(), it) - 1;
            p[i] = idx;
        }
        vector<vector<State>> dp(n + 1, vector<State>(5));
        for (int i = 1; i <= n; ++i){
            long long l = a[i-1][0];
            long long r = a[i-1][1];
            long long w = a[i-1][2];
            int idx = a[i-1][3];
            for (int j = 0; j <= 4; ++j){
                dp[i][j] = dp[i-1][j];
            }
            for (int j = 1; j <= 4; ++j){
                int prev = p[i-1];
                State prev_state = (prev == -1) ? State{0, {}} : dp[prev + 1][j - 1];   
                State candidate;
                candidate.weight = prev_state.weight + w;
                candidate.indices = prev_state.indices;
                candidate.indices.push_back(idx);
                sort(candidate.indices.begin(), candidate.indices.end());
                if (better(candidate, dp[i][j])) {
                    dp[i][j] = candidate;
                }
                if (better(dp[i-1][j], dp[i][j])){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        State best_ans;
        for (int j = 0; j <= 4; ++j){
            if (better(dp[n][j], best_ans)){
                best_ans = dp[n][j];
            }
        }
        return best_ans.indices;
    }
};