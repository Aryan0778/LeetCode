class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    long long n=nums.size(),a=0,sum=0;
    long long count=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        while((sum*(i-a+1))>=k){
            sum-=nums[a++];
        }
        count+=(i-a+1);
        cout<<count<<" ";
    }
    return count;
    }
};