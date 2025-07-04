class Solution {
public:
    vector<vector<int>>dp;
    int gen(int idx,int target,vector<int>&nums){
      if(idx>=nums.size()-1){
        if(target%nums[idx]==0) return target/nums[idx];
        return 1e5;
      }
      if(dp[idx][target]!=-1) return dp[idx][target];
      int pick=1e5,notpick;
      if(target>=nums[idx]) pick=1+gen(idx,target-nums[idx],nums);
      notpick=gen(idx+1,target,nums);
      return dp[idx][target]=min(pick,notpick);
    }

    int coinChange(vector<int>& nums, int target) {
        dp.resize(nums.size()+1);
        for(int i=0;i<=nums.size();i++){
          dp[i].resize(target+1,-1);
        }
        int ans=gen(0,target,nums);
        return ans==1e5?-1:ans;
    }


};