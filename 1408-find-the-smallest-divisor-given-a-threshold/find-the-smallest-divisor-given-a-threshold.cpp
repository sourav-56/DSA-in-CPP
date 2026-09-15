class Solution {
public:
  
  int sumbyd(vector<int> &nums,int div){
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum=sum+ceil((double)(nums[i])/(double)(div));
    }
    return sum;
  }  
  int smallestDivisor(vector<int> &nums, int limit) {
    int n=nums.size();
    if(n>limit) return -1;
    int low=1,high=*max_element(nums.begin(),nums.end());
    while(low<=high){
        int mid=(low+high)/2;
        if(sumbyd(nums,mid)<=limit){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
       
    }
};