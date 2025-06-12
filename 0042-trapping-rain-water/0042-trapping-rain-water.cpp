class Solution {
public:
    int trap(vector<int>& nums) {
        int n =nums.size();
        int lmax=-1,rmax=-1,l=0,r=n-1,ans=0;
        while(l<r){
            lmax=max(lmax,nums[l]);
            rmax=max(rmax,nums[r]);
            if(lmax>rmax) ans+=(rmax-nums[r--]);
            else ans+=(lmax-nums[l++]);
        }
        return ans;
    }
};