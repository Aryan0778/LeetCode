class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size(),ans=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                int mid=st.top();
                st.pop();
                if(st.empty()) break;
                int left=st.top();
                int minHeight=min(nums[i]-nums[mid],nums[left]-nums[mid]);
                int width=i-left-1;
                ans+=(minHeight*width);
            }
            st.push(i);
            cout<<ans<<endl;
        }
        return ans;
    }
};