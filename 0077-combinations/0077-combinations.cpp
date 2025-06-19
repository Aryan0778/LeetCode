class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>>ans;
      vector<int>ds;
      gen(1,n,k,ans,ds);
      return ans;
    }

    void gen(int curr,int n,int k,vector<vector<int>>&ans,vector<int>ds){
      if(ds.size()==k){
        ans.push_back(ds);
        return;
      }      
      for(int i=curr;i<=n;i++){
        ds.push_back(i);
        gen(i+1,n,k,ans,ds);
        ds.pop_back();
      }
    }
};