class Solution {
public:

    int countstu(vector<int> &nums,int pages){
        int student=1;
        long long pagestudent=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(pagestudent + nums[i]<=pages){
                pagestudent+=nums[i];
            }
            else{
                student+=1;
                pagestudent=nums[i];
            }
        }
        return student;
    }
    
    int splitArray(vector<int> &a, int k) {
        int low=*max_element(a.begin(),a.end());
        int high=accumulate(a.begin(),a.end(),0);
        int n=a.size();
        if(k>n) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            int students=countstu(a,mid);
            if(students>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
        
    
        
    }
};