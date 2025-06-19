class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),a=0,count=0,maxm=0;
        for(int i=0;i<n;i++){
          if(nums[i]==0) count++;
          while(count>k){
            if(nums[a]==0) count--;
            a++;
          }
          maxm=max(maxm,i-a+1);
        }
        return maxm;
    }
};