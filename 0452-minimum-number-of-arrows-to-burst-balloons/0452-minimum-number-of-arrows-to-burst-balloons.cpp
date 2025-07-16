class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,end=nums[0][1];
        for(int i=1;i<nums.size();i++){
          if(end<nums[i][0]){
            ans++;
            end=nums[i][1];
          }
          else{
            end=min(end,nums[i][1]);
          }
        }
        return ans+1;
    }
};