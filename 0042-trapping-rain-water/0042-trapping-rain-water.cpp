class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0),suff(n,0);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(pre[i],suff[i])-nums[i];
        }
        return ans;
    }
};