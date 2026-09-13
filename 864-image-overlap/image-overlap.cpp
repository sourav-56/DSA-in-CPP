class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n =img1.size();
        vector<pair<int,int>> v1,v2;        
        for (int i =0;i<n;i++){
            for (int j =0;j<n;j++) {
                if (img1[i][j] == 1) v1.push_back({i,j});
                if (img2[i][j] == 1) v2.push_back({i,j});
            }
        }      
        int ans =0;
        vector<vector<int>>count(2*n+1,vector<int>(2*n+1,0));       
        for (auto& p1 :v1){
            for (auto& p2 :v2){
                int dx = p1.first - p2.first + n;
                int dy = p1.second - p2.second + n;
                count[dx][dy]++;
                ans = max(ans,count[dx][dy]);
            }
        }       
        return ans;
    }
};