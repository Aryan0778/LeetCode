class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
    int n=nums.size();
    int i,maxm=0,j=1;
    vector<int>ans;
    for(i=1;i<k;i++){
      if(nums[i-1]+1==nums[i]) maxm++;
    }
    while(i<n){
      if(maxm==k-1){
        ans.push_back(nums[i-1]);
      }
      else{
        ans.push_back(-1);
      }
      if(nums[i-1]+1==nums[i]) maxm++;
      if(nums[j-1]+1==nums[j]) maxm--;
      i++,j++;
    }
    if(maxm==k-1)ans.push_back(nums[n-1]);
    else ans.push_back(-1); 
    return ans;
    }
};