class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0,ans=0;
        for(int i=0;i<n+k-2;i++){
          if(abs(nums[(i+1+n)%n]-nums[i%n])==1) cnt++;
          else cnt=0;
          if(cnt>=k-1){
            ans++;
          }
        }
        return ans;
    }
};