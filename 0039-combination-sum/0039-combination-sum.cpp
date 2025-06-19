class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ds;
        vector<vector<int>>ans;
        gen(0,target,nums,ds,ans);
        return ans;
    }
    void gen(int idx,int target,vector<int>& nums,vector<int>& ds,vector<vector<int>>&ans){
      if(idx>=nums.size()){
        if(target==0)ans.push_back(ds);
        return ;
      }
      if(target>=nums[idx]){
        ds.push_back(nums[idx]);
        gen(idx,target-nums[idx],nums,ds,ans);
        ds.pop_back();
      }
      gen(idx+1,target,nums,ds,ans);

    }
};