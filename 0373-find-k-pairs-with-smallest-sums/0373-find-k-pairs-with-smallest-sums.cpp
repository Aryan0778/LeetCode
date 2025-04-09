class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int m=nums1.size(),n=nums2.size();
    priority_queue<P>pq;
    vector<vector<int>>ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pq.size()<k){
                pq.push({nums1[i]+nums2[j],{i,j}});
            }
            else if(pq.top().first>nums1[i]+nums2[j]){
                pq.pop();
                pq.push({nums1[i]+nums2[j],{i,j}});   
            }
            else{
                break;
            }
        }
    }
    while(pq.size()>0){
        ans.push_back({nums1[pq.top().second.first],nums2[pq.top().second.second]});
        pq.pop();
    }
    return ans;
    }
};