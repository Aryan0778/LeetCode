class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int a=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int b=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
    cout<<a<<" "<<b<<endl;
    if(a<=b) return {a,b}; 
    return {-1,-1}; 
    }
};