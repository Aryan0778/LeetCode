class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int n=nums.size(),count=0,a=0,len=INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]==0) count++;
        while(count>k){
            if(nums[a]==0) count--;
            a++;
        }
        len=max(len,i-a+1);
    }    
    return len==INT_MIN?0:len;
    }
};