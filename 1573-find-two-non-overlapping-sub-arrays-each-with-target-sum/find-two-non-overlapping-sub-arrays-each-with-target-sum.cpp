#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n =arr.size();
        vector<int>min_len(n,1e9);
        int left = 0,sum =0;
        int best = 1e9;
        int ans = 1e9;      
        for(int right =0;right<n; ++right){
            sum += arr[right];
            while(sum>target &&left<=right){
                sum -=arr[left++];
            }        
            if (sum == target){
                int len =right -left+1;
                if (left>0 && min_len[left -1]!=1e9){
                    ans = min(ans,len +min_len[left-1]);
                }
                best =min(best,len);
            }
            min_len[right]=best;
        }    
        return ans == 1e9 ? -1:ans;
    }
};