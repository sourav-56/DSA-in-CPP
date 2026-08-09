class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int longest = 0;
        for(int x : st) {
            if(st.find(x - 1) == st.end()) {
                int cnt = 1;
                int current = x;
                while(st.find(current + 1) != st.end()) {
                    current++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};