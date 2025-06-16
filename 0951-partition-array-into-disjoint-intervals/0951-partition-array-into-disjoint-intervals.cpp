class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
    int n=nums.size();
    int lmax=nums[0],maxm=nums[0],idx=0;
    for(int i=0;i<n;i++){
      maxm=max(maxm,nums[i]);
      if(lmax>nums[i]){
        lmax=maxm;
        idx=i;
      }
    }
    return idx+1;
    }
};