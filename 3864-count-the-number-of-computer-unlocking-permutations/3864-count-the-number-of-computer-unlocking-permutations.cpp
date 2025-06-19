class Solution {
public:
    int MOD = (int)1e9+7;
    int countPermutations(vector<int>& nums) {
      int n=nums.size();
      int minm=*min_element(nums.begin(),nums.end());
      int count=0;
      if(minm!=nums[0]) return 0;
      for(int i=0;i<n;i++){
        if(nums[i]==minm) count++;
        if(count>1) return 0;
      }
      int ans=1;
      for(int i=1;i<n;i++){
        ans = (1LL * ans * i) % MOD;

      }
      return ans;
    }
};