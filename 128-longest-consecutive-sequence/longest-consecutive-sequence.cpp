class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(int x : nums)
            st.insert(x);

        int longest = 0;

        for(int x : st) {
            if(st.find(x - 1) == st.end()) {
                int cnt = 1;

                while(st.find(x + cnt) != st.end())
                    cnt++;

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};