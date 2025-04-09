class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<P,vector<P>,greater<P>>minHeap;
    int m=nums1.size(),n=nums2.size();
    int sum=nums1[0]+nums2[0];
    minHeap.push({sum,{0,0}});
    vector<vector<int>>ans;
    set<pair<int,int>>visited;
    visited.insert({0,0});
    while(k-- && !minHeap.empty()){
        auto temp=minHeap.top();
        minHeap.pop();
        int i=temp.second.first;
        int j=temp.second.second;
        ans.push_back({nums1[i],nums2[j]});
        if(j+1<n && visited.find({i,j+1})==visited.end()){//Push (i,j+1) if possible
        visited.insert({i,j+1});
        minHeap.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        if(i+1<m && visited.find({i+1,j})==visited.end()){//Push (i+1,j) if possible
        visited.insert({i+1,j});
        minHeap.push({nums1[i+1]+nums2[j],{i+1,j}});
        }
    }
    return ans;    
    }
};