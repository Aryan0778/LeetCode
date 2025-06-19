class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      vector<int>ds;
      vector<vector<int>>ans;
      gen(0,target,nums,ds,ans);
      return ans;
    }

    void gen(int ind,int target,vector<int>nums,vector<int>ds,vector<vector<int>>&ans){
      if(ind>=nums.size()){
        if(target==0) ans.push_back(ds);
        return;
      }
      if(target==0){
        ans.push_back(ds);
        return;
      }

      for(int i=ind;i<nums.size();i++){
        if(i>ind && nums[i]==nums[i-1]) continue;
        if(nums[i]>target) break;
        ds.push_back(nums[i]);
        gen(i+1,target-nums[i],nums,ds,ans);
        ds.pop_back();
      }
    }
};