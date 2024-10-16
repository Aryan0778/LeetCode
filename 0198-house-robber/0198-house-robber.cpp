class Solution {
public:
    int maxm(vector<int>&nums,vector<int>&dp,int ind){
        if(ind<0) return 0;
        if(ind==0) return nums[0];
        if(dp[ind]!=-1) return dp[ind];
        int l=maxm(nums,dp,ind-1);
        int r=nums[ind]+maxm(nums,dp,ind-2);
        return dp[ind]=max(l,r);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int l=dp[i-1];
            int r=dp[i-2]+nums[i-1];
            dp[i]=max(l,r);
        }
        return dp[n];
    }
};