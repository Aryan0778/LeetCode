class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
      multiset<int>st;
      long long j=m-1,maxm=LLONG_MIN,n=nums.size();
      for(;j<n;j++)st.insert(nums[j]);
      j=m-1;
      for(int i=0;i<n-m+1;i++){
        maxm=max({maxm,1LL*nums[i]**(st.begin()),1LL*nums[i]**st.rbegin()});
        // for(auto it:st) cout<<it<<" ";
        // cout<<endl;
        auto it=st.find(nums[j++]);
        st.erase(it);
      }
      cout<<maxm<<endl;
      return maxm;
    }
};