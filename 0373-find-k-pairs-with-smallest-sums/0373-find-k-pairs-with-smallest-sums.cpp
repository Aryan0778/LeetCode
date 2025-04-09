class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int m=nums1.size(),n=nums2.size();
    priority_queue<pair<int,pair<int,int>>>maxHeap;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int sum=nums1[i]+nums2[j];
            if(maxHeap.size()<k){
                maxHeap.push({sum,{nums1[i],nums2[j]}});
            }
            else if(maxHeap.top().first>sum){
                maxHeap.pop();
                maxHeap.push({sum,{nums1[i],nums2[j]}});
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>>ans;
    while(maxHeap.size()>0){
      ans.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
      maxHeap.pop();
    }
    return ans;   
    }
};