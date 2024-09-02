class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
    int n=nums.size(),a=0,maxScore=0,score=0;
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        while(mpp.find(nums[i])!=mpp.end()){
            mpp[nums[a]]--;
            score-=nums[a];
            if(mpp[nums[a]]==0) mpp.erase(nums[a]);
            a++;
        }
        mpp[nums[i]]++;
        score+=nums[i];
        maxScore=max(maxScore,score);
    }   
    return maxScore;
    }
};