class Solution {
public:
    int minm(vector<int>& nums){
        int n=nums.size(),mini=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>0) sum=0;
            mini=min(mini,sum);
        }
        return mini;
    }
    int maxm(vector<int>nums){
         int n=nums.size(),maxii=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0) sum=0;
            maxii=max(maxii,sum);
        }
        return maxii;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        int mini=minm(nums);
        int maxii=maxm(nums);
        bool flag=true;
        int maxu=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]>0) flag=false;
            maxu=max(maxu,nums[i]);
        }
        if(flag) return maxu;
        return max(sum-mini,maxii);
    }
};