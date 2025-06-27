class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
          if(st.empty()){
            st.push(nums[i]);
             continue;
          }
          if(st.top()<=nums[i]) st.push(nums[i]);
        }
        return st.size();
    }
};