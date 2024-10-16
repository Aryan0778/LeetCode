class Solution {
public:
    int rob(vector<int>& nums) {
    int n=nums.size();
    vector<int>dp(n+1,-1);
    return findmax(nums,n-1,dp);   
    }
    int findmax(vector<int>& nums,int n,vector<int>& dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+findmax(nums,n-2,dp);
        int notpick=findmax(nums,n-1,dp);
        return dp[n]=max(pick,notpick);
    }
};